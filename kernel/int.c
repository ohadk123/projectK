#include <libok/ktypes.h>
#include <string.h>
#include "kheaders/int.h"
#include "kheaders/console.h"
#include "kheaders/isr.h"

struct idt_desc idt[IDT_ENTRIES];

struct idtr {
    uint16 limit;
    uint32 base;
} __attribute__((packed));
struct idtr idtreg;

void set_int(struct idt_desc *desc, void *handler, int type, int dpl) {
    desc->offset_low = (uint32) handler & 0xffff;
    desc->selector = CODE_S;
    desc->zero = 0;
    desc->attr = (0x80 | dpl << 5 | type);
    desc->offset_high = (uint32) handler >> 16;
}

void idt_init() {
    struct idt_desc defint;
    set_int(&defint, (void *) isr_placeholder, INT_GATE_32, 0);

    for (int i = 0; i < IDT_ENTRIES; i++)
        idt[i] = defint;

    idtreg.limit = sizeof(idt) - 1;
    idtreg.base = (uint32) idt;
    asm volatile("lidt %0" :: "m"(idtreg));
}

void placeholder_handler() {
    console_puts("Place Holder Interrupt\n");
}