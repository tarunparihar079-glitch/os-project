#include "shell.h"
#include "terminal.h"
char cmd_buffer[256];
int cmd_idx = 0;
void shell_input(char c) {
    if (cmd_idx < 255 && c != '\b') {
        cmd_buffer[cmd_idx++] = c;
    }
}
