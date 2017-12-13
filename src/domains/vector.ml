module L = Log.Make(struct let name = "vector" end)

open Data

(** data type: int with infty *)
type bit =
  | ZERO
  | ONE
  | TOP

let string_of_bit (b: bit) =
  match b with
  | ZERO -> "0"
  | ONE -> "1"
  | TOP -> "T"

type vector =
  | Vect of bit list
  | Bot of int

module Make =
  (struct
    type t = (vector)

    let rec top_aux size =
      match size with
      | 0 -> []
      | _ -> TOP :: (top_aux (size - 1))

    let top size =
      Vect (top_aux size)

    let bot size = Bot size

    let get_size v =
      match v with
      | Bot i -> i
      | Vect b -> List.length b

    let is_bot v =
      v = bot (get_size v)

    let is_top v =
      v = top (get_size v)

    let forget v = top (get_size v)

    let rec is_subset_aux v1 v2 =
      match v1, v2 with
      | [], [] -> true
      | [], _ -> failwith "Vector size do not match"
      | _, [] -> failwith "Vector size do not match"
      | a1::v1, a2::v2 -> (a2 = TOP || a1 = a2) && is_subset_aux v1 v2

    let is_subset v1 v2 =
      match v1, v2 with
      | Bot _, _ -> true
      | _, Bot _ -> false
      | Vect v1, Vect v2 -> is_subset_aux v1 v2

    let rec to_string v =
      match v with
      | Bot _ -> "Ø"
      | Vect [] -> "0b"
      | Vect (a :: v) ->
        Printf.sprintf "%s%s" (to_string (Vect v)) (string_of_bit a)

    let rec join_aux v1 v2 =
      match v1, v2 with
      | [], []  -> []
      | [], _ -> failwith "Vector size do not match"
      | _, [] -> failwith "Vector size do not match"
      | a1::v1, a2::v2 -> (if a1 = a2 then a1 else TOP) :: join_aux v1 v2

    let join v1 v2 =
      match v1, v2 with
      | _, Bot _ -> v1
      | Bot _, _ -> v2
      | Vect v1, Vect v2 -> Vect (join_aux v1 v2)

    let widen v1 v2 =
      if is_subset v2 v1
      then v1
      else top (get_size v2)

    let rec meet_aux v1 v2 =
      match v1, v2 with
      | [], []  -> Some []
      | [], _ -> failwith "Vector size do not match"
      | _, [] -> failwith "Vector size do not match"
      | a1::v1, a2::v2 ->
        match meet_aux v1 v2 with
        | None -> None
        | Some v ->
          match a1, a2 with
          | TOP, _ -> Some (a2 :: v)
          | _, TOP -> Some (a1 :: v)
          | _, _ -> if a1 = a2 then Some (a1 :: v)
                    else None

    let meet v1 v2 =
      match v1, v2 with
      | Bot _, _ -> v1
      | _, Bot _ -> v2
      | Vect v1, Vect v2 ->
        match meet_aux v1 v2 with
        | None -> bot 0
        | Some v -> Vect v

    let rec of_int v sz =
      if sz = 1 then
        [if v mod 2 = 0 then ZERO else ONE]
      else
        (if v mod 2 = 0 then ZERO else ONE) :: (of_int (v/2) (sz-1))

    let of_word w =
      Vect (of_int (Z.to_int (Word.to_int w)) (Word.size w))

    let of_reloc s =
      match s with
      | Asm.Rentry (s, o) -> bot (Elf_info.Reloc.size_of_rtype s.Elf_info.Reloc.r_type)
      | Asm.Block (b, o) -> bot 32

    let of_concrete c sz =
      match c with
      | Asm.Loc (_, _) -> bot sz
      | Asm.Num w -> Vect (of_int w sz)

    let rec get_max v =
      match v with
      | Bot _ -> failwith "No value"
      | Vect v ->
        match v with
        | [] -> 0
        | b :: v ->
          (match b with
           | ZERO -> 0
           | _ -> 1) + 2 * (get_max (Vect v))

    let rec get_min v =
      match v with
      | Bot _ -> failwith "No value"
      | Vect v ->
        match v with
        | [] -> 0
        | b :: v ->
          (match b with
           | ONE -> 1
           | _ -> 0) + 2 * (get_min (Vect v))

    let is_between v sz inf sup =
      L.debug (fun m -> m "%d <= %d && %d <= %d" (get_min inf)
                 (get_min v) ((get_max v) + (sz/8)) (get_max sup));
      (get_min inf) <= (get_min v) && ((get_max v) + (sz/8)) <= (get_max sup)

    let rec get_singleton_aux v =
      match v with
      | Bot _ -> failwith "empty set"
      | Vect v ->
        match v with
        | [] -> failwith "empty set"
        | [ZERO] -> 0
        | [ONE] -> 1
        | [TOP] -> failwith "not a singleton"
        | b :: v ->
          (match b with
          | ZERO -> 0
          | ONE -> 1
          | TOP -> failwith "not a singleton") + 2 * (get_singleton_aux (Vect v))

    let get_singleton v =
      Asm.Num (get_singleton_aux v)

    let rec concretization_aux v =
      match v with
      | Bot _ -> []
      | Vect v ->
        match v with
        | [] -> []
        | [ZERO] -> [0]
        | [ONE] -> [1]
        | [TOP] -> [0; 1]
        | b :: v ->
          match b with
          | ZERO -> List.map (fun i -> 2 * i) (concretization_aux (Vect v))
          | ONE -> List.map (fun i -> 2 * i + 1) (concretization_aux (Vect v))
          | TOP -> List.map (fun i -> 2 * i) (concretization_aux (Vect v)) @ List.map (fun i -> 2 * i + 1) (concretization_aux (Vect v))

    let concretization v =
      List.map (fun i -> Asm.Num i) (concretization_aux v)

    let rec add_aux v1 v2 car = 
      match v1, v2 with
      | [], [] -> []
      | b1::v1, b2::v2 ->
        begin
        let res = add_aux v1 v2 in
        match car, b1, b2 with
        | ZERO, ZERO, ZERO -> ZERO :: (res ZERO)
        | ZERO, ZERO, ONE -> ONE :: (res ZERO)
        | ZERO, ZERO, TOP -> TOP :: (res ZERO)
        | ZERO, ONE, ZERO -> ONE :: (res ZERO)
        | ZERO, ONE, ONE -> ZERO :: (res ONE)
        | ZERO, ONE, TOP -> TOP :: (res TOP)
        | ZERO, TOP, ZERO -> TOP :: (res ZERO)
        | ZERO, TOP, ONE -> TOP :: (res TOP)
        | ZERO, TOP, TOP -> TOP :: (res TOP)
        | ONE, ZERO, ZERO -> ONE :: (res ZERO)
        | ONE, ZERO, ONE -> ZERO :: (res ONE)
        | ONE, ZERO, TOP -> TOP :: (res TOP)
        | ONE, ONE, ZERO -> ZERO :: (res ONE)
        | ONE, ONE, ONE -> ONE :: (res ONE)
        | ONE, ONE, TOP -> TOP :: (res ONE)
        | ONE, TOP, ZERO -> TOP :: (res TOP)
        | ONE, TOP, ONE -> TOP :: (res ONE)
        | ONE, TOP, TOP -> TOP :: (res TOP)
        | TOP, ZERO, ZERO -> TOP :: (res ZERO)
        | TOP, ZERO, ONE -> TOP :: (res TOP)
        | TOP, ZERO, TOP -> TOP :: (res TOP)
        | TOP, ONE, ZERO -> TOP :: (res TOP)
        | TOP, ONE, ONE -> TOP :: (res ONE)
        | TOP, ONE, TOP -> TOP :: (res TOP)
        | TOP, TOP, ZERO -> TOP :: (res TOP)
        | TOP, TOP, ONE -> TOP :: (res TOP)
        | TOP, TOP, TOP -> TOP :: (res TOP)
        end
      | (_, _) -> failwith "Impossible: vectors don't have the same size"

    let add v1 v2 = 
      add_aux v1 v2 ZERO

    let rec neg v =
      match v with
      | [] -> []
      | (b::v) ->
        (match b with | ZERO -> ONE | ONE -> ZERO | TOP -> TOP) :: (neg v)

    let sub v1 v2 = 
      let sz = (List.length v1) in
      add (add (neg v2) (of_int 1 sz)) v1

    let rec signext_aux b sz =
      match sz with
      | 0 -> []
      | _ -> b :: (signext_aux b (sz-1))

    let rec signext v sz =
      match v with
      | [] -> failwith "Empty vector has no sign"
      | [b] -> signext_aux b sz
      | b :: v -> b :: (signext v (sz - 1))

    let rec zeroext v sz =
      match sz with
      | 0 -> []
      | _ -> match v with
             | [] -> ZERO :: (zeroext v (sz - 1))
             | b :: v -> b :: (zeroext v (sz - 1))

    let rec shr_aux v off =
      match off with
      | 0 -> v
      | _ -> match v with
             | [] -> []
             | b :: v -> shr_aux v (off - 1)

    let shr v off sz =
      (zeroext (shr_aux v off) sz)

    let rec shl_aux v off =
      match off with
      | 0 -> v
      | _ -> shl_aux (ZERO :: v) (off - 1)

    let shl v off sz =
      (zeroext (shl_aux v off) sz)

    let rec eq_aux v1 v2 =
      match v1, v2 with
      | [], [] -> [ONE]
      | b1 :: v1, b2 :: v2 ->
        begin
          match b1, b2 with
          | ZERO, ZERO -> (eq_aux v1 v2)
          | ONE, ONE -> (eq_aux v1 v2)
          | ZERO, ONE -> [ZERO]
          | ONE, ZERO -> [ZERO]
          | _, _ -> [TOP]
        end
      | _, _ -> failwith "Comparison between vectors of different sizes"

    let eq v1 v2 =
      match v1, v2 with
      | Vect v1, Vect v2 -> Vect (eq_aux v1 v2)
      | _, _ -> failwith "Comparison with bottom"

    let rec v_and v1 v2 =
      match v1, v2 with
      | [], [] -> []
      | b1 :: v1, b2 :: v2 ->
        (match b1, b2 with
          | ZERO, _ -> ZERO
          | _, ZERO -> ZERO
          | ONE, b2 -> b2
          | b1, ONE -> b1
          | TOP, TOP -> TOP) :: (v_and v1 v2)
      | _, _ -> failwith "Sizes do not match in v_and"

    let rec v_xor v1 v2 =
      match v1, v2 with
      | [], [] -> []
      | b1 :: v1, b2 :: v2 ->
        (match b1, b2 with
          | ZERO, ZERO -> ZERO
          | ZERO, ONE -> ONE
          | ZERO, TOP -> TOP
          | ONE, ZERO -> ONE
          | ONE, ONE -> ZERO
          | ONE, TOP -> TOP
          | TOP, _ -> TOP) :: (v_xor v1 v2)
      | _, _ -> failwith "Sizes do not match in v_xor"

    let rec v_or v1 v2 =
      match v1, v2 with
      | [], [] -> []
      | b1 :: v1, b2 :: v2 ->
        (match b1, b2 with
          | ZERO, b2 -> b2
          | ONE, _ -> ONE
          | TOP, ONE -> ONE
          | TOP, _ -> TOP) :: (v_or v1 v2)
      | _, _ -> failwith "Sizes do not match in v_xor"

    let rec v_not v =
      match v with
      | [] -> []
      | b :: v -> match b with
                  | ZERO -> ONE :: (v_not v)
                  | ONE -> ZERO :: (v_not v)
                  | TOP -> TOP :: (v_not v)

    let rec v_one_to_top v =
      match v with
      | [] -> []
      | b :: v ->
        match b with
        | ONE -> TOP :: (v_one_to_top v)
        | _ -> b :: (v_one_to_top v)

    let rec v_mul (v1: bit list) (v2: bit list): bit list =
      match v1, v2 with
      | [], _ ->
        zeroext [] (get_size (Vect v2))
      | b1 :: v1, _ ->
        match b1 with
        | ZERO -> zeroext (ZERO :: (v_mul v1 v2)) (get_size (Vect v2))
        | ONE -> zeroext (add (v2 @ [ZERO]) (ZERO :: (v_mul v1 v2))) (get_size (Vect v2))
        | TOP -> zeroext (add ((v_one_to_top v2) @ [ZERO]) (ZERO :: (v_mul v1 v2))) (get_size (Vect v2))

    let binop op v1 v2 =
      let sz1 = get_size v1 in
      let vect2 = v2 in
      if sz1 = (get_size v2) || op = Asm.Shr || op = Asm.Shl then
        begin
          match v1, v2 with
          | Vect v1, Vect v2 ->
            begin
            match op with
            | Asm.Add -> Vect (add v1 v2)
            | Asm.Sub -> Vect (sub v1 v2)
            | Asm.And -> Vect (v_and v1 v2)
            | Asm.Xor -> Vect (v_xor v1 v2)
            | Asm.Or -> Vect (v_or v1 v2)
            | Asm.Mul -> Vect (v_mul (zeroext v1 (sz1*2)) (zeroext v2 (sz1*2)))
            | Asm.IMul -> Vect (v_mul (signext v1 (sz1*2)) (signext v2 (sz1*2)))
            | Asm.Div -> top sz1
            | Asm.IDiv -> top sz1
            | Asm.Mod -> top sz1
            | Asm.Shl ->
              begin
                try
                let off = get_singleton vect2 in
                let off = match off with
                          | Asm.Num n -> n
                          | _ -> failwith "" in
                Vect (shl v1 off sz1)
                with
                | _ -> top sz1
              end
            | Asm.Shr ->
              begin
                try
                let off = get_singleton vect2 in
                let off = match off with
                          | Asm.Num n -> n
                          | _ -> failwith "" in
                Vect (shr v1 off sz1)
                with
                | _ -> top sz1
              end
            | _ -> top sz1 (* Unimplemented: return top *)
            end
          | _, _ -> failwith "Bottom"
        end
      else failwith (Printf.sprintf "Sizes do not match in %s %s %s" (to_string v1) (Asm.string_of_binop op) (to_string v2))

    let unop op v =
      match op with
      | Asm.SignExt sz ->
        begin
          match v with
          | Vect v -> Vect (signext v sz)
          | Bot _ -> failwith "Bottom vector has no sign"
        end
      | Asm.ZeroExt sz ->
        begin
          match v with
          | Vect v -> Vect (zeroext v sz)
          | Bot _ -> failwith "Bottom vector cannot be extended"
        end
      | Asm.Not ->
        begin
          match v with
          | Vect v -> Vect (v_not v)
          | Bot _ -> v
        end

    let rec lt_aux v1 v2 =
      match v1, v2 with
      | [], [] -> [ZERO]
      | b1 :: v1, b2 :: v2 ->
        begin
        match b1, b2 with
        | ZERO, ZERO -> (lt_aux v1 v2)
        | ZERO, ONE -> [ONE]
        | ZERO, TOP -> join_aux [ONE] (lt_aux v1 v2)
        | ONE, ZERO -> [ZERO]
        | ONE, ONE -> lt_aux v1 v2
        | ONE, TOP -> join_aux [ZERO] (lt_aux v1 v2)
        | TOP, ZERO -> join_aux [ZERO] (lt_aux v1 v2)
        | TOP, ONE -> join_aux [ONE] (lt_aux v1 v2)
        | TOP, TOP -> [TOP]
        end
      | _, _ -> failwith "Not the same size"

    let lt v1 v2 =
      match v1, v2 with
      | Bot _, _ -> failwith "Bot"
      | _, Bot _ -> failwith "Bot"
      | Vect v1, Vect v2 -> Vect (lt_aux v1 v2)

    let rec gt_aux v1 v2 =
      match v1, v2 with
      | [], [] -> [ZERO]
      | b1 :: v1, b2 :: v2 ->
        begin
        match b1, b2 with
        | ZERO, ZERO -> (gt_aux v1 v2)
        | ZERO, ONE -> [ZERO]
        | ZERO, TOP -> join_aux [ZERO] (gt_aux v1 v2)
        | ONE, ZERO -> [ONE]
        | ONE, ONE -> gt_aux v1 v2
        | ONE, TOP -> join_aux [ONE] (gt_aux v1 v2)
        | TOP, ZERO -> join_aux [ONE] (gt_aux v1 v2)
        | TOP, ONE -> join_aux [ZERO] (gt_aux v1 v2)
        | TOP, TOP -> [TOP]
        end
      | _, _ -> failwith "Not the same size"

    let gt v1 v2 =
      match v1, v2 with
      | Bot _, _ -> failwith "Bot"
      | _, Bot _ -> failwith "Bot"
      | Vect v1, Vect v2 -> Vect (gt_aux v1 v2)

    let cmp op v1 v2 =
      match op with
      | Asm.EQ -> eq v1 v2
      | Asm.NEQ ->
        begin
          match (eq v1 v2) with
          | Vect [ZERO] -> Vect [ONE]
          | Vect [ONE] -> Vect [ZERO]
          | Vect [TOP] -> Vect [TOP]
          | _ -> failwith ""
        end
      | Asm.LT -> (lt v1 v2)
      | Asm.GT -> (gt v1 v2)
      | _ -> failwith (Printf.sprintf "Unimplemented: cmp %s on vectors" (Asm.string_of_cmp op))

    let bunop op v =
      failwith "Unimplemented: bunop on vectors"

    let bbinop op v1 v2 =
      match op with
      | Asm.LogAnd ->
        begin
          match v1, v2 with
          | Vect [ONE],  Vect [ONE]  -> Vect [ONE]
          | Vect [TOP],  Vect [ONE]  -> Vect [TOP]
          | Vect [ONE],  Vect [TOP]  -> Vect [TOP]
          | Vect [ZERO], Vect [_]    -> Vect [ZERO]
          | Vect [_],    Vect [ZERO] -> Vect [ZERO]
          | Vect [TOP],  Vect [TOP]  -> Vect [TOP]
          | _, _ -> failwith "incorrect bexp"
        end
      | Asm.LogOr ->
        begin
          match v1, v2 with
          | Vect [ONE],  Vect [_]   -> Vect [ONE]
          | Vect [_],    Vect [ONE] -> Vect [ONE]
          | Vect [ZERO], Vect [b]   -> Vect [b]
          | Vect [TOP],  Vect [_]   -> Vect [TOP]
          | _, _ -> failwith "incorrect bexp"
        end

    let rec update_sub_aux v start finish nv =
      match finish, start with
      | 0, _ -> v
      | _, 0 -> begin
                match v, nv with
                | [], _ -> failwith "Impossible to update"
                | b1::v1, b2:: v2 -> b2 :: (update_sub_aux v1 0 (finish-1) v2)
                | _, _ -> failwith "Impossible to update"
                end
      | _, _ -> begin
                match v with
                | [] -> failwith "Impossible to update"
                | b::v -> b :: (update_sub_aux v (start-1) (finish-1) nv)
                end

    let update_sub v start finish nv =
      match v, nv with
      | Bot _, _ -> v
      | _, Bot _ -> Bot (get_size v)
      | Vect v, Vect nv -> Vect (update_sub_aux v start finish nv)

    let rec get_sub_aux v start finish =
      match start, finish with
      | _, 0 -> begin
                match v with
                | [] -> failwith "Vector too short"
                | b :: v -> [b]
                end
      | 0, _ -> begin
                match v with
                | [] -> failwith "Vector too short"
                | b :: v -> b :: (get_sub_aux v 0 (finish-1))
                end
      | _, _ -> match v with
                | [] -> failwith "Cannot get sub of empty vector"
                | b :: v -> get_sub_aux v (start-1) (finish-1)

    let get_sub v start finish =
      match v with
      | Bot _ -> Bot (finish - start)
      | Vect v -> Vect (get_sub_aux v start finish)

    end: Numericaldomain.T)
