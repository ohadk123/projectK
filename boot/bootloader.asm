[ BITS 16 ]
start: jmp boot
; 
;************************************************
; Memory Layout:
; 0x00000500 - 0x00007BFF     Stack       (29.75 KB)
; 0x00007C00 - 0x00007DFF     Bootloader  (512 Bytes)
; 0x00007E00 - 0x0007FFFF     Kernel      (480.5 KB)
;************************************************
%define KERNSECT 0x7E0

; Boot process starts here, with a simple message
boot:
	cli
	mov si, boot_msg
	call print

; Read the kernel from the disk
read_kern:
	mov ax, KERNSECT
	mov es, ax
	xor bx, bx
	mov al, 2	; read 2 sectors
	mov ch, 0	; track 0
	mov cl, 2	; from sector 2
	mov dh, 0	; head 0
	mov dl, 0	; first floppy
	mov ah, 0x02
	int 0x13
	jc read_kern

; Enable A20 line
enable_a20:
	in al, 0x92
	test al, 2
	jnz after
	or al, 2
	and al, 0xFE
	out 0x92, al
after:

; Set VGA 80x25 video mode
set_vga:
	mov ah, 0x00
	mov al, 0x03
	int 0x10

; Configure the stack
set_stack:
	mov ax, 0x00
	mov ss, ax
	mov ax, 0x7C00
	mov sp, ax

load_gdt:
	cli			; Can never be too sure
	lgdt [gdtr]
; Enter protected mode
enter_pm:
	mov eax, cr0
	or al, 1
	mov cr0, eax

	jmp 0x08:load_seg

[ BITS 32 ]
; Load the data segments to the kernel's data segments descriptor
load_seg:
	mov ax, 0x10
	mov ds, ax
	mov es, ax

; Jump to the kernel
movek:
	jmp [0x7E00 + 0x18]
halt:
	cli
	hlt

[ BITS 16 ]
;************************************************
; Prints a string
; si - Pointer to the string
;************************************************
print:
	mov al, [si]
	cmp al, 0
	je done
	mov ah, 0x0E
	xor bx, bx
	int 0x10
	inc si
	jmp print
done:
	ret

boot_msg:
	db "Welcome to my Operating System!", 0x0A, 0x0D, 0x00

;************************************************
; Global Descriptor Table
; 0x00 - Null Segment
; 0x08 - Kernel Code Segment
; 0x10 - Kernel Data Segment
;************************************************
gdt:
	; null
	dd 0x00000000
	dd 0x00000000

	; kernel code
	dd 0x0000FFFF
	dd 0x00CF9A00

	; kernel data
	dd 0x0000FFFF
	dd 0x008F9200

gdtr:
	dw gdtr - gdt - 1
	dd gdt

times 510 - ($ - $$) db 0
dw 0xAA55
