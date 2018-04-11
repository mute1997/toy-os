void kernel_main(void) {
  while(1) {
    __asm__ __volatile__ ("hlt");
  }
}
