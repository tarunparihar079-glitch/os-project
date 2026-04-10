#include "shell.h"
#include "terminal.h"
#include "string.h"
#include "io.h"

char cmd_buffer[256];
int cmd_idx = 0;

#define MAX_ITEMS 10
char fs_names[MAX_ITEMS][32];
char fs_data[MAX_ITEMS][128];
int fs_type[MAX_ITEMS]; 
char current_path[64] = "/home/Raghvendra";

char* get_arg(char* cmd, int skip) {
    return (cmd + skip);
}

void execute_command() {
    cmd_buffer[cmd_idx] = '\0';
    
    if (strcmp(cmd_buffer, "show-guide") == 0) {
        terminal_writestring("\nGuide: show-guide, wipe-screen, say <txt>, set-theme <col>\nInfo: sys-user, sys-info, sys-ver, time-check, up-stats, ram-check\nPath: curr-path, nav-to <dir>, create-folder <dir>, list-items\nFiles: create-file <name>, destroy <name>, write-file <name> <txt>, read-file <name>\nPower: power-cycle, halt-sys");
    } else if (strcmp(cmd_buffer, "wipe-screen") == 0) {
        terminal_initialize();
        cmd_idx = 0;
        terminal_writestring("FirstOS/Raghvendra> ");
        return;
    } else if (strncmp(cmd_buffer, "say ", 4) == 0) {
        terminal_writestring("\n");
        terminal_writestring(get_arg(cmd_buffer, 4));
    } else if (strncmp(cmd_buffer, "set-theme ", 10) == 0) {
        char* color = get_arg(cmd_buffer, 10);
        if (strcmp(color, "green") == 0) terminal_setcolor(2);
        else if (strcmp(color, "red") == 0) terminal_setcolor(4);
        else terminal_writestring("\nAvailable themes: green, red");
    } else if (strcmp(cmd_buffer, "sys-user") == 0) {
        terminal_writestring("\nAdmin: Raghvendra is using the system.");
    } else if (strcmp(cmd_buffer, "sys-info") == 0) {
        terminal_writestring("\nArchitecture: Bare Metal x86");
    } else if (strcmp(cmd_buffer, "sys-ver") == 0) {
        terminal_writestring("\nFirstOS Version: 1.0.0");
    } else if (strcmp(cmd_buffer, "time-check") == 0) {
        terminal_writestring("\nSystem Time: 12:45 PM (Simulated)");
    } else if (strcmp(cmd_buffer, "up-stats") == 0) {
        terminal_writestring("\nUptime: System is running smoothly.");
    } else if (strcmp(cmd_buffer, "ram-check") == 0) {
        terminal_writestring("\nRAM Usage: 16 KB / 2 MB used.");
    } else if (strcmp(cmd_buffer, "curr-path") == 0) {
        terminal_writestring("\n");
        terminal_writestring(current_path);
    } else if (strncmp(cmd_buffer, "nav-to ", 7) == 0) {
        strcpy(current_path, "/");
        strcpy(current_path + 1, get_arg(cmd_buffer, 7));
        terminal_writestring("\nNavigated to new folder.");
    } else if (strncmp(cmd_buffer, "create-folder ", 14) == 0) {
        for(int i=0; i<MAX_ITEMS; i++) {
            if(fs_type[i] == 0) {
                strcpy(fs_names[i], get_arg(cmd_buffer, 14));
                fs_type[i] = 2;
                terminal_writestring("\nFolder created.");
                break;
            }
        }
    } else if (strcmp(cmd_buffer, "list-items") == 0) {
        terminal_writestring("\nItems in memory:\n");
        for(int i=0; i<MAX_ITEMS; i++) {
            if(fs_type[i] != 0) {
                terminal_writestring((fs_type[i] == 1) ? "[FILE] " : "[DIR] ");
                terminal_writestring(fs_names[i]);
                terminal_writestring("\n");
            }
        }
    } else if (strncmp(cmd_buffer, "create-file ", 12) == 0) {
        for(int i=0; i<MAX_ITEMS; i++) {
            if(fs_type[i] == 0) {
                strcpy(fs_names[i], get_arg(cmd_buffer, 12));
                fs_data[i][0] = '\0';
                fs_type[i] = 1;
                terminal_writestring("\nFile created.");
                break;
            }
        }
    } else if (strncmp(cmd_buffer, "destroy ", 8) == 0) {
        char* target = get_arg(cmd_buffer, 8);
        for(int i=0; i<MAX_ITEMS; i++) {
            if(fs_type[i] != 0 && strcmp(fs_names[i], target) == 0) {
                fs_type[i] = 0;
                terminal_writestring("\nItem destroyed.");
                break;
            }
        }
    } else if (strncmp(cmd_buffer, "write-file ", 11) == 0) {
        terminal_writestring("\nDone.");
    } else if (strncmp(cmd_buffer, "read-file ", 10) == 0) {
        terminal_writestring("\nReading file... (Virtual Content)");
    } else if (strcmp(cmd_buffer, "power-cycle") == 0) {
        terminal_writestring("\nForce restarting...");
        outb(0x64, 0xFE);
    } else if (strcmp(cmd_buffer, "halt-sys") == 0) {
        terminal_writestring("\nSystem Shutdown. CPU Halted.");
        asm volatile("cli; hlt");
    } else if (cmd_idx > 0) {
        terminal_writestring("\nUnknown command. Type 'show-guide'.");
    }
    
    cmd_idx = 0; 
    terminal_setcolor(15); 
    terminal_writestring("\nFirstOS/");
    terminal_writestring(current_path);
    terminal_writestring("> ");
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
