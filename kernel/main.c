#include "kheaders/console.h"
#include "kheaders/int.h"

void main() {
    console_init();
    idt_init();
    __asm__("int $0");
    __asm__("int $8");
    __asm__("int $100");
    __asm__("int $3");
    for(;;);
}
