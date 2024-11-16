#include "kheaders/console.h"
#include "kheaders/int.h"
#include "kheaders/asm.h"

void main() {
    cli();
    console_init();
    idt_init();
    sti();
    console_puts("Hello, World!\n");
    int(0);
    cli();
    hlt();
}
