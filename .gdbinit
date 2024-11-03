# source ~/.gef-2024.06.py

define hook-stop
	printf "[%4x:%4x] ", $cs, $eip
	x/i $cs*16+$eip
end

set architecture i8086
set disassembly-flavor intel
symbol-file build/kernel/kernel
layout src
b main
target remote localhost:26000