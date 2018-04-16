ENTRY(start)

SECTIONS {
    . = 1M;

    .text :
    {
        *(.multiboot_header)
        *(.text)
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
      *(COMMON)
      *(.bss)
      _bss_end = .;
    }

}
