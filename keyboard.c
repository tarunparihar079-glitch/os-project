#include "keyboard.h"
#include "io.h"
#include "shell.h"

void init_keyboard() {
}

const char kbd_us[128] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n'
};

void keyboard_handler() {
    uint8_t scancode = inb(0x60);
    if (!(scancode & 0x80)) {
        char c = kbd_us[scancode];
        if (c != 0) {
            shell_input(c);
        }
    }
}
