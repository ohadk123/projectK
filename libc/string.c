#include <string.h>
#include <libok/ktypes.h>

void *memset(void *s, int c, size_t n) {
    uint8 *p = s;
    while (n--)
        *p++ = (uint8) c;
    return s;
}