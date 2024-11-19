%macro ISR 1
extern %1_handler
global isr_%1
isr_%1:
    cli
    pusha
    call %1_handler
    popa
    sti
    mov al, 0x20
    out 0x20, al
    iret
%endmacro

ISR placeholder
ISR timer
ISR keyboard