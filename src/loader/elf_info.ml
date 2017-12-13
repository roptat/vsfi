(* BEWARE: the parsers makes the assumption that Int32.to_int is exact.       *)
(* This is true if the Ocaml int is 63 bits long...                           *)

open Bitstring
open Int32

(** Utils *)
let output_list_sep ins ends out_elt o l =
  let rec out l =
    match l with
    | [] -> ()
    | [e] -> out_elt o e
    | e::l -> out_elt o e  ; output_string o ins ;
              out l in
  out l ; output_string o ends
  
(** Header *)


(** Header types *)
exception InvalidClass
exception InvalidData

type ei_class = ELFCLASS32 | ELFCLASS64
                           
type ei_data  = ELFDATALSB | ELFDATAMSB

type e_ident = {
    ei_class : ei_class ; 
    ei_data  : ei_data ; 
  }
             
type e_type = ET_NONE | ET_REL | ET_EXEC | ET_DYN | ET_CORE | ET_PROC of int

type e_machine = EM_NONE | EM_M32 | EM_SPARC | EM_386 | EM_68K | EM_88K | EM_860 | EM_MIPS | EM of int

type header = {
    e_ident : e_ident ; 
    e_type  : e_type ; 
    e_machine : e_machine ; 
    e_version : int32 ;
    e_entry     : int32 ; (* start virtual address *)
    e_phoff     : int32 ; 
    e_shoff     : int32 ; 
    e_flags     : int32 ; 
    e_ehsize    : int ; 
    e_phentsize : int ; 
    e_phnum     : int ; 
    e_shentsize : int ;
    e_shnum     : int ; 
    e_shstrndx  : int
  }

(** Header parsing functions *)

let parse_ei_class bs = 
  bitmatch bs with
| { 0 : 8 } -> raise InvalidClass
| { 1 : 8 } -> ELFCLASS32
| { 2 : 8 } -> ELFCLASS64
| {   _   }  -> failwith "Unknown ei_class"

let output_ei_class o = function
  | ELFCLASS32 -> output_string o "32-bit"
  | ELFCLASS64 -> output_string o "64-bit"


let parse_ei_data bs = 
  bitmatch bs with
| { 0 : 8  } -> raise InvalidData
| { 1 : 8 } -> ELFDATALSB
| { 2 : 8 } -> ELFDATAMSB 
| {   _   }   -> failwith "Unknown ei_data"

let output_ei_data o = function
  | ELFDATALSB -> output_string o "LSB"
  | ELFDATAMSB -> output_string o "MSB"

let parse_e_idend bs = 
  bitmatch bs with
| { 0x7f : 8 ; 
    "E"  : 8 : string;
    "L"  : 8 : string;
    "F"  : 8 : string ;
    ei_class : 8 : bitstring ;
    ei_data  : 8 : bitstring ;
    1 : 8 : unsigned } -> {ei_class = parse_ei_class ei_class ; ei_data = parse_ei_data ei_data}

let output_e_ident o id = 
  Printf.printf "ELF %a %a\n" output_ei_class id.ei_class output_ei_data id.ei_data

let parse_e_type bs = 
  (
    bitmatch bs with
    | { 0 : 16 : unsigned , littleendian } -> ET_NONE
    | { 1 : 16 : unsigned , littleendian} -> ET_REL
    | { 2 : 16 : unsigned , littleendian } -> ET_EXEC
    | { 3 : 16 : unsigned , littleendian} -> ET_DYN 
    | { 4 : 16 : unsigned , littleendian } -> ET_CORE
    | { x : 16 : unsigned , littleendian}  -> 
       if 0xff00 <= x && x <= 0xffff then  ET_PROC x
       else failwith (Printf.sprintf "Unknown e_type %i" x)
  )

let output_e_type o = function
  | ET_NONE -> output_string o "undefined"
  | ET_REL  -> output_string o "relocatable"
  | ET_EXEC  -> output_string o "executable"
  | ET_DYN   -> output_string o "shared"
  | ET_CORE  -> output_string o "core"
  | ET_PROC i -> Printf.printf "processor-specific %i" i

let parse_e_machine bs = 
  bitmatch bs with
| { 0 : 16 : unsigned , littleendian } -> EM_NONE
| { 1 : 16 : unsigned , littleendian } -> EM_M32
| { 2 : 16 : unsigned , littleendian } -> EM_SPARC
| { 3 : 16 : unsigned , littleendian } -> EM_386
| { 4 : 16 : unsigned , littleendian } -> EM_68K
| { 5 : 16 : unsigned , littleendian } -> EM_88K
| { 7 : 16 : unsigned , littleendian } -> EM_860
| { 8 : 16 : unsigned , littleendian } -> EM_MIPS
| { x : 16 : unsigned , littleendian } -> EM x

let output_e_machine o = function
  | EM_NONE  -> output_string o "undefined"
  | EM_M32   -> output_string o "AT&T WE 32100"
  | EM_SPARC -> output_string o "SPARC"
  | EM_386   -> output_string o "Intel 80386"
  | EM_68K   -> output_string o "Motorola 68000"
  | EM_88K   -> output_string o "Motorola 88000"
  | EM_860   -> output_string o "Intel 80860"
  | EM_MIPS  -> output_string o "MIPS RS3000"
  | EM x     -> Printf.fprintf o "Machine %i" x

              
let parse_header bs = 
  bitmatch bs with
  {
    e_ident : 16 * 8 : bitstring ; 
    e_type  : 16 : bitstring ; 
    e_machine : 16 : bitstring ; 
    e_version : 32 : littleendian ;
    e_entry   : 32 : littleendian  ;
    e_phoff   : 32 : littleendian   ; 
    e_shoff   : 32 : littleendian   ; 
    e_flags   : 32 : littleendian  ;
    e_ehsize  : 16 : unsigned , littleendian   ; 
    e_phentsize : 16 : unsigned , littleendian ; 
    e_phnum     : 16 : unsigned , littleendian ; 
    e_shentsize : 16 : unsigned , littleendian ; 
    e_shnum     : 16 : unsigned , littleendian ; 
    e_shstrndx  : 16 : unsigned , littleendian ;
    _      : -1         : bitstring
  }  -> 
  { e_ident = parse_e_idend e_ident ; 
    e_type  = parse_e_type e_type ; 
    e_entry = e_entry ; 
    e_machine = parse_e_machine e_machine ; 
    e_version = e_version ; 
    e_phoff = e_phoff ; 
    e_shoff = e_shoff ; 
    e_flags = e_flags ; 
    e_ehsize = e_ehsize ; 
    e_phentsize = e_phentsize ; 
    e_phnum     = e_phnum ; 
    e_shentsize = e_shentsize ; 
    e_shnum     = e_shnum ; 
    e_shstrndx = e_shstrndx
  } 

let output_header o 
                  { e_ident ; 
                    e_type  ; 
                    e_entry ; 
                    e_version ; 
                    e_machine  ; 
                    e_phoff  ; 
                    e_shoff  ; 
                    e_flags  ; 
                    e_ehsize ; 
                    e_phentsize  ; 
                    e_phnum      ; 
                    e_shentsize  ; 
                    e_shnum      ; 
                    e_shstrndx 
                  }  = 
  Printf.fprintf o "%a, %a, %a, version %i" 
                 output_e_ident e_ident 
                 output_e_type e_type 
                 output_e_machine e_machine
                 (Int32.to_int e_version)


(** Parsing of program sections *)

(** Section Header *)
type sh_flags = SHF_WRITE | SHF_ALLOC | SHF_EXECINSTR | SHF_MASK_PROC of int

type sh_type = 
  | SHT_NULL 
  | SHT_PROGBITS 
  | SHT_SYMTAB
  | SHT_STRTAB 
  | SHT_RELA 
  | SHT_HASH 
  | SHT_DYNAMIC
  | SHT_NOTE 
  | SHT_NOBITS
  | SHT_REL
  | SHT_SHLIB
  | SHT_DYNSYM
  | SHT_PROC of int
  | SHT_USER of int

type 'a shdr = {
    sh_name : 'a ; (* 'a is either a string index or a string *)
    sh_type : sh_type ; 
    sh_flags : sh_flags list ; 
    sh_addr   : int32 ; 
    sh_offset : int32 ; 
    sh_size   : int32 ;
    sh_link   : int32 ; 
    sh_info   : int32 ; 
    sh_addralign : int32 ;
    sh_entsize   : int32 
  }

let is_code_section_flags flags =
  (List.mem SHF_EXECINSTR flags) && not (List.mem SHF_WRITE flags)
let is_data_section_flags flags =
  List.mem SHF_WRITE flags && not (List.mem SHF_EXECINSTR flags)

(** Parsing of section header *)

let set_flag i msk flg = 
  if (i land msk) > 0 then [flg] else []

let output_flag o = function
  | SHF_WRITE -> output_string o "w"
  | SHF_ALLOC -> output_string o "r"
  | SHF_EXECINSTR -> output_string o "x"
  | SHF_MASK_PROC i -> Printf.fprintf o "proc(%i)" i 

(** Beware of endianness *)
let parse_sh_flags i =  
  (set_flag i 0x1 SHF_WRITE)
  @ (set_flag i 0x2 SHF_ALLOC) 
  @ (set_flag i 0x4 SHF_EXECINSTR) 
  @ (let proc = i lsl 28 in
     if proc > 0 then [SHF_MASK_PROC proc] else [])

let output_sh_flags o l = 
  (if List.mem SHF_ALLOC l
   then output_string o "r"
   else output_string o "-");
  (if List.mem SHF_WRITE l
   then output_string o "w"
   else output_string o "-");
  (if List.mem SHF_EXECINSTR l
   then output_string o "x"
   else output_string o "-")

let parse_sh_type i = 
  match i with
  | 0  -> SHT_NULL
  | 1  -> SHT_PROGBITS
  | 2  -> SHT_SYMTAB
  | 3  -> SHT_STRTAB
  | 4  -> SHT_RELA
  | 5  -> SHT_HASH
  | 6  -> SHT_DYNAMIC
  | 7  -> SHT_NOTE 
  | 8  -> SHT_NOBITS
  | 9  -> SHT_REL
  | 10 -> SHT_SHLIB
  | 11 -> SHT_DYNSYM
  | x  when 0x70000000 <= x && x <= 0x7fffffff -> SHT_PROC x
  (*  | x  when 0x80000000 <= x && x <= 0xffffffff -> SHT_USER x *)
  (*  | x  ->  failwith (Printf.sprintf "parse_sh_type : unknow type %i" x)*)
  | x -> SHT_USER x

let output_sh_type o = function
  | SHT_NULL -> output_string o "inactive"
  | SHT_PROGBITS -> output_string o "progbits"
  | SHT_SYMTAB   -> output_string o "symtab"
  | SHT_STRTAB   -> output_string o "strtab"
  | SHT_RELA     -> output_string o "rela"
  | SHT_HASH     -> output_string o "hash"
  | SHT_DYNAMIC  -> output_string o "dynamic"
  | SHT_NOTE     -> output_string o "note"
  | SHT_NOBITS   -> output_string o "nobits"
  | SHT_REL      -> output_string o "rel"
  | SHT_SHLIB    -> output_string o "shlib"
  | SHT_DYNSYM   -> output_string o "dynsym"
  | SHT_PROC x   -> Printf.fprintf o "proc(%i)"  x
  | SHT_USER x   -> Printf.fprintf o "user(%i)"  x

let parse_shdr bs = 
  bitmatch bs with
  { sh_name   : 32 : littleendian ;
    sh_type   : 32 : littleendian ; 
    sh_flags  : 32 : littleendian ; 
    sh_addr   : 32 : littleendian ;
    sh_offset : 32 : littleendian ;
    sh_size   : 32 : littleendian ;
    sh_link   : 32 : littleendian ;
    sh_info   : 32 : littleendian ; 
    sh_addralign : 32 : littleendian ; 
    sh_entsize : 32 : littleendian
  } -> 
  { sh_name  = sh_name ; 
    sh_type  = parse_sh_type (Int32.to_int sh_type) ; 
    sh_flags = parse_sh_flags (Int32.to_int sh_flags) ;
    sh_addr  = sh_addr ; 
    sh_offset = sh_offset ; 
    sh_size   = sh_size ; 
    sh_link   = sh_link ; 
    sh_info   = sh_info ; 
    sh_addralign = sh_addralign ; 
    sh_entsize   = sh_entsize
  }

let output_shdr out_name o 
                { sh_name ; 
                  sh_type ; 
                  sh_flags ; 
                  sh_addr  ; 
                  sh_offset ; 
                  sh_size   ; 
                  sh_link   ; 
                  sh_info   ; 
                  sh_addralign ; 
                  sh_entsize  
                } = Printf.fprintf o "Section %a, %a, %a, %i" 
                                   out_name sh_name 
                                   output_sh_type sh_type 
                                   output_sh_flags sh_flags
                                   (Int32.to_int sh_entsize)

let is_shdr_0 { sh_name   ; 
                sh_type   ; 
                sh_flags  ; 
                sh_addr   ; 
                sh_offset ; 
                sh_size   ; 
                sh_link   ; 
                sh_info   ; 
                sh_addralign  ; 
                sh_entsize   
              } = 
  sh_name = Int32.zero
  && sh_type = SHT_NULL
  && sh_flags = []
  && sh_offset = Int32.zero
  && sh_size   = Int32.zero
  && sh_link   = Int32.zero
  && sh_info   = Int32.zero
  && sh_addralign = Int32.zero
  && sh_entsize   = Int32.zero

(** Predefined sections *)

module Strtab = 
  (** .strtab section *)
  struct
    (* [Array.length tab] is the number of bytes of the [tbl].
     tbl.(i) is the string starting at index [i] is the bitstring.
     *)
    
    type t = { 
        tab : bitstring option array;
        tbl : bitstring
      }

    let make bs = 
      let sz = bitstring_length bs / 8 in
      { tab = Array.make sz None ;
        tbl = bs}

    let rec _end_of_string bs i  = 
      bitmatch bs with
    | { 0 : 8 } -> i
    | { x : 8 ; bs : -1 : bitstring  } -> _end_of_string bs (i+1) 

    let find i {tab ; tbl}  = 
      match tab.(i) with
      | None -> 
         let bs = (dropbits (i * 8) tbl) in
         let j = _end_of_string bs 0 in
         let r = (takebits (j*8) bs) in
         tab.(i) <- Some r ;
         r
      | Some s -> s
  end

module Int = 
  struct
    type t = int
    let compare : int-> int-> int = Pervasives.compare
  end

module IntMap = 
  struct

    module IntMap = Map.Make(Int)
    include IntMap
    (*  include Basic_types.Int.Map *)

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

let parse_array check_0 parse_elt  nb sz bs = 
  
  let rec xparse idx acc bs = 
    if idx = nb
    then acc
    else let elt = parse_elt bs in
         let acc =
           if idx = 0
           then
             match check_0 with
             | None -> IntMap.add idx elt acc
             | Some check_0 -> assert (check_0 elt) ; acc
           else IntMap.add idx elt acc in
         xparse (idx + 1) acc (dropbits (sz * 8) bs) in

  xparse 0 IntMap.empty bs

let parse_list parse_elt nb sz bs = 

  let rec xparse nb bs =
    if nb = 0
    then []
    else
      (parse_elt bs)::(xparse (nb-1) (dropbits (sz * 8) bs)) in

  xparse nb bs

  
let parse_shdrs header bs = 
  (* start of the section header *)
  let bs = dropbits ((Int32.to_int header.e_shoff)*8) bs in
  let nb = header.e_shnum in
  let sz = header.e_shentsize in
  (* parse nb section headers *)

  parse_array (Some is_shdr_0) parse_shdr nb sz bs


let extract_section sec bs = 
  let offset = sec.sh_offset in 
  let size   = sec.sh_size in 
  takebits ((Int32.to_int size)*8) (dropbits ((Int32.to_int offset)*8) bs)


let find_string_table header secs bs = 
  let idx = header.e_shstrndx in
  assert (idx >= 0);
  if idx = 0
  then failwith "Section string table is absent"
  else 
    begin
      let sec = IntMap.find idx  secs  in
      assert (sec.sh_type = SHT_STRTAB) ;
      let sec = extract_section sec bs in
      Strtab.make sec
    end

(** Symbol Table *)

type st_bind = STB_LOCAL | STB_GLOBAL | STB_WEAK | STB_PROC of int

type st_type    = STT_NOTYPE | STT_OBJECT | STT_FUNC | STT_SECTION | STT_FILE | STT_OS of int | STT_PROC of int | STT_UKN of int

(* objdump seems to consider that 3 is also a possibility. *)
let parse_st_bind bs = 
  bitmatch bs with
| { 0 : 4 } -> STB_LOCAL
| { 1 : 4 } -> STB_GLOBAL
| { 2 : 4 } -> STB_WEAK
| { x : 4 } when 13 <= x && x <= 15 -> STB_PROC x


let string_st_bind  = function
  | STB_LOCAL  -> "l"
  | STB_GLOBAL -> "g"
  | STB_WEAK   -> " w"
  | STB_PROC x -> Printf.sprintf  "p(%i)" x


let output_st_bind o = function
  | STB_LOCAL  -> output_string o "l"
  | STB_GLOBAL -> output_string o "g"
  | STB_WEAK   -> output_string o " w"
  | STB_PROC x -> Printf.fprintf o "p(%i)" x


let parse_st_type bs =
  bitmatch bs with
| { 0 : 4 } -> STT_NOTYPE
| { 1 : 4 } -> STT_OBJECT
| { 2 : 4 } -> STT_FUNC
| { 3 : 4 } -> STT_SECTION
| { 4 : 4 } -> STT_FILE
| { x : 4 } when 13 <= x && x <= 15  -> STT_PROC x
| { x : 4 } when 10 <= x && x <= 12  -> STT_OS x
| { x : 4 } -> STT_UKN x

let output_st_type o = function
  | STT_NOTYPE    -> output_string o " "
  | STT_OBJECT    -> output_string o "O"
  | STT_FUNC      -> output_string o "F"
  | STT_SECTION   -> output_string o "S"
  | STT_FILE      -> output_string o "f"
  | STT_PROC x    -> Printf.fprintf o "p(%i)" x
  | STT_OS   x    -> Printf.fprintf o "o(%i)" x
  | STT_UKN  x    -> Printf.fprintf o " " (* objdump does not print this one *)

let string_of_st_type t =
  match t with
  | STT_NOTYPE    -> " "
  | STT_OBJECT    -> "O"
  | STT_FUNC      -> "F"
  | STT_SECTION   -> "S"
  | STT_FILE      -> "f"
  | STT_PROC x    -> Printf.sprintf "p(%i)" x
  | STT_OS   x    -> Printf.sprintf "o(%i)" x
  | STT_UKN  x    -> "U"

let parse_info bs = 
  bitmatch bs with
| { st_bind : 4 : bitstring; 
    st_type : 4 : bitstring
  } -> (parse_st_bind st_bind, parse_st_type st_type)


type shndx = 
  SHN_ABS 
| SHN_COMMON 
| SHN_UNDEF 
| SHN_RESERVE of int 
| SHN_PROC of int
| SHN of int 

let parse_shndx = function
  | 0 -> SHN_UNDEF
  | 0xfff1 -> SHN_ABS
  | 0xfff2 -> SHN_COMMON
  | x      -> 
     if x < 0xff00
     then SHN x
     else if 0xff00 <= x && x <= 0xff1f
     then SHN_PROC x
     else  SHN_RESERVE x


let output_bitstring o bs = 
  output_string o (string_of_bitstring bs)


let string_shndx sec  = function
  | SHN_ABS   -> "*ABS*"
  | SHN_UNDEF -> "*UND*"
  | SHN_COMMON ->"*COM*"
  | SHN   i    -> string_of_bitstring (IntMap.find i sec).sh_name
  | SHN_PROC i -> Printf.sprintf  "*P%i" i
  | SHN_RESERVE i -> Printf.sprintf  "*R%i" i


let output_shndx sec o = function
  | SHN_ABS   -> output_string o "*ABS*"
  | SHN_UNDEF -> output_string o "*UND*"
  | SHN_COMMON -> output_string o "*COM*"
  | SHN   i    -> output_bitstring o (IntMap.find i sec).sh_name
  | SHN_PROC i -> Printf.fprintf o "*P%i" i
  | SHN_RESERVE i -> Printf.fprintf o "*R%i" i


type sym = 
  { 
    st_name  : bitstring ; 
    st_value : int32 ; 
    st_size  : int32 ;
    st_bind  : st_bind ; 
    st_type  : st_type ;
    (*      st_other : int   ;  *)
    st_shndx : shndx
  }


let size_of_symb_entry = 128

                       
let parse_sym strtab shdrs bs = 
  bitmatch bs with
| { st_name : 32 : littleendian ;
    st_value : 32 : littleendian ; 
    st_size : 32 : littleendian ; 
    st_info : 8  : bitstring ;
    st_other : 8 ;
    st_shndx : 16 : unsigned , littleendian
  }  -> 
   let (st_bind,st_type) = parse_info st_info in
   { st_name  = if st_type = STT_SECTION
                then let sec = IntMap.find st_shndx shdrs in
                     sec.sh_name
                else Strtab.find (Int32.to_int st_name) strtab ;
     st_value = st_value ;
     st_size  = st_size ;
     st_bind  = st_bind ;
     st_type  = st_type ;
     st_shndx = parse_shndx st_shndx
   }


let output_sym secs o 
               { 
                 st_name;
                 st_value;
                 st_size;
                 st_bind;
                 st_type;
                 (*      st_other : int   ;  *)
                 st_shndx;
               }  = 
  Printf.fprintf o "%.8x %-5s %a %-8s %.8x %a" 
                 (Int32.to_int st_value)
                 (string_st_bind st_bind)
                 output_st_type st_type 
                 (string_shndx secs st_shndx)
                 (Int32.to_int st_size)
                 output_bitstring st_name

let output_fun secs o 
               { 
                 st_name;
                 st_value;
                 st_size;
                 st_bind;
                 st_type;
                 (*      st_other : int   ;  *)
                 st_shndx;
               }  = 
  Printf.fprintf o "%a %.8x" 
                 output_bitstring st_name
                 (Int32.to_int st_value)

let is_symb_0 s = 
  bitstring_length s.st_name = 0
  && Int32.to_int s.st_value = 0 
  && Int32.to_int s.st_size  = 0
  && s.st_bind = STB_LOCAL 
  && s.st_type = STT_NOTYPE
  && s.st_shndx = SHN_UNDEF


let is_symtab bs = 
  bitmatch bs with
| { ".symtab" : 7*8 : string ;
    rst : -1 : bitstring } when bitstring_length rst = 0 -> true
|  { _ } -> false


let is_strtab bs = 
  bitmatch bs with
| { ".strtab" : 7*8 : string ;
    rst : -1 : bitstring } when bitstring_length rst = 0 -> true
|  { _ } -> false
          
module SymTab =
  struct

    let find_symb_by_name str tbl = 
      let bs = bitstring_of_string str in
      snd (IntMap.search (fun _ s -> equals bs s.st_name) tbl)

  end

let parse_symtab secs bs = 
  let symtab = snd (IntMap.search (
                        fun k s -> is_symtab s.sh_name && s.sh_type = SHT_SYMTAB) secs) in
  let strtab = snd (IntMap.search (
                        fun k s -> is_strtab s.sh_name && s.sh_type = SHT_STRTAB) secs) in

  let sz  = Int32.to_int symtab.sh_entsize in
  assert (sz <> 0);
  let nb  = (Int32.to_int symtab.sh_size) /  sz  in

  let symtab = extract_section symtab bs in
  let strtab = extract_section strtab bs in

  parse_array (Some is_symb_0) (parse_sym (Strtab.make strtab) secs) nb sz  symtab

(** Program Header *)

type p_type = 
  | PT_NULL 
  | PT_LOAD
  | PT_DYNAMIC
  | PT_INTERP
  | PT_NOTE
  | PT_SHLIB
  | PT_PHDR
  | PT_PROC of int

let parse_p_type i = 
  match i with
  | 0  -> PT_NULL
  | 1  -> PT_LOAD
  | 2  -> PT_DYNAMIC
  | 3  -> PT_INTERP
  | 4  -> PT_NOTE
  | 5  -> PT_SHLIB
  | 6  -> PT_PHDR
  (*  | x  when 0x70000000 <= x && x <= 0x7fffffff -> PT_PROC x *)
  | x  -> (*failwith (Printf.sprintf "parse_p_type : unknown type %i" x)*) PT_PROC x

let output_p_type o = function
  | PT_NULL -> output_string o "*UND*"
  | PT_LOAD -> output_string o "LOAD"
  | PT_DYNAMIC   -> output_string o "DYNAMIC"
  | PT_INTERP   -> output_string o "INTERP"
  | PT_NOTE     -> output_string o "NOTE"
  | PT_SHLIB     -> output_string o "SHLIB"
  | PT_PHDR  -> output_string o "PHDR"
  | PT_PROC x   -> Printf.fprintf o "PROC(%i)"  x

type p_flags = PF_R | PF_W | PF_X

let parse_p_flags i =  
  (set_flag i 0x4 PF_R)
  @ (set_flag i 0x2 PF_W) 
  @ (set_flag i 0x1 PF_X) 

let has_pf_r l = List.mem PF_R l

let has_pf_w l = List.mem PF_W l

let has_pf_x l = List.mem PF_X l

let is_code_flags l = has_pf_x l && has_pf_r l

let is_data_flags l = has_pf_r l && has_pf_w l

let output_p_flags o l = 
  (if has_pf_r l
   then output_string o "r"
   else output_string o "-");
  (if has_pf_w l
   then output_string o "w"
   else output_string o "-");
  (if has_pf_x l
   then output_string o "x"
   else output_string o "-")





type phdr = 
  {
    p_type   : p_type ; 
    p_offset : int32 ;
    p_vaddr  : int32 ; 
    p_paddr  : int32 ; 
    p_filesz : int32 ; 
    p_memsz  : int32 ;
    p_flags  : p_flags list; (* not sure *)
    p_align  : int32
  }

let parse_phdr bs = 
  bitmatch bs with
  { p_type   : 32 : littleendian ; 
    p_offset : 32 : littleendian ; 
    p_vaddr  : 32 : littleendian ; 
    p_paddr  : 32 : littleendian ; 
    p_filesz : 32 : littleendian ; 
    p_memsz  : 32 : littleendian ; 
    p_flags  : 32 : littleendian ;
    p_align  : 32 : littleendian
  } -> 
  {
    p_type   = parse_p_type (Int32.to_int p_type) ; 
    p_offset = p_offset ;
    p_vaddr  = p_vaddr  ; 
    p_paddr  = p_paddr  ; 
    p_filesz = p_filesz ; 
    p_memsz  = p_memsz  ; 
    p_flags  = parse_p_flags (Int32.to_int p_flags) ; 
    p_align  = p_align
  }

let parse_phdrs header bs = 
  let e_phoff = Int32.to_int header.e_phoff in
  if e_phoff = 0
  then IntMap.empty (* No segments *)
  else 
    let sz =  header.e_phentsize in
    let nb =  header.e_phnum in
    let phdrs = dropbits (e_phoff * 8) bs in
    parse_array None parse_phdr nb sz phdrs


let output_phdr o 
                {
                  p_type ;
                  p_offset ;
                  p_vaddr  ;
                  p_paddr  ; 
                  p_filesz ; 
                  p_memsz  ;
                  p_flags  ; (* not sure *)
                  p_align  
                }  = 
  Printf.fprintf o "Segment %a off %.8x vaddr %.8x paddr %.8x align %i\n\tfilesz %.8x memsz %.8x flags %a\n"
                 output_p_type p_type 
                 (Int32.to_int p_offset)
                 (Int32.to_int p_vaddr)
                 (Int32.to_int p_paddr)
                 (Int32.to_int p_align)
                 (Int32.to_int p_filesz)
                 (Int32.to_int p_memsz)
                 output_p_flags p_flags



let get_code_segment phdrs = 
  let code = IntMap.fold 
               (fun k hd acc -> 
                 if hd.p_type = PT_LOAD && is_code_flags hd.p_flags 
                 then hd::acc else acc) phdrs [] in
  match code with
  | [] -> failwith "Code segment is absent"
  | [e] -> e
  |  _  -> failwith "Multiple code segments"


let get_dynamic_segment phdrs =
  let code = IntMap.fold
               (fun k hd acc ->
                 if hd.p_type = PT_DYNAMIC then hd::acc else acc) phdrs [] in
  match code with
  | []  -> failwith "Dynamic segment is missing"
  | [e] -> e
  |  _  -> failwith "Multiple dynamic segments"
         

let get_data_segment phdrs = 
  let code = IntMap.fold 
               (fun k hd acc -> 
                 if hd.p_type = PT_LOAD && is_data_flags hd.p_flags 
                 then hd::acc else acc) phdrs [] in
  match code with
  | [] -> failwith "Data segment is absent"
  | [e] -> e
  |  _  -> failwith "Multiple data segments"

let get_code_section shdrs =
  let code = IntMap.fold
              (fun k hd acc ->
                if (is_code_section_flags hd.sh_flags) &&
                   ((string_of_bitstring hd.sh_name) = ".text")
                then hd::acc else acc)
              shdrs [] in
  match code with
  | []  -> failwith "No .text section found"
  | [e] -> e
  |  _  -> failwith "Multiple .text sections"

let get_code_rel_section shdrs =
  let rel = IntMap.fold
             (fun k hd acc ->
               if (string_of_bitstring hd.sh_name) = ".rel.text"
               then hd::acc else acc)
             shdrs [] in
  match rel with
  | []  -> failwith "No .rel.text section found"
  | [e] -> e
  |  _  -> failwith "Multiple .rel.text sections"

let get_data_section shdrs =
  let data = IntMap.fold
              (fun k hd acc ->
                if (is_data_section_flags hd.sh_flags) &&
                   ((string_of_bitstring hd.sh_name) = ".data")
                then hd::acc else acc)
              shdrs [] in
  match data with
  | []  -> failwith "No .data section found"
  | [e] -> e
  |  _  -> failwith "Multiple .data sections"

let bs_of_segment seg bs =
  let seg_offset = Int32.to_int seg.p_offset in
  let seg_filesz = Int32.to_int seg.p_filesz in
  takebits (seg_filesz * 8) (dropbits (seg_offset * 8) bs)

  

  

module ProcImage = 
  struct

    (** We make the following assumptions:
    - The file is a relocatable object file.
    - The file has at least two sections: .text and .data.
    *)

    type p_image =
      {
        v_entry : int32 ; (* entry point of the process i.e., main *)
        
        c_vaddr  : int32 ; (* virtual address of the start of the process image *)

        code_segment : bitstring ; 

        d_vaddr : int32 ; (* virtual address of the data segment *)
        
        data_segment : bitstring ; 
      }

    let output o 
               { v_entry ; c_vaddr ; code_segment ; d_vaddr ; data_segment }
      = 
      Printf.fprintf o "start address %.8x, code segment %.8x, data segment %.8x\n" 
                     (Int32.to_int v_entry)
                     (Int32.to_int c_vaddr)
                     (Int32.to_int d_vaddr) ; 
      Printf.fprintf o "Code segment:\n%a\n" hexdump_bitstring code_segment ; 
      Printf.fprintf o "Data segment:\n%a\n" hexdump_bitstring data_segment 


      

    let get_main_addr header bs = 
      let secs   = parse_shdrs header bs in 
      let tbl    = find_string_table header secs bs in
      let secs   = IntMap.map (fun sec -> 
                       {sec with sh_name = Strtab.find (Int32.to_int sec.sh_name) tbl}) secs in
      let symtab = parse_symtab secs bs in
      let main = SymTab.find_symb_by_name "main" symtab in
      main.st_value

(*
    sh_name : 'a ; (* 'a is either a string index or a string *)                
    sh_type : sh_type ;                                                         
    sh_flags : sh_flags list ;                                                  
    sh_addr   : int32 ;                                                         
    sh_offset : int32 ;                                                         
    sh_size   : int32 ;                                                         
    sh_link   : int32 ;                                                         
    sh_info   : int32 ;                                                         
    sh_addralign : int32 ;                                                      
    sh_entsize   : int32       *)

    let make_code_section code bs = 
      let code_addr   = Int32.to_int code.sh_addr in
      let code_align  = Int32.to_int code.sh_addralign in
      let code_offset = Int32.to_int code.sh_offset in
      let code_filesz   = Int32.to_int code.sh_size in

      let head   = code_addr mod code_align in (* For gcc, this is 0 *)
      let tail   = code_align - ((code_offset + code_filesz) mod code_align) in

      let code_init = code_offset - head in
      let code_bits = head + code_filesz + tail in

      let code_seg   = takebits (code_bits * 8) (dropbits (code_init * 8) bs) in

      let v_code_init = code_addr - head in
      let v_code_fini = v_code_init + code_bits in

      assert (v_code_init mod code_align = 0
              && v_code_fini mod code_align = 0) ; 

      (v_code_init, code_seg , v_code_fini - 1)


    let make_data_section data bs = 
      let data_addr    = Int32.to_int data.sh_addr in
      let data_align   = Int32.to_int data.sh_addralign in
      let data_offset  = Int32.to_int data.sh_offset in
      let data_filesz  = Int32.to_int data.sh_size in
      let data_memsz  = Int32.to_int data.sh_size in

      let head = data_addr mod data_align in

      let data_init = data_offset - head in

      let data_seg = takebits (data_filesz * 8) (dropbits (data_init * 8) bs) in

      assert (data_memsz >= data_filesz) ; 

      let data_bss = data_offset + data_memsz in

      let tail = data_align - (data_bss mod data_align) in

      let zeros = (data_memsz - data_filesz) + tail in

      let data_bss = create_bitstring (zeros * 8) in

      let data_image = Bitstring.concat [data_seg ; data_bss] in

      let v_data_init = data_addr - head in
      let v_data_fini = v_data_init + head + data_filesz + zeros in

      (v_data_init, data_image, v_data_fini - 1)

    let make secs bs = 
      let header = parse_header bs in
      (*let shdrs  = parse_shdrs header bs in*)
      let phdrs  = parse_phdrs header bs in

      let code = get_code_section secs in
      let data = get_data_section secs in

      let (v_code_init,code_seg,v_code_fini) = make_code_section code bs in
      let (v_data_init,data_seg,v_data_fini) = make_data_section data bs in

      let main = get_main_addr header bs in

      { 
        v_entry      = main ; 
        c_vaddr      = Int32.of_int v_code_init ; 
        code_segment = code_seg ;
        d_vaddr      = Int32.of_int v_data_init ; 
        data_segment = data_seg
      }      

    let output o {v_entry;c_vaddr;code_segment;d_vaddr;data_segment} =
      Printf.fprintf o"v_entry : %x\nc_vaddr : %x\n%a"
                     (Int32.to_int v_entry) (Int32.to_int c_vaddr)
                     Bitstring.hexdump_bitstring code_segment
      

      
  end

module Reloc =
  struct
    type rtype =
      | R_386_NONE
      | R_386_32
      | R_386_PC32
      | R_386_GOT32
      | R_386_PLT32
      | R_386_COPY
      | R_386_GLOB_DAT
      | R_386_JMP_SLOT
      | R_386_RELATIVE
      | R_386_GOTOFF
      | R_386_GOTPC

      
    type rentry =
      {
        r_offset : int32 ; (* relocation address *)
        r_symb   : sym ; (* symbol *)
        r_type   : rtype;
        r_addend  : int32 option
      }


    let parse_rtype = function
      | 0  -> R_386_NONE
      | 1  -> R_386_32
      | 2  -> R_386_PC32
      | 3  -> R_386_GOT32
      | 4  -> R_386_PLT32
      | 5  -> R_386_COPY
      | 6  -> R_386_GLOB_DAT
      | 7  -> R_386_JMP_SLOT
      | 8  -> R_386_RELATIVE
      | 9  -> R_386_GOTOFF
      | 10 -> R_386_GOTPC
      | i  -> failwith (Printf.sprintf "Unknown relocation type %i" i)

    let size_of_rtype = function 
      | R_386_NONE     -> 0
      | R_386_32       -> 32
      | R_386_PC32     -> 32
      | R_386_GOT32    -> 32
      | R_386_PLT32    -> 32
      | _ -> failwith "TODO: Size of exotic relocation types"

    let string_of_rtype = function 
      | R_386_NONE     -> "R_386_NONE"
      | R_386_32       -> "R_386_32"
      | R_386_PC32     -> "R_386_PC32"
      | R_386_GOT32    -> "R_386_GOT32"
      | R_386_PLT32    -> "R_386_PLT32"
      | R_386_COPY     -> "R_386_COPY"
      | R_386_GLOB_DAT -> "R_386_GLOB_DAT"
      | R_386_JMP_SLOT -> "R_386_JMP_SLOT"
      | R_386_RELATIVE -> "R_386_RELATIVE"
      | R_386_GOTOFF   -> "R_386_GOTOFF"
      | R_386_GOTPC    -> "R_386_GOTPC"

    let parse_symbol symbs i =
      IntMap.find i symbs
      
    let parse_rel symtab bs =
      bitmatch bs with
      { 
        r_offset : 32 : unsigned, littleendian;
        r_info   : 32 : unsigned, littleendian
      } ->
      let r_info = Int32.to_int r_info in
      let sindex = r_info lsr 8 in
      let r_type = r_info land 0xFF in
      {
        r_offset  = r_offset;
        r_symb    = parse_symbol symtab sindex;
        r_type    = parse_rtype r_type;
        r_addend  = None
      }

    let parse_rela symtab bs =
      bitmatch bs with
      { 
        r_offset : 32 : unsigned, littleendian;
        r_info   : 32 : unsigned, littleendian;
        r_addend : 32 : unsigned, littleendian
      } ->
      let r_info = Int32.to_int r_info in
      let sindex = r_info lsr 8 in
      let r_type = r_info land 0xFF in
      {
        r_offset  = r_offset;
        r_symb    = parse_symbol symtab sindex;
        r_type    = parse_rtype r_type;
        r_addend  = Some r_addend
      }
      
    let is_plt_reloc r = 
      r.r_type = R_386_JMP_SLOT

    let output_addend o = function
      | None   -> ()
      | Some i -> Printf.fprintf o "%8lx" i

    let string_of_raddend addend =
      match addend with
      | None   -> ""
      | Some i -> Printf.sprintf "%8lx" i

    let string_of_rentry { r_offset ; r_symb ; r_type ; r_addend } = 
      Printf.sprintf "%08lx %s %s %s (%s)" r_offset (string_of_rtype r_type)
                     (string_of_bitstring (r_symb.st_name))
                     (string_of_raddend r_addend)
                     (match r_symb.st_shndx with
                      | SHN_ABS -> "*ABS*"
                      | SHN_UNDEF -> "Trusted function"
                      | SHN_COMMON -> "*COM*"
                      | SHN i -> if r_symb.st_type = STT_FUNC
                                 then "Internal function"
                                 else if r_symb.st_type = STT_OBJECT
                                 then "Symbolic variable"
                                 else "*IN*"
                      | SHN_PROC i -> "*PROC*"
                      | SHN_RESERVE i -> "*RES*")
                
    let output_reloc o {r_offset; r_type;r_symb;r_addend} =
      Printf.fprintf o "%08lx %s %s %a %s" r_offset (string_of_rtype r_type)
                     (string_of_bitstring (r_symb.st_name))
                     output_addend r_addend
                     (match r_symb.st_shndx with
                      | SHN_ABS -> "*ABS*"
                      | SHN_UNDEF -> "Trusted function"
                      | SHN_COMMON -> "*COM*"
                      | SHN i -> if r_symb.st_type = STT_FUNC
                                 then "Internal function"
                                 else if r_symb.st_type = STT_OBJECT
                                 then "Symbolic variable"
                                 else "*IN*"
                      | SHN_PROC i -> "*PROC*"
                      | SHN_RESERVE i -> "*RES*")

    let make shdrs symtab bs =
      let rel = get_code_rel_section shdrs in
      let bs = dropbits ((Int32.to_int rel.sh_offset)*8) bs in
      let sz = Int32.to_int rel.sh_entsize in
      let nb = Int32.to_int rel.sh_size / sz in
      parse_array None (parse_rel symtab) nb sz bs
  end


let get_function_symbols (symtab: sym IntMap.t) : sym list = 
  List.sort
    (fun s t -> Int32.to_int s.st_value - Int32.to_int t.st_value)
    (IntMap.fold (fun k sym acc -> if sym.st_type = STT_FUNC then sym::acc else acc) symtab [])

let named_secs secs tbl =
  IntMap.map (fun sec -> {sec with sh_name = Strtab.find (Int32.to_int sec.sh_name) tbl}) secs
  
(** Main parsing function *)
  
let parse file =
  let chan= open_in_bin file in
  let bs = bitstring_of_chan chan in
  let header = parse_header bs in 
  Printf.fprintf stdout "Header:\n";
  Printf.fprintf stdout "%a\n" output_header header ; 
  let secs   = parse_shdrs header bs in 
  let tbl    = find_string_table header secs bs in
  let secs   = IntMap.map (fun sec -> 
                   {sec with sh_name = Strtab.find (Int32.to_int sec.sh_name) tbl}) secs in
  Printf.fprintf stdout "Sections:\n";
  IntMap.iter (fun _ sec-> 
      Printf.fprintf stdout "%a\n" (output_shdr output_bitstring) sec) secs; 
  let phdrs  = parse_phdrs header bs in
  Printf.fprintf stdout "Segments:\n";
  IntMap.iter (fun _ phdr-> Printf.fprintf stdout "%a\n" output_phdr phdr) phdrs; 
  let (symtab: sym IntMap.t) = parse_symtab secs bs in
  Printf.fprintf stdout "Symbols:\n";
  IntMap.iter (fun _ sym -> Printf.fprintf stdout "%a\n" (output_sym secs) sym) symtab ;
  let image = ProcImage.make secs bs in
  Printf.fprintf stdout "Functions:\n";
  List.iter (fun sym -> Printf.fprintf stdout "%a\n" (output_fun secs) sym)
            (get_function_symbols symtab) ;
  let relocs = Reloc.make secs symtab bs in
  Printf.fprintf stdout "Relocations:\n";
  IntMap.iter (fun _ reloc -> Printf.fprintf stdout "%a\n" Reloc.output_reloc reloc) relocs;

