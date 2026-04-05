#include "terminal.h"
// Terminal functions will go here
static int terminal_row;
static int terminal_column;
terminal_row = 0;
terminal_column = 0;
uint8_t terminal_color;
void terminal_setcolor(uint8_t color) {
    terminal_color = color;
}
