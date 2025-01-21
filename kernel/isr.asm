; Defines a macro to create interrup handlers
; some assembly code is needed before jumping into a interrupt function
; ISR - Interrupt Service Routine
; The C function must be named '<something>_handler' accepts no arguments and returns void
; 'isr_<name>' will be the name of the int service routine
; After creating the C function called '<name>_handler', you must add the line 'ISR <name>' here, and declare it in isr.h 
; Example:
; C: void placeholder_handler()
; isr.asm: ISR placeholder
; isr.h: extern void isr_placeholder()
; C: set_int(&idt[index], (void *) isr_placeholder, INT_GATE_32, 0)

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
ISR empty
ISR keyboard