#include "io.h"
#include "terminal.h"

static int terminal_row;
static int terminal_column;
uint8_t terminal_color;

void update_cursor(int x, int y) {
    uint16_t pos = y * 80 + x;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void terminal_initialize(void) {
    terminal_row = 0;
    terminal_column = 0;
    uint16_t* terminal_buffer = (uint16_t*) 0xB8000;
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            const int index = y * 80 + x;
            terminal_buffer[index] = (uint16_t) ' ' | (uint16_t) 15 << 8;
        }
    }
    update_cursor(0, 0);
}

void terminal_putchar(char c) {
    uint16_t* terminal_buffer = (uint16_t*) 0xB8000;
    
    if (c == '\n') {
        terminal_column = 0;
        terminal_row++;
        update_cursor(terminal_column, terminal_row);
        return;
    }
    // Backspace logic
    if (c == '\b') {
        if (terminal_column > 0) {
            terminal_column--;
        } else if (terminal_row > 0) {
            terminal_row--;
            terminal_column = 79;
        }
        const int index = terminal_row * 80 + terminal_column;
        terminal_buffer[index] = (uint16_t) ' ' | (uint16_t) 15 << 8;
        update_cursor(terminal_column, terminal_row);
        return;
    }
    
    const int index = terminal_row * 80 + terminal_column;
    terminal_buffer[index] = (uint16_t) c | (uint16_t) 15 << 8;
    terminal_column++;
    if(terminal_column >= 80) { 
        terminal_column = 0; 
        terminal_row++; 
    }
    update_cursor(terminal_column, terminal_row);
}

void terminal_writestring(const char* data) {
    for (int i = 0; data[i] != '\0'; i++) {
        terminal_putchar(data[i]);
    }
}
