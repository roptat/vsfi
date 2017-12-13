module L = Log.Make(struct let name = "env" end)

module Mem(D: Numericaldomain.T) =
  struct
    module IntMap = (Elf_info.IntMap)

    type content =
    | Top
    | Reference of int
    | Value of D.t

    let string_of_content c =
      match c with
      | Top -> "T"
      | Reference i -> (Printf.sprintf "<%d>" i)
      | Value v -> (Printf.sprintf "%s(%d)" (D.to_string v) (D.get_size v))

    let to_string m = IntMap.fold (fun key value acc -> Printf.sprintf "%s\n|%s|" acc (string_of_content value)) m "Stack: "

    type t = content IntMap.t

    let top: t = IntMap.empty

    let is_top m = IntMap.is_empty m

    let framesize = 2000
    let archsize = 4294967296
    let frame_offset_max = archsize
    let frame_offset_min = archsize - framesize
    let datasize  = 16777216

    let get_content_at (frame: t) (offset: int): content =
      try IntMap.find offset frame with
      | Not_found -> Top
    
    let read (frame: t) (offset: int) (size: int): D.t =
      L.debug (fun p -> p "Read at %d:%d" offset (offset + (size/8) - 1));
      match get_content_at frame offset with
      | Value v -> if (D.get_size v) = size then v else (D.top size)
      | _ -> D.top size

    let rec clear (frame: t) (offset: int) (size: int): t =
      if size <= 0 then frame
      else match get_content_at frame offset with
           | Top -> clear frame (offset+1) (size-1)
           | Reference off -> clear (IntMap.add offset Top frame) off (size + offset - off)
           | Value v -> clear (IntMap.add offset Top frame) (offset+1) (max (((D.get_size v)/8) - 1) (size-1))

    let rec update_aux (frame: t) (offset: int) (size: int) (value: content): t =
      if size <= 0 then frame
      else update_aux (IntMap.add offset value frame) (offset+1) (size-1) value

    let update (frame: t) (offset: int) (value: D.t): t =
      L.debug (fun p -> p "Update: put %s at %d" (D.to_string value) offset);
      L.debug (fun p -> p "%s" (to_string (clear frame offset ((D.get_size value)/8))));
      update_aux (IntMap.add offset (Value value) (clear frame offset ((D.get_size value)/8)))
                 (offset+1) (((D.get_size value)/8) - 1) (Reference offset)

    let is_subset m1 m2 =
      IntMap.fold (fun off content acc ->
                    if acc
                    then match get_content_at m1 off with
                         | Top -> content = Top
                         | Reference offset -> content = Reference offset
                         | Value v -> match content with
                                      | Value v' -> D.is_subset v v'
                                      | _ -> false
                    else false)
                  m2 true

    let rec join_aux m1 m2 off dfun =
      if off > framesize then m1
      else
        match get_content_at m1 off with
        | Top -> join_aux m1 (clear m2 off 1) (off+1) dfun
        | Reference _ -> failwith "improper memory layout!"
        | Value v -> match get_content_at m2 off with
                     | Top -> join_aux (clear m1 off 1) m2 (off + 1) dfun
                     | Reference _ -> failwith "Improper memory layout!"
                     | Value v' -> if (D.get_size v) = (D.get_size v') then
                                   join_aux (IntMap.add off (Value (dfun v v')) m1)
                                            (IntMap.add off (Value (dfun v v')) m2)
                                            (off + D.get_size v) dfun
                                   else join_aux (clear m1 off 1)
                                                 (clear m2 off 1)
                                                 (off + 1) dfun

    let join m1 m2 =
      join_aux m1 m2 0 D.join

    let widen m1 m2 =
      join_aux m1 m2 0 D.widen

    let meet m1 m2 = m1

    let forget m = top

    let callclean m cesp =
      match cesp with
      | Asm.Loc (Asm.Frame, off) ->
        begin
          let (min, v) = IntMap.min_binding m in
          clear m min (off - min)
        end
      | _ -> failwith "esp is not in the stack"
  end

module Env(D: Numericaldomain.T) =
  struct
    module IntMap = Map.Make(Register)
    
    type t = D.t IntMap.t

    let top = IntMap.empty

    let is_top = IntMap.is_empty

    let to_string e =
      IntMap.fold (fun key node acc -> Printf.sprintf "%s; %s = %s" acc (Register.name key) (D.to_string node)) e ""

    let get_reg_by_name e name =
      IntMap.fold (fun key node acc -> if (Register.name key) = name then Some key else acc) e None

    let forget e = top

    let forget_reg e r =
      match r with
      | Asm.T r -> IntMap.remove r e
      | Asm.P (r, a, b) -> failwith "Unimplemented forget_reg for partial register"

    let get_content_of (env: t) (reg: Register.t) =
      try IntMap.find reg env with
      | Not_found -> D.top (Register.size reg)

    let get_sub_content_of (env: t) (reg: Register.t) (start: int) (finish: int) =
      if finish < start then failwith "finish < start"
      else
        try
          let r = IntMap.find reg env in
          D.get_sub r start finish
        with
        | Not_found -> D.top (finish - start + 1)

    let update_content_of (env: t) (reg: Register.t) (v: D.t) =
      IntMap.add reg v env

    let update_content_of_sub (env: t) (reg: Register.t) (start: int) (finish: int) (v: D.t) =
      IntMap.add reg (D.update_sub (get_content_of env reg) start finish v) env

    let is_subset e1 e2 =
      IntMap.fold (fun reg content acc ->
                    if acc
                    then D.is_subset (get_content_of e1 reg) content
                    else false)
                  e2 true

    let join e1 e2 =
      L.debug (fun m -> m "join memory");
      IntMap.fold (fun reg content acc ->
                    IntMap.add reg (D.join content (get_content_of e2 reg)) acc)
                  e1 IntMap.empty

    let widen e1 e2 =
      L.debug (fun m -> m "widen memory");
      IntMap.fold (fun reg content acc ->
                    IntMap.add reg (D.widen content (get_content_of e2 reg)) acc)
                  e1 IntMap.empty

    let meet e1 e2 =
      IntMap.fold (fun reg content acc ->
                    IntMap.add reg (D.meet content (get_content_of e1 reg)) acc)
        (IntMap.fold (fun reg content acc ->
                    IntMap.add reg (D.meet content (get_content_of e2 reg)) acc)
                    e1 IntMap.empty) IntMap.empty
  end

module Make(D: Numericaldomain.T): Envdomain.T =
  struct
    module IntMap = (Elf_info.IntMap)
    module Memory = Mem(D)
    module Environ = Env(D)

    type t = (Environ.t * Memory.t)

    let top = (Environ.top, Memory.top)

    let get_size v = 0

    let forget (v: t): t = top

    let is_top v = let (e, m) = v in Environ.is_top e && Memory.is_top m

    let is_subset e1 e2 =
      let (e1, m1) = e1 in
      let (e2, m2) = e2 in
      Environ.is_subset e1 e2 && Memory.is_subset m1 m2

    let to_string e = 
      let (e, m) = e in
      (Printf.sprintf "\nenvironment: %s \nframe: %s" (Environ.to_string e) (Memory.to_string m))

    let join e1 e2 =
      let (e1, m1) = e1 in
      let (e2, m2) = e2 in
      (Environ.join e1 e2, Memory.join m1 m2)

    let widen e1 e2 =
      let (e1, m1) = e1 in
      let (e2, m2) = e2 in
      (Environ.widen e1 e2, Memory.widen m1 m2)

    let meet e1 e2 =
      let (e1, m1) = e1 in
      let (e2, m2) = e2 in
      (Environ.meet e1 e2, Memory.meet m1 m2)

    let rec eval s exp =
      let (e, m) = s in
      match exp with
      | Asm.Const v -> D.of_word v
      | Asm.Return  -> D.of_concrete (Asm.Loc (Asm.Ret, 0)) 32
      | Asm.Reloc s -> D.of_reloc s
      | Asm.BinOp (op, e1, e2) -> D.binop op (eval s e1) (eval s e2)
      | Asm.UnOp (op, e1) -> D.unop op (eval s e1)
      | Asm.TernOp (be, e1, e2) ->
        begin
          let iftrue = eval s e1 in
          let iffalse = eval s e2 in
          let boolean = my_beval s be in
          if D.is_subset (D.of_concrete (Asm.Num 1) 1) boolean
          then if D.is_subset (D.of_concrete (Asm.Num 0) 1) boolean
            then D.join iftrue iffalse
            else iftrue
          else if D.is_subset (D.of_concrete (Asm.Num 0) 1) boolean
            then iffalse
            else failwith "Error evaluating binary expression"
        end
      | Asm.Lval lval ->
        match lval with
        | Asm.M (exp, sz) ->
          (let loc = eval s exp in
           try
             match (D.get_singleton loc) with
             | Asm.Num n -> D.top sz
             | Asm.Loc (l, n) ->
               if l = Asm.Frame then Memory.read m n sz else D.top sz
           with
           | _ -> D.top sz)
        | Asm.V r ->
          match r with
          | Asm.T r -> Environ.get_content_of e r
          | Asm.P (r, a, b) -> Environ.get_sub_content_of e r a b
    and my_beval s bexp =
      let (e, m) = s in
      match bexp with
      | Asm.BUnOp (op, bexp) -> D.bunop op (my_beval s bexp)
      | Asm.Cmp (cmp, e1, e2) -> D.cmp cmp (eval s e1) (eval s e2)
      | Asm.BBinOp (op, b1, b2) -> D.bbinop op (my_beval s b1) (my_beval s b2)
      | Asm.BConst b -> if b then (D.of_concrete (Asm.Num 1) 1) else (D.of_concrete (Asm.Num 0) 1)

    let beval s bexp =
      let boolean = (eval s (Asm.TernOp (bexp, (Asm.Const (Data.Word.of_int (Z.of_int 1) 1)), (Asm.Const (Data.Word.of_int (Z.of_int 0) 1))))) in
      let one = D.of_concrete (Asm.Num 1) 1 in
      let zero = D.of_concrete (Asm.Num 0) 1 in
      if D.is_subset one boolean
      then if D.is_subset zero boolean
        then Vector.TOP
        else Vector.ONE
      else if D.is_subset zero boolean
        then Vector.ZERO
        else failwith "Error evaluating binary expression"
      

    let assign s exp reg =
      let (e, m) = s in
      let v = (eval s exp) in
      match reg with
      | Asm.T r -> (Environ.update_content_of e r v, m)
      | Asm.P (r, a, b) -> (Environ.update_content_of_sub e r a b v, m)

    let load s exp reg =
      match reg with
      | Asm.T r ->
        let sz = (Register.size r) in
        assign s (Asm.Lval (Asm.M (exp, sz))) reg
      | Asm.P (r, a, b) -> failwith "TODO: Not implemented yet"

    let store s exp sz dst =
      L.debug (fun m -> m "store");
      let (e, m) = s in
      let v = (eval s exp) in
      let dst = (eval s dst) in
      try
        (match (D.get_singleton dst) with
         | Asm.Loc (Asm.Frame, off) -> if (off + (sz/8)) <= Memory.frame_offset_max && off > Memory.frame_offset_min
                                       then (e, Memory.update m off v)
                                       else failwith (Printf.sprintf "Write to %d(%d) may be outside of allowed bounds." off (sz/8))
         | _ -> failwith "Singleton, not in Frame")
      with
      | _ -> if D.is_between dst sz
                  (D.of_concrete (Asm.Loc (Asm.Data, 0)) 32)
                  (D.of_concrete (Asm.Loc (Asm.Data, Memory.datasize)) 32)
             then s
             else failwith (Printf.sprintf "Write to %s of size %d may be outside of allowed bounds."  (D.to_string dst) (sz/8))

    (** FIXME: actually do something meaningfull *)
    let callclean v =
      let (e, m) = v in
      let esp = Environ.get_reg_by_name e "esp" in
      match esp with
      | Some esp -> 
        let cesp = Environ.get_content_of e esp in
        let cesp = D.binop Asm.Add cesp (D.of_word (Data.Word.of_int (Z.of_int 4) 32)) in
        let m = Memory.callclean m (D.get_singleton cesp) in
        let e = Environ.update_content_of Environ.top esp cesp in
        (e, m)
      | None -> failwith "cannot update after function call"

    let forget_reg s r =
      let (e, m) = s in
      (Environ.forget_reg e r, m)

    let bit32_int i =
      Data.Word.of_int (Z.of_int i) 32

    let start_state esp =
      let start_frame = Asm.Reloc (Asm.Block (Asm.Frame, (bit32_int 0))) in
      let start_frame = Asm.BinOp (Asm.Sub, start_frame, Asm.Const (bit32_int 4)) in
      let env = top in
      let env = assign top start_frame esp in
      store env Asm.Return 32 start_frame

    let concrete_eval s e =
      let abs = eval s e in
      D.concretization abs

    end
