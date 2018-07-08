#include <asm/types.h>
#include <mm.h>

extern struct page pages[PHYS_PAGETABLE_SIZE];
extern unsigned long _kernel_end;
static u32 virt_heap_end = 0x00EFFFFF;

int find_free_page() {
  int i;
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

u32 *kmalloc(u32 size) {
  u32 ps[256];
  u32 alloced_size = 0;
  int index = 0;

  memset(ps, NULL, sizeof(ps));

  /* alloc page */
  do {
    ps[index] = alloc_page();
    alloced_size += PAGE_SIZE;
    index++;
  } while(alloced_size<size);

  /* map virtual memory */
  for(int i=0;ps[i]!=NULL;i++) {
    virt_heap_end-=PAGE_SIZE;
    map_one_page((u32*)ps[i], (u32*)virt_heap_end);
  }

  return (u32*)(virt_heap_end & 0xFFFFF000);
}

void free(u32 addr) {
}
