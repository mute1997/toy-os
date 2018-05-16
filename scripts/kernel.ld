ENTRY(start)

SECTIONS {
    . = 1M;

    .text :
    {
      _text_start = .;
      *(.multiboot_header)
      *(.text)
      _text_end = .;
    }

    .rodata :
    {
      *(.rodata)
    }

    .data :
    {
      *(.data)
    }

    bss :
    {
      _bss_start = .;
      *(.bss)
      _bss_end = .;
    }

}
