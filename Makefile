OBJS = kernel.o gdt.o idt.o keyboard.o shell.o
CC = gcc
CFLAGS = -m32 -fno-pie -ffreestanding -nostdlib
kernel.o: kernel.c
	$(CC) $(CFLAGS) -c kernel.c -o kernel.o
idt.o: idt.c
	$(CC) $(CFLAGS) -c idt.c -o idt.o
keyboard.o: keyboard.c
	$(CC) $(CFLAGS) -c keyboard.c -o keyboard.o
shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c -o shell.o
