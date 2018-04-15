OBJS=loader.o

.PHONY: all
all:
	nasm -f elf64 -o $(OBJS) loader.asm

.PHONEY: clean
clean:
	rm $(KOBJECT)
