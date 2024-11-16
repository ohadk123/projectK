#include "kheaders/console.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_BUFFER ((uint16 *)0xB8000)

struct vga_console {
    uint8 x;
    uint8 y;
    uint8 color;
    uint16 *buffer;
} console;

void console_init() {
    console.color = VGA_ATTR(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    console.x = 0;
    console.y = 0;
    console.buffer = VGA_BUFFER;
    int max = VGA_WIDTH * VGA_HEIGHT;
    for (int i = 0; i < max; i++)
        console.buffer[i] = VGA_CHAR(' ', console.color);
}

void inline console_set_attr(uint8 fg, uint8 bg) {
    console.color = VGA_ATTR(fg, bg);
}

void inline console_putc_at(char c, uint8 x, uint8 y) {
    console.buffer[y * VGA_WIDTH + x] = VGA_CHAR(c, console.color);
}

void console_putc(char c) {
    switch (c) {
        case '\n':
            console.x = 0;
            if (++console.y == VGA_HEIGHT)
                console_clear();
            return;
        case '\r':
            console.x = 0;
            return;
        case '\t':
            console_puts("    ");
            return;
        default:
            console_putc_at(c, console.x, console.y);
            if (++console.x == VGA_WIDTH) {
                console.x = 0;
                if (++console.y == VGA_HEIGHT)
                    console_clear();
            }
    }
}

void console_write(const char* str, int len) {
    for (int i = 0; i < len; i++)
        console_putc(str[i]);
}

int console_strlen(const char* str) {
    int len = 0;
    while (str[len++]);
    return len-1;
}

void console_clear() {
    int max = VGA_WIDTH * VGA_HEIGHT;
    for (int i = 0; i < max; i++)
        console.buffer[i] = VGA_CHAR(' ', console.color);
    console.x = 0;
    console.y = 0;
}