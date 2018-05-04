ARCH=i386

# -----------------------
#  command
# -----------------------
CD=cd
CC=gcc
CFLAGS = \
				 -fno-builtin \
				 -Os \
				 -Wall \
				 -c \
				 -masm=intel \
				 -I ../include \
				 -I ../include/arch/$(ARCH)/include \
				 -m32 \
				 -fno-stack-protector
LD     = ld
LDFLAGS = -nostdlib -Map ../build/kernel.map -m elf_i386
LDSCRIPT = ../scripts/kernel.ld
NASM = nasm
NASM_FLAGS = -f elf32

# -----------------------
#  Directories
# -----------------------
ARCH_DIR=../arch
BOOT_DIR=$(ARCH_DIR)/$(ARCH)/boot
DRIVER_DIR=../drivers
KERNEL_DIR=.
LIB_DIR=../lib

# output
BUILD_DIR=../build
KERNEL_ELF=$(BUILD_DIR)/kernel.elf

# -----------------------
#  object
# -----------------------
OBJS = $(BOOT_DIR)/loader.o \
			$(BOOT_DIR)/protect.o \
			$(ARCH_DIR)/$(ARCH)/kernel/setup.o \
			$(ARCH_DIR)/$(ARCH)/lib/string.o \
			$(ARCH_DIR)/$(DRIVER_DIR)/vram/video.o \
			$(KERNEL_DIR)/printk.o \
			$(KERNEL_DIR)/trap.o \
			$(LIB_DIR)/vsprintf.o


%.o : %.c
	$(CC) $(CFLAGS) -o $*.o $*.c

%.o : %.asm
	$(NASM) $(NASM_FLAGS) -o $*.o $*.asm

all: $(OBJS)
	$(LD) $(LDFLAGS) -n  -T $(LDSCRIPT) \
		-o $(KERNEL_ELF) \
		$(OBJS)

.PHONEY: clean
clean:
	rm $(OBJS)
	rm $(KERNEL_ELF)
	rm ../build/kernel.map
