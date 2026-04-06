#include "string.h"
#include "types.h"

void* memset(void* ptr, int value, int num) {
    unsigned char* p = ptr;
    while (num--) {
        *p++ = (unsigned char)value;
    }
    return ptr;
}
int strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
char* strcpy(char* dest, const char* src) {
    char* saved = dest;
    while ((*dest++ = *src++) != '\0');
    return saved;
}
void* memcpy(void* dest, const void* src, int num) {
    char* d = dest; const char* s = src;
    while (num--) *d++ = *s++;
    return dest;
}
