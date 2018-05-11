#include <std/printk.h>
#include <trap.h>

void hwint00(struct interrupt_frame *frame){
  printk("hwint00");
}
void hwint01(struct interrupt_frame *frame){
  printk("hwint01");
}
void hwint02(struct interrupt_frame *frame){
  printk("hwint02");
}
void hwint03(struct interrupt_frame *frame){
  printk("hwint03");
}
void hwint04(struct interrupt_frame *frame){
  printk("hwint04");
}
void hwint05(struct interrupt_frame *frame){
  printk("hwint05");
}
void hwint06(struct interrupt_frame *frame){
  printk("hwint06");
}
void hwint07(struct interrupt_frame *frame){
  printk("hwint07");
}
void hwint08(struct interrupt_frame *frame){
  printk("hwint08");
}
void hwint09(struct interrupt_frame *frame){
  printk("hwint09");
}
void hwint10(struct interrupt_frame *frame){
  printk("hwint10");
}
void hwint11(struct interrupt_frame *frame){
  printk("hwint11");
}
void hwint12(struct interrupt_frame *frame){
  printk("hwint12");
}
void hwint13(struct interrupt_frame *frame){
  printk("hwint13");
}
void hwint14(struct interrupt_frame *frame){
  printk("hwint14");
}
void hwint15(struct interrupt_frame *frame){
  printk("hwint15");
}

void divide_error (struct interrupt_frame *frame) {
  printk("divide error");
}
void single_step_exception (struct interrupt_frame *frame){
  printk("single step exception");
}
void nmi (struct interrupt_frame *frame){
  printk("nmi");
}
__attribute__((interrupt))
void breakpoint_exception (struct interrupt_frame *frame){
  printk("breakpoint exception");
}
void overflow (struct interrupt_frame *frame){
  printk("overflow");
}
void bounds_check (struct interrupt_frame *frame){
  printk("bounds check");
}
void inval_opcode (struct interrupt_frame *frame){
  printk("inval opcode");
}
void copr_not_available (struct interrupt_frame *frame){
  printk("copr not available");
}
void double_fault(struct interrupt_frame *frame){
  printk("double fault");
}
void copr_seg_overrun(struct interrupt_frame *frame){
  printk("copr seg overrun");
}
void inval_tss(struct interrupt_frame *frame){
  printk("inval tss");
}
void segment_not_present(struct interrupt_frame *frame){
  printk("segment not present");
}
void stack_exception(struct interrupt_frame *frame){
  printk("stack exception");
}
void general_protection(struct interrupt_frame *frame){
  printk("general protection");
}
void page_fault(struct interrupt_frame *frame){
  printk("page fault");
}
void copr_error(struct interrupt_frame *frame){
  printk("copr error");
}
void alignment_check(struct interrupt_frame *frame){
  printk("alignment check");
}
void machine_check(struct interrupt_frame *frame){
  printk("machine check");
}
void simd_exception(struct interrupt_frame *frame){
  printk("simd exception");
}

/* software interrupt handlers */
void ipc_entry_softint_orig(struct interrupt_frame *frame){
  printk("ipc entry softint orig");
}
void ipc_entry_softint_um(struct interrupt_frame *frame){
  printk("ipc entry softint um");
}
void kernel_call_entry_orig(struct interrupt_frame *frame){
  printk("kernel call entry orig");
}
void kernel_call_entry_um(struct interrupt_frame *frame){
  printk("kernel call entry um");
}
