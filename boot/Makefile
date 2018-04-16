OBJS=loader.o

.PHONY: all
all:
	nasm -f elf32 -o $(OBJS) loader.asm

.PHONEY: clean
clean:
	rm $(KOBJECT)
