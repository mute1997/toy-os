#include <asm/types.h>
#include <mm.h>

extern struct page pages[PHYS_PAGETABLE_SIZE];
extern unsigned long _kernel_end;

int find_free_page() {
  int i;
  int offset=-1;
  for (i=0;i<PHYS_PAGETABLE_SIZE;i++) {
    if (pages[i].phys_mem != NULL && pages[i].count == 0) {
      return i;
    }
  }
  return -1;
}

int phys_to_page(u32 *addr) {
  return ((u32)addr-(u32)pages[0].phys_mem)/PAGE_SIZE;
}

/* return single page */
u32* alloc_page() {
  int offset=-1;
  offset=find_free_page();
  pages[offset].count=1;
  return (void*)pages[offset].phys_mem;
}

void free_page(u32 *addr) {
  int offset=-1;
  offset=phys_to_page(addr);
  pages[offset].count=0;
}
