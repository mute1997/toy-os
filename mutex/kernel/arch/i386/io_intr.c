void enable_intr() {
  __asm__ __volatile__ ("sti");
}

void disable_intr() {
  __asm__ __volatile__ ("cli");
}
