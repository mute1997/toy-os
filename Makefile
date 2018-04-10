CC     = gcc
CFLAGS = \
				 -pipe \
				 -ffreestanding \
				 -fno-common \
				 -fno-builtin \
				 -fomit-frame-pointer \
				 -Os \
				 -Wall \
				 -c
LD     = ld -nostdlib --oformat binary
BUILD_DIR = build

all: kernel.elf

kernel.elf: kernel.o loader.o
	$(LD) -Ttext=0x100000 --oformat elf32-i386 -o kernel.elf \
		loader.o kernel.o

loader.o: loader.S
	$(CC) $(CFLAGS) -o loader.o loader.S

%.o: %.c
	$(CC) $(CFLAGS) -masm=intel $*.c

.PHONY: clean
clean:
	rm -f *.o
	rm -f *.elf
