#include "idt.h"
#include "terminal.h"
#include "gdt.h"

void kernel_main(void) {
    init_gdt();
    init_idt();
    terminal_initialize();
    terminal_writestring("FirstOS/Users> ");
}
