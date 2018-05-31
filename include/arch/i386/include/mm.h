#define MEMORY_HIGH_LIMIT 0x00EFFFFF
#define PAGE_SIZE (1024*4) /* 4KB */
#define PHYS_PAGETABLE_SIZE 1048456 /* 4GB / PAGE_SIZE */
#define MMAP_TABLE_SIZE 256 /* mmap table size */

/* PTE, PDE constants */
#define VM_PRESENT        0x001
#define VM_RW             0x002
#define VM_USER           0x004 /* user | supervisor */
#define VM_PWT            0x008 /* page level write through */
#define VM_PCD            0x010 /* page level cache disable */
#define VM_ACC            0x020 /* page table accessed */
#define VM_DIRTY          0x040 /* page table accessed */
#define VM_PS             0x080 /* page table accessed */
#define VM_GLOBAL         0x100 /* page table accessed */
#define VM_UNUSED1        0x200 /* available for use */
#define VM_UNUSED2        0x400 /* available for use */
#define VM_UNUSED3        0x800 /* available for use */

#define VM_ADDR_MASK      0xFFFFF000

#define _VM_INIT_USER (VM_RW | VM_PRESENT | VM_USER)
#define _VM_INIT_KERN (VM_RW | VM_PRESENT)

/* TODO #define pgd_index() */
/* TODO #define pte_index() */

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
