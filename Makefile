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

kernel.elf:
	nasm -f elf64 -o $(BUILD_DIR)/loader.o loader.asm
	nasm -f elf64 -o $(BUILD_DIR)/kernel.o kernel.asm
	$(LD) -n -o iso/boot/kernel.elf -T linker.ld build/loader.o build/kernel.o

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/*.elf

image:
	grub-mkrescue -o mutex.iso iso

qemu:
	grub-file --is-x86-multiboot iso/boot/kernel.elf && qemu-system-i386 -cdrom mutex.iso
