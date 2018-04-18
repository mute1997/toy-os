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
				 -m32
LD     = ld
LDFLAGS = -nostdlib -Map ../build/kernel.map -m elf_i386
LDSCRIPT = ../scripts/kernel.ld

# -----------------------
#  Directories
# -----------------------
ARCH_DIR=../arch
BOOT_DIR=../boot
DRIVER_DIR=../drivers
KERNEL_DIR=.
LIB_DIR=../lib

# output
BUILD_DIR=../build
KERNEL_ELF=$(BUILD_DIR)/kernel.elf

# -----------------------
#  object
# -----------------------
OBJS = $(ARCH_DIR)/$(ARCH)/kernel/setup.o \
			$(ARCH_DIR)/$(ARCH)/lib/string.o \
			$(ARCH_DIR)/$(DRIVER_DIR)/vram/video.o \
			$(KERNEL_DIR)/printk.o \
			$(LIB_DIR)/vsprintf.o


all: $(OBJS)
	($(CD) $(BOOT_DIR);$(MAKE))
	$(LD) $(LDFLAGS) -n  -T $(LDSCRIPT) \
		-o $(KERNEL_ELF) \
		$(BOOT_DIR)/loader.o $(OBJS)

.PHONEY: clean
clean:
	rm $(OBJS)
	rm $(KERNEL_ELF)
	rm ../build/kernel.map
