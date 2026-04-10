#include "string.h"
#include "types.h"

void* memset(void* ptr, int value, int num) {
    unsigned char* p = ptr;
    while (num--) *p++ = (unsigned char)value;
    return ptr;
}

int strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) { s1++; s2++; }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

int strncmp(const char* s1, const char* s2, int n) {
    while (n && *s1 && (*s1 == *s2)) { ++s1; ++s2; --n; }
    if (n == 0) return 0;
    return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

char* strcpy(char* dest, const char* src) {
    char* saved = dest;
    while ((*dest++ = *src++) != '\0');
    return saved;
}

void itoa(int n, char* str) {
    int i = 0;
    if(n == 0) { str[0] = '0'; str[1] = '\0'; return; }
    while (n > 0) { str[i++] = (n % 10) + '0'; n /= 10; }
    str[i] = '\0';
}
