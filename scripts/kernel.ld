ENTRY(kernel_main)

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
      *(.bss)
    }

}
