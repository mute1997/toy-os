#include <mm.h>

pt_entry pte[1024];
pd_entry pde[1024];

u32 virt_to_phys(u32 *virt) {
  return (*virt & VM_ADDR_MASK);
}
