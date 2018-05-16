#include <grub/multiboot2.h>
#include <std/printk.h>

/* TODO type == 1 かつ base_addr = 0x0100000 の終了アドレスを保存する */
/* 開始アドレスはkernel_end */
/* */
void get_memory_map(unsigned long addr) {
}

void print_memory_map(unsigned long addr) {
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
          printk ("memory mapping");
          for (mmap = ((struct multiboot_tag_mmap *) tag)->entries;
              (multiboot_uint8_t *) mmap 
              < (multiboot_uint8_t *) tag + tag->size;
              mmap = (multiboot_memory_map_t *) 
              ((unsigned long) mmap
               + ((struct multiboot_tag_mmap *) tag)->entry_size))
            printk (" base_addr = 0x%x%x,"
                " length = 0x%x%x, type = 0x%x",
                (unsigned) (mmap->addr >> 32),
                (unsigned) (mmap->addr & 0xffffffff),
                (unsigned) (mmap->len >> 32),
                (unsigned) (mmap->len & 0xffffffff),
                (unsigned) mmap->type);
        }
        break;
    }
  }
}
