ENTRY(setup)

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
      *(.bss)
      _bss_end = .;
    }

}
