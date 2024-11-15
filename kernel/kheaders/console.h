#ifndef CONSOLE_H
#define CONSOLE_H

#include <libok/ktypes.h>

enum VGAColor {
    VGA_COLOR_BLACK,
    VGA_COLOR_BLUE,
    VGA_COLOR_GREEN,
    VGA_COLOR_CYAN,
    VGA_COLOR_RED,
    VGA_COLOR_MAGENTA,
    VGA_COLOR_BROWN,
    VGA_COLOR_LIGHT_GREY,
    VGA_COLOR_DARK_GREY,
    VGA_COLOR_LIGHT_BLUE,
    VGA_COLOR_LIGHT_GREEN,
    VGA_COLOR_LIGHT_CYAN,
    VGA_COLOR_LIGHT_RED,
    VGA_COLOR_LIGHT_MAGENTA,
    VGA_COLOR_LIGHT_BROWN,
    VGA_COLOR_WHITE
};

#define VGA_ATTR(fg, bg) (bg << 4) | fg
#define VGA_CHAR(c, attr) (uint16) c | (uint16) attr << 8

void console_init();
void console_set_attr(uint8 fg, uint8 bg);
void console_putc_at(char c, uint8 x, uint8 y);
void console_putc(char c);
void console_write(const char* str, int len);
int console_strlen(const char* str);
void console_clear();

#define console_puts(str) console_write(str, console_strlen(str))

#endif // CONSOLE_H