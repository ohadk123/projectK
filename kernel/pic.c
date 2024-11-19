#include "kheaders/asm.h"
#include "kheaders/pic.h"
#include "kheaders/int.h"
#include "kheaders/console.h"
#include "kheaders/isr.h"
#include <libok/ktypes.h>

extern struct idt_desc idt[];

void pic_init() {
    // ICW1
	outb(PICM_COM, 0x11);
	outb(PICS_COM, 0x11);

    // ICW2
	outb(PICM_DATA, IRQ0);
	outb(PICS_DATA, IRQ8);

    // ICW3
	outb(PICM_DATA, 0x04);
	outb(PICS_DATA, 0x02);
	
    // ICW4
	outb(PICM_DATA, 0x01);
	outb(PICS_DATA, 0x01);

	set_int(&idt[TIMER_IRQ], (void *) isr_timer, INT_GATE_32, 0);
    set_int(&idt[KEYBOARD_IRQ], (void *) isr_keyboard, INT_GATE_32, 0);
}

void timer_handler() {
	console_puts("timer tick\n");
}

void keyboard_handler() {
    console_puts("keyboard pressed\n");
}