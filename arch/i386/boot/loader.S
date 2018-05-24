extern multiboot_addr
extern _bss_start
extern _kernel_end
global start

section .multiboot
header_start:
  dd 0xe85250d6                ; magic number (multiboot 2)
  dd 0                         ; architecture 0 (protected mode i386)
  dd header_end - header_start ; header length
  dd -(0xe85250d6 + 0 + (header_end - header_start)) ; checksum

  ; ; address header
  ; dw 2, 0
  ; dd 8+16
  ; dd header_start
  ; dd multiboot_addr - KERNEL_VIRTUAL_BASE
  ; dd _bss_start - KERNEL_VIRTUAL_BASE
  ; dd _kernel_end - KERNEL_VIRTUAL_BASE
  ;
  ; ; entry point tag
  ; dw 3,0
  ; dd 8+4
  ; dd start - KERNEL_VIRTUAL_BASE
  ;
  ; ; module aligment tag
  ; dw 6,0
  ; dd 12
  ; dd 0

  ; required end tag
  dw 0    ; type
  dw 0    ; flags
  dd 8    ; size
header_end:

KERNEL_VIRTUAL_BASE equ 0xC0000000
KERNEL_PAGE_NUMBER equ (KERNEL_VIRTUAL_BASE >> 22)

section .data
align 0x1000
boot_page_directory:
  dd 0x00000083
  times (KERNEL_PAGE_NUMBER - 1) dd 0
  dd 0x00000083
  times (1024 - KERNEL_PAGE_NUMBER - 1) dd 0

section .text
  ; kernel entry function
  extern setup

  ; stack
  STACK_SIZE equ 4096*4

  ; Entry point
  ; start equ (_start - 0xC0000000)
  ; global start

start:
  mov ecx, (boot_page_directory - KERNEL_VIRTUAL_BASE)
  mov cr3, ecx

  mov ecx, cr4
  or ecx, 0x00000010
  mov cr4, ecx

  mov ecx, cr0
  or ecx, 0x80000000
  mov cr0, ecx

  lea ecx, [start_higher_half]
  jmp ecx

start_higher_half:
  mov dword [boot_page_directory], 0
  invlpg [0]

  mov esp, stack+STACK_SIZE

  ; add ebx, KERNEL_VIRTUAL_BASE
  push ebx

  ; add eax, KERNEL_VIRTUAL_BASE
  push eax

  call setup

  hlt

section .bss
stack:
  resb STACK_SIZE
