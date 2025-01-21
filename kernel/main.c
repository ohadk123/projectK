#include "kheaders/console.h"
#include "kheaders/int.h"
#include "kheaders/asm.h"
#include "kheaders/pic.h"

void main() {
    console_init();
    idt_init();
    int(0x20);
    pic_init();
    int(0x20);
    sti();
    console_puts("Hello, World!\n");
    cli();
    hlt();
}
