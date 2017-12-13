module L = Log.Make(struct let name = "interpreter" end)

module IntMap = Decoder.IntMap
type prog = Decoder.prog

type offset  =
| Stmt of int
| Cond of int * bool * offset

type addr = int * offset
type pool = addr list

let rec string_of_offset o =
match o with
| Stmt i -> Printf.sprintf "%d" i
| Cond (i, b, o) -> Printf.sprintf "%d(%s:%s)" i (if b then "T" else "F") (string_of_offset o)

let string_of_addr a =
let (a, o) = a in
Printf.sprintf "%x:%s" a (string_of_offset o)

module Lexico =
struct
  type t = addr
  let compare: t -> t -> int = Pervasives.compare
end

module LexicoMap =
struct
  module LexMap = Map.Make(Lexico)
  include LexMap
  exception Found

  let search p m =
      let (k,e) = choose m in
      if p k e
      then (k,e)
      else
        let res = ref (k,e) in
        try
          fold (fun k e () -> if p k e then (res := (k,e) ; raise Found) else ()) m () ; raise Not_found
        with Found -> !res
end

module Make(Env: Envdomain.T) =
  struct
    type node = { addr: addr ; state: Env.t }
    type result = Env.t LexicoMap.t

    let rec stmt_at_aux stmts off =
      match off with
      | Stmt i ->
        begin
          if i = 0 && stmts = [] then
            Asm.Nop
          else
            List.nth stmts i
        end
      | Cond (i, b, o) ->
        match List.nth stmts i with
        | Asm.If (bexp, t, f) ->
          stmt_at_aux (if b then t else f) o
        | _ -> failwith "Cond but not cond"

    let stmt_at p addr =
      let (addr, off) = addr in
      let lst = IntMap.find addr p in
      stmt_at_aux lst off

    let rec next_addr p addr =
      let (addr, off) = addr in
      let (maddr, moff) = IntMap.max_binding p in
      if maddr < addr then
        failwith (Printf.sprintf "%d is bigger than the maximum decoded address" addr)
      else
        let new_off = next_off off in
        try let stmt = stmt_at p (addr, new_off) in
            (addr, new_off)
        with
        | _ -> match off_up off with
               | None -> next_addr p (addr+1, Stmt (-1))
               | Some up -> next_addr p (addr, up)
    and off_up off =
      match off with
      | Stmt i -> None
      | Cond (i, b, o) ->
        let up = off_up o in
        if up = None
        then Some (Stmt i)
        else up
    and next_off off =
      match off with
      | Stmt off -> Stmt (off+1)
      | Cond (o1, b, o2) -> 
        Cond (o1, b, (next_off o2))

    let rec next_addr_cond b off =
      match off with
      | Stmt i -> Cond (i, b, (Stmt 0))
      | Cond (i, c, o) -> Cond (i, c, next_addr_cond b o)

    (** Analyze a node, return possible states after execution of this node. *)
    let advance (addr: addr) (s: Env.t) (p: prog): result =
      try
        let stmt = stmt_at p addr in
        L.debug (fun s -> s "%s --- %s" (string_of_addr addr) (Asm.string_of_stmt stmt true));
        match stmt with
        | Asm.Set (Asm.V r, e) ->
          begin
              LexicoMap.singleton (next_addr p addr) (Env.assign s e r)
          end
        | Asm.Set (Asm.M (m, sz), e) -> LexicoMap.singleton (next_addr p addr) (Env.store s e sz m)
        | Asm.If (b, t, f) ->
          begin
            let (a, o) = addr in
            match Env.beval s b with
            | Vector.ZERO -> LexicoMap.singleton (a, next_addr_cond false o) s
            | Vector.ONE -> LexicoMap.singleton (a, next_addr_cond true o) s
            | Vector.TOP -> LexicoMap.add (a, next_addr_cond true o) s
                            (LexicoMap.singleton (a, next_addr_cond false o) s)
          end
        | Asm.Jmp t ->
          begin
            match t with
            | Asm.A t -> LexicoMap.singleton ((Z.to_int (Data.Address.to_int t)), Stmt 0) s
            | Asm.R t ->
              let t = Env.concrete_eval s t in
              List.fold_left (fun acc c ->
                               match c with
                                 | Asm.Num n -> failwith (Printf.sprintf "Unsupported jump to numerical location: %s" (Asm.string_of_concrete c)) (*LexicoMap.add (n, Stmt 0) s acc*)
                                 | Asm.Loc (Asm.Ret, 0) ->
                                   begin
                                     (* TODO: check registers *)
                                     LexicoMap.empty
                                   end
                                 | Asm.Loc (_, _) -> failwith (Printf.sprintf "Unsupported jump to symbolic location: %s" (Asm.string_of_concrete c))) LexicoMap.empty t
          end
        | Asm.Call t -> LexicoMap.singleton (next_addr p addr) (Env.callclean s)
        | Asm.Directive (Asm.Forget (Asm.V r)) -> LexicoMap.singleton (next_addr p addr) (Env.forget_reg s r)
        | Asm.Directive (Asm.Remove r) -> LexicoMap.singleton (next_addr p addr) (Env.forget_reg s (Asm.T r))
        | Asm.Directive _ -> failwith "Unimplemented advance on directive"
        | Asm.Assert (_, _)| Asm.Nop -> LexicoMap.singleton (next_addr p addr) s
      with
      | Failure s -> failwith (Printf.sprintf "%s | While advancing on %s" s (string_of_addr addr))
      | _ -> failwith (Printf.sprintf "Uncaught exception at %s" (string_of_addr addr))

    let print_pool pool txt =
      L.debug (fun m -> m "%s: %s" txt (List.fold_left (fun acc value -> Printf.sprintf "%s, %s" acc (string_of_addr value)) "" pool))

    let print_result_keys res txt =
      L.debug (fun m -> m "%s: %s" txt (LexicoMap.fold (fun key value acc -> Printf.sprintf "%s, %s" acc (string_of_addr key)) res ""))

    (* r1: old results, r2: new results (excluding already known ones) *)
    let join_with_pool (oldpool: pool) (r1: result) (r2: result): (result * addr list) =
      let newpool = LexicoMap.fold (fun key node acc -> key :: acc) r2 oldpool in
      let (r, p) = LexicoMap.fold (fun key node acc ->
                       let (res, pool) = acc in
                       try let node' = LexicoMap.find key res in
                           LexicoMap.add key (Env.widen node node') res,
                             (if Env.is_subset node node' then pool else key :: pool)
                       with
                       | Not_found ->
                         (LexicoMap.add key node res, key :: pool)) r2 (r1, oldpool) in
      (r, List.sort_uniq Pervasives.compare p)

    let rec iter p pool result =
      match pool with
      | [] -> result
      | addr :: pool ->
        let state = LexicoMap.find addr result in
        L.debug (fun m -> m "%s" (Env.to_string state));
        let node_res = advance addr state p in
        L.debug (fun m -> m "Possible updates number: %d" (LexicoMap.cardinal node_res));
        let (result, pool) = join_with_pool pool result node_res in
        print_pool pool "New pool";
        L.debug (fun p -> p "-------");
        iter p pool result

    let do_it p start esp =
      let res = LexicoMap.singleton start (Env.start_state esp) in
      iter p [start] res
  end
