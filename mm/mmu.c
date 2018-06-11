#include <mm.h>
#include <std/printk.h>

extern pd_entry page_directory[1024];
pt_entry page_table[1024][1024];

u32 virt_to_phys(u32 *virt) {
  return (*virt & VM_ADDR_MASK);
}

/* map each 4KB page */
void map_page(u32 *phys_addr, u32 *virt_addr, u32 size) {

  // 10000011
  // u32 pd = 0x0 | PRESENT | RW;
  page_directory[pde_index(virt_addr)] = 0x0;
}

/* unmap page */
void unmap_page(u32 *virt_addr, u32 size) {
}
