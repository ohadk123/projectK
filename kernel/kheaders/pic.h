#ifndef PIC_H
#define PIC_H

#define PICM_COM 0x20
#define PICM_DATA 0x21
#define PICS_COM 0xA0
#define PICS_DATA 0xA1

#define IRQ0 0x20
#define IRQ1 0x21
#define IRQ2 0x22
#define IRQ3 0x23
#define IRQ4 0x24
#define IRQ5 0x25
#define IRQ6 0x26
#define IRQ7 0x27
#define IRQ8 0x28
#define IRQ9 0x29
#define IRQ10 0x2A
#define IRQ11 0x2B
#define IRQ12 0x2C
#define IRQ13 0x2D
#define IRQ14 0x2E
#define IRQ15 0x2F

#define TIMER_IRQ IRQ0
#define KEYBOARD_IRQ IRQ1
#define SERIAL2_IRQ IRQ3
#define SERIAL1_IRQ IRQ4
#define PARALLEL2_IRQ IRQ5
#define FLOPPY_IRQ IRQ6
#define PARALLEL1_IRQ IRQ7
#define RTC_IRQ IRQ8
#define MOUSE_IRQ IRQ12
#define FPU_IRQ IRQ13
#define HDD_IRQ IRQ14

void pic_init();

void timer_handler();
void keyboard_handler();

#endif