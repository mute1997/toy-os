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
#  arch
# -----------------------
ARCH=../arch

# -----------------------
#  boot
# -----------------------
BOOT=../boot

# -----------------------
#  object
# -----------------------
OBJS = $(ARCH)/arch.o \
			$(BOOT)/loader.o

# -----------------------
#  Directories
# -----------------------
BUILD_DIR=../build
OUTPUT_FILE=$(BUILD_DIR)/kernel.elf


.PHONY: all
all:
	($(CD) $(ARCH);$(MAKE))
	($(CD) $(BOOT);$(MAKE))
	$(LD) $(LDFLAGS) -n  -T $(LDSCRIPT) \
		-o $(OUTPUT_FILE) \
		$(BOOT)/loader.o $(ARCH)/arch.o

.PHONEY: clean
clean:
	($(CD) $(ARCH);$(MAKE) clean)
	($(CD) $(BOOT);$(MAKE) clean)
