#include "io.h"
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
void update_cursor(int x, int y) {
    uint16_t pos = y * 80 + x;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}
