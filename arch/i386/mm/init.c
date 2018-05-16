#include <asm/types.h>

extern unsigned long _bss_start;
extern unsigned long _bss_end;
extern unsigned long _text_start;
extern unsigned long _text_end;

u32 get_kernel_size() {
  return _bss_end - _text_start;
}

u32 get_system_memory_size() {
}
