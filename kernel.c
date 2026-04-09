#include "terminal.h"
#include "gdt.h"
#include "idt.h"

// Declare keyboard checker function
void check_keyboard();

void kernel_main(void) {
    init_gdt();
    init_idt();
    terminal_initialize();
    
    terminal_writestring("Welcome to FirstOS!\n");
    terminal_writestring("Type 'help' to see commands.\n\n");
    terminal_writestring("FirstOS/Users> ");
    
    // The Heartbeat of the OS
    while(1) {
        check_keyboard();
    }
}

