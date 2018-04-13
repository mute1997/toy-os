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
LD     = ld
LDFLAGS = -nostdlib -Map kernel.map
LDSCRIPT = scripts/kernel.ld

BUILD_DIR = build
SRC_DIR = src

DOCKER_IMAGE=mutexos
DOCKER_TAG=0.1

all: kernel.elf

kernel.elf:
	nasm -f elf64 -o $(BUILD_DIR)/loader.o $(SRC_DIR)/loader.asm
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/kernel.o $(SRC_DIR)/kernel.c
	$(LD) $(LDFLAGS) -n \
		-o $(BUILD_DIR)/kernel.elf \
		-T $(LDSCRIPT) \
		$(BUILD_DIR)/loader.o $(BUILD_DIR)/kernel.o

.PHONY: clean
clean:
	find . -name "*.o" | xargs --no-run-if-empty rm
	find . -name "*.iso" | xargs --no-run-if-empty rm
	find . -name "*.elf" | xargs --no-run-if-empty rm

image:
	cp $(BUILD_DIR)/kernel.elf iso/boot/
	grub-mkrescue -o $(BUILD_DIR)/mutex.iso iso

qemu:
	qemu-system-i386 -cdrom $(BUILD_DIR)/mutex.iso &

build-docker:
	docker build -t $(DOCKER_IMAGE):$(DOCKER_TAG) .

osx:
	docker run -it -v $(PWD):/app $(DOCKER_IMAGE):$(DOCKER_TAG) make
	docker run -it -v $(PWD):/app $(DOCKER_IMAGE):$(DOCKER_TAG) make image
