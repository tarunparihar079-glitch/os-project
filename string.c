#include "string.h"
#include "types.h"

void* memset(void* ptr, int value, int num) {
    unsigned char* p = ptr;
    while (num--) {
        *p++ = (unsigned char)value;
    }
    return ptr;
}
