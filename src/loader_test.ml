let elf_file = ref ""


             
let _ =
  let usage = Printf.sprintf "%s <elf-file>" Sys.argv.(0) in
  Arg.parse [] (fun s-> elf_file := s) usage ;
  if !elf_file = ""
  then failwith usage
  else Elf_info.parse !elf_file
