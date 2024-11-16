#ifndef ASM_H
#define ASM_H

#include <libok/ktypes.h>

#define cli() asm volatile("cli")
#define sti() asm volatile("sti")

#define inb(buffer, port) asm ("inb %1, %0" : "=a"(buffer) : "Nd"(port))
#define inw(buffer, port) asm ("inw %1, %0" : "=a"(buffer) : "Nd"(port))
#define inl(buffer, port) asm ("inl %1, %0" : "=a"(buffer) : "Nd"(port))

#define outb(port, data) asm ("outb %0, %1" : : "a"((uint8) data), "Nd"(port))
#define outw(port, data) asm ("outw %0, %1" : : "a"((uint16) data), "Nd"(port))
#define outl(port, data) asm ("outl %0, %1" : : "a"((uint32) data), "Nd"(port))

#endif
