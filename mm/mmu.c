#include <mm.h>
#include <std/printk.h>

extern pd_entry page_directory[1024];
static pt_entry page_table[1024][1024];

u32 virt_to_phys(u32 *virt) {
  return (*virt & VM_ADDR_MASK);
}

void enable_paging() {
  u32 cr0=read_cr0();
  cr0|=0x80000000;
  write_cr0(cr0);
}

/* TODO */
void init_one_pde(u32 base_addr) {
  printk("PDE addr: 0x%x, index: %d", base_addr, pde_index(base_addr));

  int pde_index = pde_index(base_addr);
  for (int i=0;i<1024;i++) {
    u32 addr = base_addr+(i*sizeof(u32)*PTRS_PER_PTE);
    // TODO
    page_table[pde_index][pte_index(addr)] = addr;

    /* --- for Debug ------- */
    if (i == 1023 || i == 0)
      printk("  addr: 0x%x, index: %d, pde_index: %d, pte_index: %d", addr, i, pde_index, pte_index(addr));
    /* --------------------- */
  }

  /* --- for Debug ------- */
  u32 addr = base_addr+(1024*sizeof(u32)*PTRS_PER_PTE);
  printk("  addr: 0x%x, index: 1024 (next)", addr);
  printk("");
  /* --------------------- */

  // TODO
  // page_directory[pde_index(base_addr)] = page_table[pde_index];
}

/* mapping KERNEL_VIRTUAL_BASE - MEMORY_HIGH_LIMIT */
void init_paging() {
  int pde_count = (MEMORY_HIGH_LIMIT - KERNEL_VIRTUAL_BASE) / (sizeof(u32)*PTRS_PER_PTE*PTRS_PER_PGD);
  for (int i=0;i<=pde_count;i++) {
    u32 addr = KERNEL_VIRTUAL_BASE+(i*(sizeof(u32)*PTRS_PER_PTE*PTRS_PER_PGD));
    init_one_pde(addr);
  }

  page_table[1023][1023];
  // printk("pagetable 0x%x", page_table[1023][1023]);

  /* TODO */
  // write_cr3(page_directory);

  printk("Setup paging... [OK]");
}
