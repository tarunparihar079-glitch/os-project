; Multiboot header constants
MBALIGN  equ  1 << 0
MEMINFO  equ  1 << 1
FLAGS    equ  MBALIGN | MEMINFO
MAGIC    equ  0x1BADB002
CHECKSUM equ -(MAGIC + FLAGS)

; Multiboot section (Must be at the very top of the compiled binary)
section .multiboot
align 4
dd MAGIC
dd FLAGS
dd CHECKSUM

; Stack allocation
section .bss
align 16
stack_bottom:
resb 16384 ; 16 KiB
stack_top:

; OS Entry Point
section .text
global start
extern kernel_main

start:
    ; Setup stack
    mov esp, stack_top
    
    ; Call the C kernel
    call kernel_main
    
    ; If kernel returns, halt the CPU
    cli
.hang:  
    hlt
    jmp .hang
