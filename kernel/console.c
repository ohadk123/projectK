#include <console.h>


struct VGAConsole console;

void consoleInit() {
    console.color = VGA_ATTR(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    console.x = 0;
    console.y = 0;
    console.buffer = VGA_BUFFER;
    int max = VGA_WIDTH * VGA_HEIGHT;
    for (int i = 0; i < max; i++)
        console.buffer[i] = VGA_CHAR(' ', console.color);
}

void inline consoleSetAttr(uint8 fg, uint8 bg) {
    console.color = VGA_ATTR(fg, bg);
}

void consolePutCharAt(char c, uint8 x, uint8 y) {
    int i = y * VGA_WIDTH + x;
    console.buffer[i] = VGA_CHAR(c, console.color);
}

void consolePutChar(char c) {
    consolePutCharAt(c, console.x, console.y);
    if (++console.x == VGA_WIDTH) {
        console.x = 0;
        if (++console.y == VGA_HEIGHT)
            console.y = 0;
    }
}

void consoleWrite(const char* str, int len) {
    for (int i = 0; i < len; i++)
        consolePutChar(str[i]);
}

int consoleStrLen(const char* str) {
    int len = 0;
    while (str[len++]);
    return len;
}

void consoleClear() {
    int max = VGA_WIDTH * VGA_HEIGHT;
    for (int i = 0; i < max; i++)
        console.buffer[i] = VGA_CHAR(' ', console.color);
        console.x = 0;
        console.y = 0;
}