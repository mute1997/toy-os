#include <mm.h>
#include <std/printk.h>
#include <std/hlt.h>

extern pd_entry page_directory[1024];
pt_entry page_table[1024][1024] __attribute__((aligned(4096)));

u32 virt_to_phys(u32 *virt) {
  if (page_directory[pde_index((u32)virt)] & VM_PS != 0) {
    /* 4MB paging */
    return (page_directory[pde_index((u32)virt)] & 0xFFC00000) | ((u32)virt & 0x3FFFFF);
  } else {
    /* TODO 4KB paging */
  }
  return 0;
}

/* map each 4KB page */
void map_page(u32 *phys_addr, u32 *virt_addr, u32 size) {
  u32 pd_index = pde_index((u32)virt_addr);
  u32 pt_index = pte_index((u32)virt_addr);

  /* setting up page table entry */
  page_table[pd_index][pt_index] = ((u32)phys_addr & 0xFFFFF000) |  VM_PRESENT | VM_RW;

  /* setting up page directory entry */
  u32 pt_phys = virt_to_phys(&page_table[pd_index][pt_index]);
  page_directory[pd_index] = ((pt_phys) & 0xFFFFF000) | VM_PRESENT | VM_RW;

  // TODO グローバル変数の物理アドレスと仮想アドレスの対応がおかしい
  // TODO ローカル変数でページングすると有効にはなるものの、データがおかしい
  // for debug ---------------
  printk("pt            : 0x%x", page_table[pd_index][pt_index]);
  printk("pt virt addr  : 0x%x", &page_table[pd_index][pt_index]);
  printk("pt phys addr  : 0x%x", pt_phys);

  u32 pt[1024] __attribute__((aligned(4096)));
  for(int i=0;i<1024;i++) pt[i] = 0x0;
  pt[pt_index] = ((u32)phys_addr & 0xFFFFF000) | VM_PRESENT | VM_RW;
  pt_phys = virt_to_phys(&pt);
  page_directory[pd_index] = ((pt_phys) & 0xFFFFF000) | VM_PRESENT | VM_RW;

  hlt();
  // -------------------------
}

/* unmap page */
void unmap_page(u32 *virt_addr, u32 size) {
}
