#ifndef INT_H
#define INT_H

#include "config.h"

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

void set_int(struct idt_desc *desc, void *handler, int type, int dpl);
void idt_init();

void placeholder_handler();

#endif // INT_H
