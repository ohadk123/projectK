#ifndef CONSOLE_H
#define CONSOLE_H

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_BUFFER ((uint16 *)0xB8000)

#include <stdint.h>

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

struct VGAConsole {
    uint8 x;
    uint8 y;
    uint8 color;
    uint16 *buffer;
};

#define VGA_ATTR(fg, bg) (bg << 4) | fg
#define VGA_CHAR(c, attr) (uint16) c | (uint16) attr << 8

void consoleInit();
void consoleSetAttr(uint8 fg, uint8 bg);
void consolePutCharAt(char c, uint8 x, uint8 y);
void consolePutChar(char c);
void consoleWrite(const char* str, int len);
int consoleStrLen(const char* str);
void consoleClear();

#define consoleWriteStr(str) consoleWrite(str, consoleStrLen(str))

#endif // CONSOLE_H