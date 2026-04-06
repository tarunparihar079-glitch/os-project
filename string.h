#ifndef STRING_H
#define STRING_H

void* memset(void* ptr, int value, int num);
int strcmp(const char* s1, const char* s2);
char* strcpy(char* dest, const char* src);
void itoa(int n, char* str);
void* memcpy(void* dest, const void* src, int num);
#endif
