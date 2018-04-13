KOBJECT=loader.o
OBJECT=loader.asm

.PHONY: all
all: $(KOBJECTS)
	nasm -f elf64 -o $(KOBJECT) $(OBJECT)

.PHONEY: clean
clean:
	rm $(KOBJECT)
