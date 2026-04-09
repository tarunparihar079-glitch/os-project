CC = gcc
CFLAGS = -m32 -fno-pie -ffreestanding -nostdlib
AS = nasm
ASFLAGS = -f elf32

OBJS = boot.o kernel.o terminal.o string.o gdt.o idt.o keyboard.o shell.o

all: FirstOS.bin

FirstOS.bin: $(OBJS) linker.ld
	ld -m elf_i386 -T linker.ld -o FirstOS.bin $(OBJS)

boot.o: boot.asm
	$(AS) $(ASFLAGS) boot.asm -o boot.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o FirstOS.bin
