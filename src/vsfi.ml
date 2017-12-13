

Printf.printf "VSFI %s\n" Vsfi_ver.version_string;
if (Array.length Sys.argv < 2) then
    print_endline "Usage: vsfi elf [options]"
else
	begin
    if Array.length Sys.argv > 2 && Sys.argv.(2) = "--debug" then
	  Config.loglevel := 4
	end;
	begin
    if Array.length Sys.argv > 2 && Sys.argv.(2) = "--quiet" then
	  Config.loglevel := 2
	end;
    Main.process Sys.argv.(1);;
