#include "string.h"
#include "shell.h"
#include "terminal.h"
char cmd_buffer[256];
int cmd_idx = 0;
void shell_input(char c) {
    if (cmd_idx < 255 && c != '\b') {
        cmd_buffer[cmd_idx++] = c;
    }
    if (c == '\n') {
        execute_command();
    }
}
void execute_command() {
    cmd_buffer[cmd_idx] = '\0'; // End string
    if (strcmp(cmd_buffer, "help") == 0) {
        terminal_writestring("\nCommands: help, clear");
    } else if (strcmp(cmd_buffer, "clear") == 0) {
        // Clear logic will trigger here
    } else if (cmd_idx > 0) {
        terminal_writestring("\nUnknown command");
    }
    cmd_idx = 0; // Reset buffer
    terminal_writestring("\nFirstOS/Users> ");
}
