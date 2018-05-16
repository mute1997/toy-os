# -----------------------
#  command
# -----------------------
CD=cd

# -----------------
# Directories
# -----------------
BUILD_DIR=build
KERNEL=kernel

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
	($(CD) $(KERNEL);$(MAKE))

.PHONY: clean
clean:
	($(CD) $(KERNEL);$(MAKE) clean)

run:
	./scripts/run.sh

# -----------------------------
# QEMU
# -----------------------------
image:
	cp $(BUILD_DIR)/kernel.elf iso/boot/
	grub-mkrescue -o $(BUILD_DIR)/mutex.iso iso

qemu:
	qemu-system-i386 -m 1G -cdrom $(BUILD_DIR)/mutex.iso &


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
