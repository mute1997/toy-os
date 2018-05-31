#define MEMORY_HIGH_LIMIT 0x00EFFFFF
#define PAGE_SIZE (1024*4) /* 4KB */
#define PHYS_PAGETABLE_SIZE 1048456 /* 4GB / PAGE_SIZE */
#define MMAP_TABLE_SIZE 256 /* mmap table size */

/* PTE constants */
#define VM_PRESENT        0x001
#define VM_WRITE          0x002
#define VM_READ           0x000
#define VM_USER           0x004
#define VM_PWT            0x008
#define VM_PCD            0x010
#define VM_ACC            0x020
#define VM_ADDR_MASK      0xFFFFF000

/* PDE constants */

typedef u32 pt_entry;
typedef u32 pd_entry;

struct page {
  int count; /* TODO atomicな操作にする */
  u32 *phys_mem;
  u32 *virt_mem;
};

/* init */
void setup_physical_memory(u32 addr);
void setup_heap(void);

/* page_alloc */
int phys_to_page(u32 *addr);
u32 *alloc_page();
void free_page(u32 *addr);

/* mmu */
virt_to_phys(u32 *virt);
