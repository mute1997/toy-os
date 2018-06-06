#include <mm.h>
#include <std/printk.h>

extern pd_entry page_directory[1024];
extern pt_entry page_table[1024];

u32 virt_to_phys(u32 *virt) {
  return (*virt & VM_ADDR_MASK);
}

void enable_paging() {
  u32 cr0=read_cr0();
  cr0|=0x80000000;
  write_cr0(cr0);
}

/* TODO */
void init_paging() {
  /* mapping KERNEL_VIRTUAL_BASE - KERNEL_VIRTUAL_END */
  for(u32 addr=KERNEL_VIRTUAL_BASE;addr<KERNEL_VIRTUAL_END;addr+=((sizeof(u32))*PTRS_PER_PGD)) {
    printk("pde: %d,  pte: %d", pde_index(addr), pte_index(addr));
    // if (addr==KERNEL_VIRTUAL_BASE+(((sizeof(u32))*PTRS_PER_PGD))*5) {
    //   break;
    // }
  }

  // write_cr3(page_directory);

  printk("Setup paging... [OK]");
}
