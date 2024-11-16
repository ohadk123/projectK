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

/**
 * Initializes the console
 */
void console_init();

/**
 * Sets the foreground and background colors of the console
 * @param fg The foreground color
 * @param bg The background color
 */
void console_set_attr(uint8 fg, uint8 bg);

/**
 * Prints a character at the specified position in the console
 * @param x The horizontal position
 * @param y The vertical position
 */
void console_putc_at(char c, uint8 x, uint8 y);

/**
 * Prints a charater at the current cursor position
 * @param c The character to print
 */
void console_putc(char c);

/**
 * Prints len characters from a string to the console
 * @param str The string to print
 * @param len The number of characters to print
 */
void console_write(const char* str, int len);

/**
 * Counts the number of characters in a string
 * @param str The string to count
 * @return The number of characters in the string
 */
int console_strlen(const char* str);

/**
 * Clears the console
 */
void console_clear();

/**
 * Prints a string to the console
 * @param str The string to print
 */
#define console_puts(str) console_write(str, console_strlen(str))

#endif // CONSOLE_H