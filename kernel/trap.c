#include <std/printk.h>
#include <std/hlt.h>
#include <trap.h>

__attribute__((interrupt))
void hwint00(struct interrupt_frame *frame){
  printk("hwint00");
}
__attribute__((interrupt))
void hwint01(struct interrupt_frame *frame){
  printk("hwint01");
}
__attribute__((interrupt))
void hwint02(struct interrupt_frame *frame){
  printk("hwint02");
}
__attribute__((interrupt))
void hwint03(struct interrupt_frame *frame){
  printk("hwint03");
}
__attribute__((interrupt))
void hwint04(struct interrupt_frame *frame){
  printk("hwint04");
}
__attribute__((interrupt))
void hwint05(struct interrupt_frame *frame){
  printk("hwint05");
}
__attribute__((interrupt))
void hwint06(struct interrupt_frame *frame){
  printk("hwint06");
}
__attribute__((interrupt))
void hwint07(struct interrupt_frame *frame){
  printk("hwint07");
}
__attribute__((interrupt))
void hwint08(struct interrupt_frame *frame){
  printk("hwint08");
}
__attribute__((interrupt))
void hwint09(struct interrupt_frame *frame){
  printk("hwint09");
}
__attribute__((interrupt))
void hwint10(struct interrupt_frame *frame){
  printk("hwint10");
}
__attribute__((interrupt))
void hwint11(struct interrupt_frame *frame){
  printk("hwint11");
}
__attribute__((interrupt))
void hwint12(struct interrupt_frame *frame){
  printk("hwint12");
}
__attribute__((interrupt))
void hwint13(struct interrupt_frame *frame){
  printk("hwint13");
}
__attribute__((interrupt))
void hwint14(struct interrupt_frame *frame){
  printk("hwint14");
}
__attribute__((interrupt))
void hwint15(struct interrupt_frame *frame){
  printk("hwint15");
}

__attribute__((interrupt))
void divide_error (struct interrupt_frame *frame) {
  printk("divide error");
}
__attribute__((interrupt))
void single_step_exception (struct interrupt_frame *frame){
  printk("single step exception");
}
__attribute__((interrupt))
void nmi (struct interrupt_frame *frame){
  printk("nmi");
}
__attribute__((interrupt))
void breakpoint_exception (struct interrupt_frame *frame){
  printk("breakpoint exception");
}
__attribute__((interrupt))
void overflow (struct interrupt_frame *frame){
  printk("overflow");
}
__attribute__((interrupt))
void bounds_check (struct interrupt_frame *frame){
  printk("bounds check");
}
__attribute__((interrupt))
void inval_opcode (struct interrupt_frame *frame){
  printk("inval opcode");
}
__attribute__((interrupt))
void copr_not_available (struct interrupt_frame *frame){
  printk("copr not available");
}
__attribute__((interrupt))
void double_fault(struct interrupt_frame *frame){
  printk("double fault");
}
__attribute__((interrupt))
void copr_seg_overrun(struct interrupt_frame *frame){
  printk("copr seg overrun");
}
__attribute__((interrupt))
void inval_tss(struct interrupt_frame *frame){
  printk("inval tss");
}
__attribute__((interrupt))
void segment_not_present(struct interrupt_frame *frame){
  printk("segment not present");
}
__attribute__((interrupt))
void stack_exception(struct interrupt_frame *frame){
  printk("stack exception");
}
__attribute__((interrupt))
void general_protection(struct interrupt_frame *frame){
  printk("general protection");
}
__attribute__((interrupt))
void page_fault(struct interrupt_frame *frame){
  printk("[INTERRUPT] page fault interrupt");
  hlt();
}
__attribute__((interrupt))
void copr_error(struct interrupt_frame *frame){
  printk("copr error");
}
__attribute__((interrupt))
void alignment_check(struct interrupt_frame *frame){
  printk("alignment check");
}
__attribute__((interrupt))
void machine_check(struct interrupt_frame *frame){
  printk("machine check");
}
__attribute__((interrupt))
void simd_exception(struct interrupt_frame *frame){
  printk("simd exception");
}

/* software interrupt handlers */
__attribute__((interrupt))
void ipc_entry_softint_orig(struct interrupt_frame *frame){
  printk("ipc entry softint orig");
}
__attribute__((interrupt))
void ipc_entry_softint_um(struct interrupt_frame *frame){
  printk("ipc entry softint um");
}
__attribute__((interrupt))
void kernel_call_entry_orig(struct interrupt_frame *frame){
  printk("kernel call entry orig");
}
__attribute__((interrupt))
void kernel_call_entry_um(struct interrupt_frame *frame){
  printk("kernel call entry um");
}
