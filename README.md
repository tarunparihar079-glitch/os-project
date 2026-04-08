# FirstOS - A Custom 32-bit Kernel

FirstOS is a basic operating system kernel built from scratch in C and Assembly.

## Features
- **32-bit Protected Mode:** Custom GDT and IDT setup.
- **Hardware Interaction:** PIC remapping and Keyboard drivers.
- **Shell Environment:** Interactive terminal with command support (help, clear).
- **VGA Driver:** Color text output and hardware cursor management.

## How to Run
1. Ensure you have `gcc`, `nasm`, and `qemu` installed.
2. Run the automation script:
   ```bash
   ./run_os.sh
