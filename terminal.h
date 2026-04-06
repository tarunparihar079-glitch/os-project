#ifndef TERMINAL_H
#define TERMINAL_H
#include "types.h"
#define VGA_ADDRESS 0xB8000
void terminal_setcolor(uint8_t color);
void update_cursor(int x, int y);
#endif
