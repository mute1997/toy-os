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

loader.o: loader.S
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/loader.o loader.S

%.o: %.c
	$(CC) $(CFLAGS) -masm=intel $*.c -o $(BUILD_DIR)/kernel.o

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/*.elf
