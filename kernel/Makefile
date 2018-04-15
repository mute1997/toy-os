ARCH=i386

# -----------------------
#  command
# -----------------------
CD=cd
CC=gcc
CFLAGS = \
				 -pipe \
				 -ffreestanding \
				 -fno-common \
				 -fno-builtin \
				 -fomit-frame-pointer \
				 -Os \
				 -Wall \
				 -c \
				 -masm=intel \
				 -I ../include
LD     = ld
LDFLAGS = -nostdlib -Map ../build/kernel.map
LDSCRIPT = ../scripts/kernel.ld

# -----------------------
#  Directories
# -----------------------
ARCH_DIR=../arch
BOOT_DIR=../boot

# output
BUILD_DIR=../build
KERNEL_ELF=$(BUILD_DIR)/kernel.elf

# -----------------------
#  object
# -----------------------
OBJS = $(ARCH_DIR)/$(ARCH)/kernel/setup.o \
			$(ARCH_DIR)/$(ARCH)/lib/string.o


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
