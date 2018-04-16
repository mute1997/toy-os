static inline void hlt() {
  while(1) {
    __asm__ __volatile__ ("hlt");
  }
}
