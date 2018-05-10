ARCH=i386

# -----------------------
#  command
# -----------------------
CD=cd
CC=clang
CFLAGS = \
				 -fno-builtin \
				 -Os \
				 -Wall \
				 -c \
				 -I ../include \
				 -I ../include/arch/$(ARCH)/include \
				 -I ../kernel \
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
ISO_FILE=$(BUILD_DIR)/mutex.iso

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
			$(KERNEL_DIR)/arch/$(ARCH)/i8325.o \
			$(KERNEL_DIR)/arch/$(ARCH)/io_intr.o \
			$(KERNEL_DIR)/arch/$(ARCH)/klib.o \
			$(LIB_DIR)/vsprintf.o


%.o : %.c
	$(CC) $(CFLAGS) -o $*.o $*.c

%.o : %.S
	$(NASM) $(NASM_FLAGS) -o $*.o $*.S

all: $(OBJS)
	$(LD) $(LDFLAGS) -n  -T $(LDSCRIPT) \
		-o $(KERNEL_ELF) \
		$(OBJS)

.PHONEY: clean
clean:
	rm $(OBJS)
	rm $(KERNEL_ELF)
	rm $(ISO_FILE)
	rm ../build/kernel.map
