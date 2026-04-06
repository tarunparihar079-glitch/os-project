CC = gcc
CFLAGS = -m32 -fno-pie -ffreestanding -nostdlib
kernel.o: kernel.c
	$(CC) $(CFLAGS) -c kernel.c -o kernel.o
idt.o: idt.c
	$(CC) $(CFLAGS) -c idt.c -o idt.o
