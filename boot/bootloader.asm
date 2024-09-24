org 0x7C00
bits 16
start: jmp boot
; 
;************************************************
; Memory Layout:
; 0x00000500 - 0x00007BFF     Stack       (29.75 KB)
; 0x00007C00 - 0x00007DFF     Bootloader  (512 Bytes)
; 0x00007E00 - 0x0007FFFF     Kernel      (480.5 KB)
;************************************************
%define BOOTSECT 0x7C0
%define KERNSECT 0x7E0
%define STACKSECT 0x50

boot_msg:
	db "Welcome to my Operating System!", 0x0A, 0x0D, 0x00
belowMB: 
	db 0
overMB:
	db 0

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

; Check if the a20 line is enabled
check_a20:
	mov ax, 0x0000
	mov fs, ax
	mov si, 0x500
	mov al, [fs:si]
	mov [belowMB], al

	mov ax, 0xffff
	mov gs, ax
	mov di, 0x510
	mov al, [gs:di]
	mov [overMB], al

	xor ax, ax
	mov byte [fs:si], 0x00
	mov byte [gs:di], 0x01
	mov al, [gs:si]
	cmp al, [fs:di]
	jne after_a20

; If not, enable the a20 line
enable_a20:
	call busy_a20
	mov al, 0xD1
	out 0x64, al
	call busy_a20
	mov al, 0xDF
	out 0x64, al
	call busy_a20
	call check_a20

; Restore the values in memory
after_a20:
	mov al, [belowMB]
	mov [fs:si], al
	mov al, [overMB]
	mov [gs:di], al

; Configure the stack
set_stack:
	mov ax, STACKSECT
	mov ss, ax
	mov ax, BOOTSECT - (STACKSECT * 0x10)
	mov sp, ax

; Load the GDT, nothing much
load_gdt:
	lgdt [gdtr]
	jmp 0x08:load_seg
	
; Load the data segments to the kernel's data segments descriptor
load_seg:
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

; Enter protected mode
enter_pm:
	mov eax, cr0
	or eax, 0x01
	mov cr0, eax

; Jump to the kernel
	jmp KERNSECT:0x00

	cli
	hlt

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

busy_a20:
	in al, 0x64
	test al, 0x02
	jnz busy_a20
	ret

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
  dw 0xFFFF
  dw 0x0000
  db 0b10011010
  db 0b11001111
  db 0x00

  ; kernel data
  dw 0xFFFF
  dw 0x0000
  db 0b10010010
  db 0b11001111
  db 0x00

gdtr:
  dw gdtr - gdt - 1
  dd gdt

times 510 - ($ - $$) db 0
dw 0xAA55
