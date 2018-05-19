#include <grub/multiboot2.h>
#include <std/printk.h>
#include <std/string.h>
#include <asm/types.h>
#include <mm.h>

extern unsigned long _bss_start;
extern unsigned long _bss_end;
extern unsigned long _kernel_end;

int is_kernel_section(u32 addr);
int find_free_page();
void freerange(u32 addr, u32 length);
void print_mmap(multiboot_memory_map_t *mmap);

struct page pages[PHYS_PAGETABLE_SIZE];

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

            /* RAM Available && less than 32bit && dont use top */
            if (mmap->type == 1 && MEMORY_HIGH_LIMIT > mmap->addr && mmap->addr != 0x0) {
              freerange(mmap->addr, mmap->len);
            }
          }
        }
        break;
    }
  }
  printk("Setup Physical Memory... [OK]");
}

void setup_heap() {
  memset((void *)_bss_start, 0x00, _bss_end-_bss_start);
}

int is_kernel_section(u32 addr) {
  return &_kernel_end < (u32*)addr && &_kernel_end < (u32*)(addr+PAGE_SIZE);
}

/* return free page offset, witch found the first */
int find_unused_page() {
  int i;
  int offset=-1;
  for (i=0;i<PHYS_PAGETABLE_SIZE;i++) {
    if (pages[i].phys_mem == NULL && pages[i].count == 0) {
      offset=i;
      break;
    }
  }
  return offset;
}

void freerange(u32 addr, u32 length) {
  u32 page_addr;
  int offset;

  offset=find_unused_page();
  for(page_addr=addr;page_addr<addr+length;page_addr+=PAGE_SIZE) {
    if (!(is_kernel_section(page_addr))) continue;

    pages[offset].count=0;
    pages[offset].phys_mem=(void*)page_addr;
    pages[offset].virt_mem=NULL;

    offset+=1;
  }
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
