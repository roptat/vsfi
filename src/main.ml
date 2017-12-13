open Bitstring
open Int32

module L = Log.Make(struct let name = "main" end)

class oracle =
  object
    method value_of_register (r: Register.t): Z.t =
      match Register.name r with
      | "cs" -> Z.of_int 0x1b
      | "ds" -> Z.of_int 0x23
      | "ss" -> Z.of_int 0x23
      | "es" -> Z.of_int 0x23
      | "fs" -> Z.of_int 0x3b
      | "gs" -> Z.of_int 0x00
      | _ -> failwith "Not a segment register"
  end

let generate_domain =
  let module Vector     = Vector.Make                     in
  let module SymbDom     = Symbdom.Make(Vector)             in
  let module Dom         = EnvDom.Make(SymbDom) in
  (module Dom: Envdomain.T)

let analyze bs relocs f =
  let module Domain      = (val generate_domain : Envdomain.T) in
  let module Inter = Interpreter.Make(Domain)         in
  let module Decoder = Decoder.Make in
  let module IntMap = Elf_info.IntMap in
  let (start, finish, f) = f in
  L.info (fun m -> m "Analyzing [%x:%x] %s..." start finish (string_of_bitstring f.Elf_info.st_name));
  let code = Decoder.prog_from_bitstring (dropbits (start*8) bs) relocs start finish (new oracle) (Data.Address.of_word (Data.Word.of_int (Z.of_int start) 32)) in
  let module Vector     = Vector.Make                     in
  let module SymbDom     = Symbdom.Make(Vector)             in
  (*IntMap.iter (fun (addr: int) (code: Asm.stmt list) ->
                                 Printf.fprintf stdout "%x: %s\n" addr
                                 (List.fold_left (fun (acc: string) (code: Asm.stmt) ->
                                                   Printf.sprintf "%s ; %s" (Asm.string_of_stmt code true) acc)
                                                 "" code)) code;*)
  (*let min = SymbDom.of_word (Data.Word.of_int (Z.of_int 15) 33) in
  let eax = SymbDom.top 8 in
  L.info (fun m -> m "%s - %s =" (SymbDom.to_string eax) (SymbDom.to_string min));
  L.info (fun m -> m "%s" (SymbDom.to_string (SymbDom.binop Asm.Sub (SymbDom.unop (Asm.ZeroExt 33) eax) min)));*)
  (*let addr = (21, (Interpreter.Cond (0, true, Interpreter.Stmt 0))) in
  let four = SymbDom.of_word (Data.Word.of_int (Z.of_int 4) 32) in
  let zero = SymbDom.of_word (Data.Word.of_int (Z.of_int 0) 32) in
  L.info (fun m -> m "%s" (SymbDom.to_string (SymbDom.binop Asm.Add (SymbDom.binop Asm.Sub zero four) four)));
  L.info (fun m -> m "%s" (Asm.string_of_stmt (Inter.stmt_at code addr) true));
  L.info (fun m -> m "%s" (Interpreter.string_of_addr (Inter.next_addr code addr)));*)
  Interpreter.LexicoMap.iter (fun key value -> ())
            (Inter.do_it code (start, (Interpreter.Stmt 0)) (Asm.T Decoder.esp))


let init_gdt () =
  (*Linux 32-bits*)
  Hashtbl.replace Config.gdt (Z.of_int 1) (Z.of_string "0x00cf9b000000ffff");
  Hashtbl.replace Config.gdt (Z.of_int 2) (Z.of_string "0x00cf93000000ffff");
  Hashtbl.replace Config.gdt (Z.of_int 3) (Z.of_string "0x00cffb000000ffff");
  Hashtbl.replace Config.gdt (Z.of_int 4) (Z.of_string "0x00cff3000000ffff");
  Hashtbl.replace Config.gdt (Z.of_int 5) (Z.of_string "0x80008b04200020ab");
  Hashtbl.replace Config.gdt (Z.of_int 6) (Z.of_string "0xffc093dff0000001");
  Hashtbl.replace Config.gdt (Z.of_int 7) (Z.of_string "0x0040f30000000fff");
  Hashtbl.replace Config.gdt (Z.of_int 8) (Z.of_string "0x0000f2000400ffff")

let process elffile =
  init_gdt () ;
  L.info (fun m -> m "VSFI version %s" Vsfi_ver.version_string);
  let chan= open_in_bin elffile in
  let bs = bitstring_of_chan chan in
  let header = Elf_info.parse_header bs in 
  let secs   = Elf_info.parse_shdrs header bs in 
  let tbl    = Elf_info.find_string_table header secs bs in
  let secs   = Elf_info.named_secs secs tbl in
  let phdrs  = Elf_info.parse_phdrs header bs in
  let symtab = Elf_info.parse_symtab secs bs in
  let image  = Elf_info.ProcImage.make secs bs in
  let relocs = Elf_info.Reloc.make secs symtab bs in
  let functions = Elf_info.get_function_symbols symtab in
  let text_section = Elf_info.get_code_section secs in
  let text_size = Int32.to_int text_section.Elf_info.sh_size in
  let text_off = Int32.to_int text_section.Elf_info.sh_offset in
  let functions = List.fold_left (fun acc f ->
        match acc with
        | [] -> (0, text_size, f) :: []
        | (a, b, f') :: rest -> (Int32.to_int f.Elf_info.st_value, text_size, f) ::
                                (a, Int32.to_int f.Elf_info.st_value - 1, f') ::
                                rest) [] functions in
  L.info (fun m -> m "Header of \"%s\" successfully decoded: %d functions to analyze." elffile (List.length functions));
  List.iter (fun f -> analyze (dropbits (text_off * 8) bs) relocs f) (List.rev functions);
  L.info (fun m -> m "Result: Pass")
