#include <mm.h>
#include <std/printk.h>
#include <std/hlt.h>

extern pd_entry page_directory[1024];
pd_entry a[10];
pd_entry b;
// pt_entry page_table[1024][1024] __attribute__((aligned(4096)));

u32 virt_to_phys(u32 *virt) {
  if ((page_directory[pde_index((u32)virt)] & VM_PS) != 0) {
    /* 4MB paging */
    return (page_directory[pde_index((u32)virt)] & 0xFFC00000) | ((u32)virt & 0x3FFFFF);
  } else {
    /* TODO 4KB paging */
  }
  return 0;
}

/* map each 4KB page */
u32 *map_page(u32 *phys_addr, u32 *virt_addr, u32 size) {
  u32 pd_index = pde_index((u32)virt_addr);
  u32 pt_index = pte_index((u32)virt_addr);

  /* setting up page table entry */
  // page_table[pd_index][pt_index] = ((u32)phys_addr & 0xFFFFF000) |  VM_PRESENT | VM_RW;

  /* setting up page directory entry */
  // u32 pt_phys = virt_to_phys(&page_table[pd_index][pt_index]);
  // page_directory[pd_index] = ((pt_phys) & 0xFFFFF000) | VM_PRESENT | VM_RW;

  // TODO グローバル変数の物理アドレスと仮想アドレスの対応がおかしい

  // ローカル変数だと動いた
  // u32 pt[1024] __attribute__((aligned(4096)));
  // for(int i=0;i<1024;i++) pt[i] = 0x0;
  // pt[pt_index] = ((u32)phys_addr & 0xFFFFF000) | VM_PRESENT | VM_RW;
  // pt_phys = virt_to_phys(&pt);
  // page_directory[pd_index] = ((pt_phys) & 0xFFFFF000) | VM_PRESENT | VM_RW;

  a[0] = 0xFFF;
  b = 0xFFF;
  printk("0x%x", a[0]);
  printk("0x%x", a[0]);
  printk("0x%x", b);
  printk("0x%x", b);
  hlt();
  // -------------------------

  return (u32*)((u32)virt_addr | ((u32)phys_addr & 0x00000FFF));
}

/* unmap page */
void unmap_page(u32 *virt_addr, u32 size) {
}
