#include <console.h>

void main() {
    consoleInit();
    consoleWriteStr("Hello World");
    consoleWriteStr("   This is a kernel");
    for(;;);
}
