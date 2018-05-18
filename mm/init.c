#include <grub/multiboot2.h>
#include <std/printk.h>
#include <std/string.h>
#include <asm/types.h>
#include <mm.h>

extern unsigned long _bss_start;
extern unsigned long _bss_end;
extern unsigned long _text_start;
extern unsigned long _kernel_end;

int is_kernel_section(u32 addr) {
  // if(&_text_start < addr && addr > &_kernel_end) {
  //   // printk("outside kernel");
  // }
  return (&_text_start < addr && addr > &_kernel_end);
}

u32* kalloc(u32 addr) {
  /* 空きを探してポインタを返す */
}

void kfree(u32 addr) {
  /* addrを1埋めする */
}

int freerange(u32 addr, u32 length) {
  u32 *index;
  u32 limit = addr+length;

  for (index=(void*)addr;index<limit;index++) {
    if (is_kernel_section(index)) continue;
    // TODO reservedなメモリの範囲が入らないように確認
    // TODO すでに1で埋まっていないか確認
    // *index=0;
  }
  return 1;
}

void print_mmap(multiboot_memory_map_t *mmap) {
  printk (" base_addr = 0x%x%x,"
      " length = 0x%x%x, type = 0x%x",
      (unsigned) (mmap->addr>>32),
      (unsigned) (mmap->addr&0xFFFFFFFF),
      (unsigned) (mmap->len>>32),
      (unsigned) (mmap->len&0xFFFFFFFF),
      (unsigned) mmap->type);
}

void setup_physical_memory(u32 addr) {
  struct multiboot_tag *tag;
  multiboot_memory_map_t *mmap;

  for (tag = (struct multiboot_tag *) (addr + 8);
      tag->type != MULTIBOOT_TAG_TYPE_END;
      tag = (struct multiboot_tag *) ((multiboot_uint8_t *) tag 
        + ((tag->size + 7) & ~7)))
  {
    switch (tag->type)
    {
      case MULTIBOOT_TAG_TYPE_MMAP:
        {
          for (mmap = ((struct multiboot_tag_mmap *) tag)->entries;
              (multiboot_uint8_t *) mmap 
              < (multiboot_uint8_t *) tag + tag->size;
              mmap = (multiboot_memory_map_t *) 
              ((unsigned long) mmap
               + ((struct multiboot_tag_mmap *) tag)->entry_size)) {

            /* mmap->typeが1かつ 32bit以内 */
            if (mmap->type == 1 && MEMORY_HIGH_LIMIT > mmap->addr) {
              print_mmap(mmap);
              freerange(mmap->addr, mmap->len);
            }
          }
        }
        break;
    }
  }
  printk("Setup Memory... [OK]");
}

void setup_heap() {
  memset((void *)_bss_start, 0x00, _bss_end-_bss_start);
}
