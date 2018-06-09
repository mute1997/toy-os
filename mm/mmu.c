#include <mm.h>
#include <std/printk.h>

extern pd_entry page_directory[1024];

u32 virt_to_phys(u32 *virt) {
  return (*virt & VM_ADDR_MASK);
}
