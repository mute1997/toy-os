ENTRY(start)

SECTIONS {
    . += 0xC0100000;

    .text : AT(ADDR(.text) - 0xC0000000)
    {
      _text_start = .;
      *(.multiboot)
      *(.text)
      _text_end = .;
    }

    .rodata : AT(ADDR(.rodata) - 0xC0000000)
    {
      *(.rodata)
    }

    .data : AT(ADDR(.data) - 0xC0000000)
    {
      *(.data)
    }

    .bss : AT(ADDR(.bss) - 0xC0000000)
    {
      _bss_start = .;
      *(.bss)
      _bss_end = .;
    }

	PROVIDE(_kernel_end = .);

}
