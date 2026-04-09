#include "io.h"
#include "shell.h"

// Standard US Keyboard Layout Map
const char kbd_us[128] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
};

// Polling function
void check_keyboard() {
    if (inb(0x64) & 1) { // Check if data is available
        uint8_t scancode = inb(0x60); // Read the key
        if (!(scancode & 0x80)) { // If it's a key PRESS (not release)
            char c = kbd_us[scancode];
            if (c != 0) {
                shell_input(c); // Send to shell
            }
        }
    }
}
