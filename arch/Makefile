ARCH=i386
KOBJECT=kernel.o
OBJECT=kernel.c

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
				 -masm=intel

.PHONY: all
all: $(KOBJECTS)
	$(CC) $(CFLAGS) -o $(KOBJECT) $(ARCH)/$(OBJECT)

.PHONEY: clean
clean:
	rm $(KOBJECT)
