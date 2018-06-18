#include <mm.h>
#include <std/printk.h>

extern pd_entry page_directory[1024];
pt_entry page_table[1024][1024];

u32 virt_to_phys(u32 *virt) {
  return (*virt & VM_ADDR_MASK);
}

/* map each 4KB page */
void map_page(u32 *phys_addr, u32 *virt_addr, u32 size) {
  u32 pd_index = pde_index((u32)virt_addr);
  u32 pt_index = pte_index((u32)virt_addr);

  // MEMO: 
  // Grub address = 0x1908280

  /* 4MB paging*/
  // page_directory[pd_index] = (((u32)phys_addr) & 0xFFC00000) | VM_PRESENT | VM_RW | VM_PS;

  /* setting up page table entry */
  page_table[pd_index][pt_index] = ((u32)phys_addr & 0xFFFFF000) |  VM_PRESENT | VM_RW;
  
  // TODO page_tableが正しく指定できてないっぽい
  /* setting up page directory entry */
  u32 *pt = &page_table[pd_index][pt_index];
  page_directory[pd_index] = (((u32)pt) & 0xFFFFF000) | VM_PRESENT | VM_RW;
}

/* unmap page */
void unmap_page(u32 *virt_addr, u32 size) {
}
