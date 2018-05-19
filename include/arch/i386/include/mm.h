#define MEMORY_HIGH_LIMIT 0x00EFFFFF
#define PAGE_SIZE (1024*4) /* 4KB */
#define PHYS_PAGETABLE_SIZE 1048456 /* 4GB / PAGE_SIZE */
#define MMAP_TABLE_SIZE 256 /* mmap table size */

struct page {
  int count; /* TODO atomicな操作にする */
  u32 *phys_mem;
  u32 *virt_mem;
};

struct memory_map {
  u32 offset_start;
  u32 *phys_start;
  u32 *phys_end;
};

void setup_physical_memory(u32 addr);
void setup_heap(void);

int phys_to_page(u32 *addr);
u32 *alloc_page();
void free_page(u32 *addr);
