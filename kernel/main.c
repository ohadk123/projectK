#include "kheaders/console.h"

void main() {
    consoleInit();
    consoleWriteStr("Hello World");
    consoleClear();
    consoleWriteStr("This is a kernel");
    for(;;);
}
