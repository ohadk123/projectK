#include "kheaders/console.h"
#include "kheaders/int.h"
#include "kheaders/asm.h"
#include "kheaders/pic.h"

void main() {
    console_init();
    idt_init();
    pic_init();
    sti();
    console_puts("Hello, World!\n");
    int(0x20);
    int(0x21);
    int(0x21);
    int(0x22);
    cli();
    hlt();
}
