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
	$(LD) -Ttext=0x100000 --oformat elf32-i386 -o $(BUILD_DIR)/kernel.elf \
		$(BUILD_DIR)/loader.o $(BUILD_DIR)/kernel.o

loader.o: loader.asm
	nasm -o $(BUILD_DIR)/loader.o loader.asm

%.o: %.c
	$(CC) $(CFLAGS) -masm=intel $*.c -o $(BUILD_DIR)/kernel.o

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/*.elf

image:
	mkdir -p iso/boot/grub
	cp kernel.elf iso/boot/kernel.elf
	cp grub.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o mutex.iso iso

qemu:
	qemu-system-i386 -cdrom mutex.iso
	# grub-file --is-x86-multiboot mutex.iso && qemu-system-i386 -cdrom mutex.iso
