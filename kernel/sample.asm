org 0x7e00
bits 16

start:
	mov si, msg
	call print
	cli
	hlt

print:
	mov al, [si]
	cmp al, 0
	je done
	mov ah, 0x0e
	xor bx, bx
	int 0x10
	inc si
	jmp print
done:
	ret

msg: db "Welcome from Kernel", 0x0a, 0x0d, 0x00
