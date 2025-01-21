#ifndef ASM_H
#define ASM_H

#include <libok/ktypes.h>

#define cli() asm volatile("cli")
#define sti() asm volatile("sti")

#define inb(buffer, port) asm volatile("inb %1, %0" : "=a"(buffer) : "Nd"(port))
#define inw(buffer, port) asm volatile("inw %1, %0" : "=a"(buffer) : "Nd"(port))
#define inl(buffer, port) asm volatile("inl %1, %0" : "=a"(buffer) : "Nd"(port))

#define outb(port, data) asm volatile("outb %0, %1" : : "a"((uint8) data), "Nd"(port))
#define outw(port, data) asm volatile("outw %0, %1" : : "a"((uint16) data), "Nd"(port))
#define outl(port, data) asm volatile("outl %0, %1" : : "a"((uint32) data), "Nd"(port))

#define int(offset) asm volatile("int %0" :: "i"(offset))
#define hlt() asm volatile("hlt")

#define io_wait() outb(0x80, 0)

#endif
