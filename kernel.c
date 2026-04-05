#include "terminal.h"
#include "gdt.h"

void kernel_main(void) {
    init_gdt();
    terminal_initialize();
    terminal_writestring("FirstOS/Users> ");
}
