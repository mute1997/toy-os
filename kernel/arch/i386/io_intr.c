void enable() {
  __asm__ __volatile__ ("sti");
}

void disable() {
  __asm__ __volatile__ ("cli");
}
