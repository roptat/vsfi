open Data
open Bitstring

module L = Log.Make(struct let name = "symbdom" end)

type label = Asm.label

let label_of_sym s =
  match s.Elf_info.st_type with
  | Elf_info.STT_OBJECT -> if (string_of_bitstring s.Elf_info.st_name) = "sfi$id" then Asm.Data else failwith "Unexpected Object symbol"
  | Elf_info.STT_FUNC ->
    (match s.Elf_info.st_shndx with
    | Elf_info.SHN_UNDEF -> Asm.Trust (string_of_bitstring s.Elf_info.st_name)
    | Elf_info.SHN i -> Asm.Fun (string_of_bitstring s.Elf_info.st_name)
    | _ -> failwith "Unsupported function relocation type")
  | Elf_info.STT_SECTION ->
    (match s.Elf_info.st_shndx with
     | Elf_info.SHN i ->
       if (string_of_bitstring s.Elf_info.st_name) = ".sfi"
       then Asm.Data
       else if (string_of_bitstring s.Elf_info.st_name) = ".text"
       then Asm.Code
       else failwith (Printf.sprintf "Unexpected Section symbol %s" (string_of_bitstring s.Elf_info.st_name))
     | _ -> failwith "Unknow section relocation")
  | _ -> failwith (Printf.sprintf "Unsupported relocation type: %s" (Elf_info.string_of_st_type s.Elf_info.st_type))

module Make(D: Numericaldomain.T) =
  (struct
    type t = (label * D.t)
    
    let top size = (Asm.Zero, D.top size)

    let get_size v =
      let (l, v) = v in
      D.get_size v

    let forget t = top (get_size t)

    let is_top v = match v with (_, b) -> D.is_top b

    let is_subset v1 v2 =
      match v1, v2 with
      | (l1, v1), (l2, v2) ->
        if l1 = l2 then D.is_subset v1 v2
        else false

    let to_string v =
      match v with
      | (l, v) -> Printf.sprintf "%s + %s" (Asm.string_of_label l) (D.to_string v)

    let join v1 v2 =
      if (get_size v1) = (get_size v2) then
        match v1, v2 with
        | (l1, v1), (l2, v2) ->
          if l1 = l2 then
          (l1, D.join v1 v2)
          else top (D.get_size v1)
      else failwith "Incompatible sizes"

    let widen v1 v2 =
      if (get_size v1) = (get_size v2) then
        match v1, v2 with
        | (l1, v1), (l2, v2) ->
          if l1 = l2 then
          (l1, D.widen v1 v2)
          else top (D.get_size v1)
      else failwith (Printf.sprintf "Incompatible sizes: %s and %s" (to_string v1) (to_string v2))

    let meet v1 v2 =
      if (get_size v1) = (get_size v2) then
        match v1, v2 with
        | (l1, v1), (l2, v2) ->
          if l1 = l2 then
          (l1, D.meet v1 v2)
          (* not perfect, but we can't say that two different label don't overlap *)
          else (l1, v1)
      else failwith "Incompatible sizes"

    let of_word w =
      (Asm.Zero, D.of_word w)

    let of_reloc r =
      match r with
      | Asm.Rentry (r, o) -> (label_of_sym r.Elf_info.Reloc.r_symb, D.of_word o)
      | Asm.Block (b, o) -> (b, D.of_word o)

    let of_concrete c sz =
      match c with
      | Asm.Num n -> (Asm.Zero, D.of_concrete c sz)
      | Asm.Loc (l, n) -> (l, D.of_concrete (Asm.Num n) sz)

    let is_between v sz inf sup =
      let (infl, infv) = inf in
      let (supl, supv) = sup in
      let (l, v) = v in
      if infl = supl && supl = l then
        D.is_between v sz infv supv
      else
        false

    let rec binop op v1 v2 =
      let (l1, v1) = v1 in
      let (l2, v2) = v2 in
      match op with
      | Asm.Add -> if l1 = Asm.Zero
                   then (l2, D.binop op v1 v2)
                   else if l2 = Asm.Zero
                   then (l1, D.binop op v1 v2)
                   else top (D.get_size v1)
      | Asm.Sub -> if l2 = Asm.Zero
                   then (l1, D.binop op v1 v2)
                   else if l1 = l2
                   then (Asm.Zero, D.binop op v1 v2)
                   else top (D.get_size v1)
      | _ -> if l1 = Asm.Zero && l2 = Asm.Zero
             then (Asm.Zero, D.binop op v1 v2)
             else
               if l1 != Asm.Zero then
                 binop op (top (D.get_size v1)) (l2, v2)
               else
                 binop op (l1, v1) (top (D.get_size v2))

    let unop op v =
      let (l, v) = v in
      if l = Asm.Zero || (match op with | Asm.ZeroExt _ -> true | _ -> false)
      then (l, D.unop op v)
      else top (D.get_size v)

    let cmp op v1 v2 =
      if (get_size v1) = (get_size v2) then
        begin
        let (l1, v1) = v1 in
        let (l2, v2) = v2 in
        if l1 = l2 && l1 = Asm.Zero then
          (Asm.Zero, D.cmp op v1 v2)
        else
          top 1
        end
      else failwith "Sizes do not match in cmp"

    let bunop op v =
      let (l, v) = v in
      if l = Asm.Zero then (Asm.Zero, D.bunop op v) else top 1

    let bbinop op v1 v2 =
      if (get_size v1) = (get_size v2) then
        begin
        let (l1, v1) = v1 in
        let (l2, v2) = v2 in
        if l1 = l2 && l1 = Asm.Zero then
          (Asm.Zero, D.bbinop op v1 v2)
        else
          top 1
        end
      else failwith "Sizes do not match in bbinop"

    let update_sub v start finish nv =
      match v, nv with
      | (Asm.Zero, v), (Asm.Zero, nv) -> (Asm.Zero, D.update_sub v start finish nv)
      | _, _ -> top (get_size v)

    let get_sub v start finish =
      match v with
      | (Asm.Zero, v) -> (Asm.Zero, D.get_sub v start finish)
      | _ -> top (finish - start + 1)

    let get_singleton v =
      let (l, v) = v in
      if l = Asm.Zero then D.get_singleton v
      else match D.get_singleton v with
           | Asm.Num n -> Asm.Loc (l, n)
           | Asm.Loc (l', n) -> failwith "Unsupported conversion"

    let concretization v =
      let (l, v) = v in
      if l = Asm.Zero then D.concretization v
      else List.map (fun c -> match c with | Asm.Num n -> Asm.Loc (l, n)
                                           | Asm.Loc (l', n) -> failwith "Unsupported conversion") (D.concretization v)

    end: Numericaldomain.T)
