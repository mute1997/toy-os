#include <std/printk.h>
#include <trap.h>


void hwint_master() {
  printk("HW Interrupt");
  __asm__ __volatile__ ("iret");
}

void interrupt() {
  printk("Interrupt");
  __asm__ __volatile__ ("iret");
}

void hwint00(void){
  hwint_master();
}
void hwint01(void){
  hwint_master();
}
void hwint02(void){
  hwint_master();
}
void hwint03(void){
  hwint_master();
}
void hwint04(void){
  hwint_master();
}
void hwint05(void){
  hwint_master();
}
void hwint06(void){
  hwint_master();
}
void hwint07(void){
  hwint_master();
}
void hwint08(void){
  hwint_master();
}
void hwint09(void){
  hwint_master();
}
void hwint10(void){
  hwint_master();
}
void hwint11(void){
  hwint_master();
}
void hwint12(void){
  hwint_master();
}
void hwint13(void){
  hwint_master();
}
void hwint14(void){
  hwint_master();
}
void hwint15(void){
  hwint_master();
}

void divide_error (void) {
  interrupt();
}
void single_step_exception (void){
  interrupt();
}
void nmi (void){
  interrupt();
}
void breakpoint_exception (void){
  interrupt();
}
void overflow (void){
  interrupt();
}
void bounds_check (void){
  interrupt();
}
void inval_opcode (void){
  interrupt();
}
void copr_not_available (void){
  interrupt();
}
void double_fault(void){
  interrupt();
}
void copr_seg_overrun(void){
  interrupt();
}
void inval_tss(void){
  interrupt();
}
void segment_not_present(void){
  interrupt();
}
void stack_exception(void){
  interrupt();
}
void general_protection(void){
  interrupt();
}
void page_fault(void){
  interrupt();
}
void copr_error(void){
  interrupt();
}
void alignment_check(void){
  interrupt();
}
void machine_check(void){
  interrupt();
}
void simd_exception(void){
  interrupt();
}

/* software interrupt handlers */
void ipc_entry_softint_orig(void){
  interrupt();
}
void ipc_entry_softint_um(void){
  interrupt();
}
void kernel_call_entry_orig(void){
  interrupt();
}
void kernel_call_entry_um(void){
  interrupt();
}
