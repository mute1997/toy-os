ARCH=i386
SRCS=$(ARCH)/kernel.c
OUTPUT=arch.o

CC     = gcc
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

.PHONY: all
all:
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRCS)

.PHONEY: clean
clean:
	rm $(OUTPUT)
