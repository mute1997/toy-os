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
LD     = ld
LDFLAGS = -nostdlib
BUILD_DIR = build

all: kernel.elf

kernel.elf:
	nasm -f elf64 -o $(BUILD_DIR)/loader.o loader.asm
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/kernel.o kernel.c
	$(LD) $(LDFLAGS) -n -o iso/boot/kernel.elf -T linker.ld build/loader.o build/kernel.o

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/*.elf

image:
	grub-mkrescue -o mutex.iso iso

qemu:
	qemu-system-i386 -cdrom mutex.iso &
