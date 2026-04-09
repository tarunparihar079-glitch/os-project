#ifndef TERMINAL_H
#define TERMINAL_H
#include "types.h"

void terminal_initialize(void);
void update_cursor(int x, int y);
void terminal_writestring(const char* data);

#endif
