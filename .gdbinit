define hook-stop
	printf "[%4x:%4x] ", $cs, $eip
	x/i $cs*16+$eip
end

set architecture i8086
target remote localhost:26000
set disassembly-flavor intel
layout asm
layout reg
b *0x7c00
