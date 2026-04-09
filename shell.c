#include "shell.h"
#include "terminal.h"
#include "string.h"
#include "io.h"

char cmd_buffer[256];
int cmd_idx = 0;

void execute_command() {
    cmd_buffer[cmd_idx] = '\0';
    
    if (strcmp(cmd_buffer, "help") == 0) {
        terminal_writestring("\nCommands [1-10]: help, clear, about, version, whoami, ping, pwd, ls, hello, exit");
        terminal_writestring("\nCommands [11-20]: reboot, halt, fetch, date, time, author, joke, matrix, secret, credits");
    } else if (strcmp(cmd_buffer, "clear") == 0) {
        terminal_initialize();
        cmd_idx = 0;
        terminal_writestring("FirstOS/root> ");
        return;
    } else if (strcmp(cmd_buffer, "about") == 0) {
        terminal_writestring("\nFirstOS - A Custom 32-bit Kernel built from scratch.");
    } else if (strcmp(cmd_buffer, "version") == 0) {
        terminal_writestring("\nFirstOS v1.0.0 (Stable Release)");
    } else if (strcmp(cmd_buffer, "whoami") == 0) {
        terminal_writestring("\nroot (Superuser / Administrator)");
    } else if (strcmp(cmd_buffer, "ping") == 0) {
        terminal_writestring("\npong! Network is offline, but I'm here.");
    } else if (strcmp(cmd_buffer, "pwd") == 0) {
        terminal_writestring("\n/home/FirstOS/root");
    } else if (strcmp(cmd_buffer, "ls") == 0) {
        terminal_writestring("\nboot.asm   kernel.c   shell.c   FirstOS.bin   README.md");
    } else if (strcmp(cmd_buffer, "hello") == 0) {
        terminal_writestring("\nHello, Developer! Welcome to your custom Operating System.");
    } else if (strcmp(cmd_buffer, "reboot") == 0) {
        terminal_writestring("\nRebooting system...");
        outb(0x64, 0xFE);
    } else if (strcmp(cmd_buffer, "halt") == 0) {
        terminal_writestring("\nSystem halted. CPU is frozen. Please close QEMU.");
        asm volatile("cli; hlt");
    } else if (strcmp(cmd_buffer, "fetch") == 0) {
        terminal_writestring("\n   ___ _        _    ___  __ ");
        terminal_writestring("\n  / __(_)_ _ __| |_ / _ \\/ / ");
        terminal_writestring("\n | _|| | '_(_-<  _| (_) \\ \\  ");
        terminal_writestring("\n |_| |_|_| /__/\\__|\\___/___/ ");
        terminal_writestring("\n-----------------------------");
        terminal_writestring("\n OS     : FirstOS v1.0");
        terminal_writestring("\n Kernel : Custom 32-bit Bare-Metal");
        terminal_writestring("\n Memory : 16 KB Stack Setup");
    } else if (strcmp(cmd_buffer, "date") == 0) {
        terminal_writestring("\nDate: 09 April 2026 (Simulated)");
    } else if (strcmp(cmd_buffer, "time") == 0) {
        terminal_writestring("\nTime is an illusion. (CMOS RTC driver not installed yet)");
    } else if (strcmp(cmd_buffer, "author") == 0) {
        terminal_writestring("\nDeveloped by the FirstOS Core Team.");
    } else if (strcmp(cmd_buffer, "joke") == 0) {
        terminal_writestring("\nWhy do programmers prefer dark mode?\nBecause light attracts bugs!");
    } else if (strcmp(cmd_buffer, "matrix") == 0) {
        terminal_writestring("\n01010011 01111001 01110011 01110100 01100101 01101101 00100000");
    } else if (strcmp(cmd_buffer, "secret") == 0) {
        terminal_writestring("\nAccess Granted! You found the hidden Easter Egg!");
    } else if (strcmp(cmd_buffer, "credits") == 0) {
        terminal_writestring("\nSpecial thanks to the Open Source Community.");
    } else if (strcmp(cmd_buffer, "exit") == 0) {
        terminal_writestring("\nYou cannot exit. You are trapped in FirstOS forever!");
    } else if (cmd_idx > 0) {
        terminal_writestring("\nCommand not found: '");
        terminal_writestring(cmd_buffer);
        terminal_writestring("'. Type 'help' for a list.");
    }
    
    cmd_idx = 0;
    terminal_writestring("\nFirstOS/root> ");
}

void shell_input(char c) {
    if (c == '\n') {
        execute_command();
    } else if (c == '\b') {
        if (cmd_idx > 0) {
            cmd_idx--;
            terminal_putchar('\b');
        }
    } else if (cmd_idx < 255) {
        cmd_buffer[cmd_idx++] = c;
        terminal_putchar(c);
    }
}
