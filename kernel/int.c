#include <libok/ktypes.h>
#include <string.h>
#include "kheaders/config.h"
#include "kheaders/console.h"

#define TASK_GATE 0x5
#define INT_GATE_16 0x6
#define TRAP_GATE_16 0x7
#define INT_GATE_32 0xe
#define TRAP_GATE_32 0xf

struct idt_desc {
    uint16 offset_low;
    uint16 selector;
    uint8 zero;
    uint8 attr;
    uint16 offset_high;
} __attribute__((packed));
struct idt_desc idt[IDT_ENTRIES];

#define IDT_ATTR(type, dpl) (0x80 | dpl << 5 | type)
#define INT_ADD(index, off, type, dpl) \
    idt[index].offset_low = (uint32) off & 0xffff, \
    idt[index].selector = CODE_S, \
    idt[index].zero = 0, \
    idt[index].attr = IDT_ATTR(type, dpl), \
    idt[index].offset_high = (uint32) off >> 16

struct idtr {
    uint16 limit;
    uint32 base;
} __attribute__((packed));
struct idtr idtreg;

void placeholder() {
    console_puts("Place Holder Interrupt\n");
}

union desc_val {
    struct idt_desc desc;
    uint64 val;
};

void idt_init() {
    struct idt_desc defint = {
        .offset_low = ((uint32) placeholder) & 0xffff,
        .selector = CODE_S,
        .zero = 0,
        .attr = IDT_ATTR(INT_GATE_32, 0),
        .offset_high = ((uint32) placeholder) >> 16
    };

    for (int i = 0; i < IDT_ENTRIES; i++)
        idt[i] = defint;

    idtreg.limit = sizeof(idt) - 1;
    idtreg.base = (uint32) idt;
    asm volatile("lidt %0" :: "m"(idtreg));
}