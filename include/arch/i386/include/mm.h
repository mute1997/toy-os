#define MEMORY_HIGH_LIMIT 0x00EFFFFF
#define PAGE_SIZE (1024*4) /* 4KB */
#define PHYS_PAGETABLE_SIZE 1048456 /* 4GB / PAGE_SIZE */

struct page {
  int count; /* TODO atomicな操作にする */
  u32 *phys_mem;
  u32 *virt_mem;
};

void setup_physical_memory(u32 addr);
void setup_heap(void);
