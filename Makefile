# -----------------
# Dependencies
# -----------------
LD     = ld
LDFLAGS = -nostdlib -Map kernel.map
LDSCRIPT = scripts/kernel.ld
CD = cd

# -----------------
# Input Directorys
# -----------------
BOOT_DIR=boot
ARCH_DIR=arch

# -----------------
# Output Directory
# -----------------
BUILD_DIR=build
OUTPUT_FILE=$(BUILD_DIR)/kernel.elf

# -----------------
# Docker
# -----------------
DOCKER_IMAGE=mutexos
DOCKER_TAG=0.1

# -----------------
# Recipe
# -----------------
.PHONY: all
all:
	($(CD) $(BOOT_DIR);$(MAKE))
	($(CD) $(ARCH_DIR);$(MAKE))
	$(LD) $(LDFLAGS) -n  -T $(LDSCRIPT) \
		-o $(OUTPUT_FILE) \
		$(BOOT_DIR)/loader.o $(ARCH_DIR)/kernel.o

.PHONY: clean
clean:
	($(CD) $(BOOT_DIR);$(MAKE) clean)
	($(CD) $(ARCH_DIR);$(MAKE) clean)


# -----------------------------
# QEMU
# -----------------------------
image:
	cp $(BUILD_DIR)/kernel.elf iso/boot/
	grub-mkrescue -o $(BUILD_DIR)/mutex.iso iso

qemu:
	qemu-system-i386 -cdrom $(BUILD_DIR)/mutex.iso &


# -----------------------------
# Docker 
# -----------------------------
build-docker:
	docker build -t $(DOCKER_IMAGE):$(DOCKER_TAG) .

osx:
	docker run -it -v $(PWD):/app $(DOCKER_IMAGE):$(DOCKER_TAG) make all
	docker run -it -v $(PWD):/app $(DOCKER_IMAGE):$(DOCKER_TAG) make image

bash:
	docker run -it -v $(PWD):/app $(DOCKER_IMAGE):$(DOCKER_TAG) /bin/bash
