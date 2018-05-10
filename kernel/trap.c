/* TODO 割り込みハンドラはアセンブラで書くのでこのファイルはあとで消す*/

#include <std/printk.h>
#include <trap.h>


void hwint_master() {
  printk("HW Interrupt");
  __asm__ __volatile__ ("iret");
}

void interrupt() {
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
  printk("inval opcode");
}
void copr_not_available (void){
  printk("copr not available");
}
void double_fault(void){
  printk("double fault");
}
void copr_seg_overrun(void){
  printk("copr seg overrun");
}
void inval_tss(void){
  printk("inval tss");
}
void segment_not_present(void){
  printk("segment not present");
}
void stack_exception(void){
  printk("stack exception");
}
void general_protection(void){
  printk("general protection");
}
void page_fault(void){
  printk("page fault");
}
void copr_error(void){
  printk("copr error");
}
void alignment_check(void){
  printk("alignment check");
}
void machine_check(void){
  printk("machine check");
}
void simd_exception(void){
  printk("simd exception");
}

/* software interrupt handlers */
void ipc_entry_softint_orig(void){
  printk("ipc entry softint orig");
}
void ipc_entry_softint_um(void){
  printk("ipc entry softint um");
}
void kernel_call_entry_orig(void){
  printk("kernel call entry orig");
}
void kernel_call_entry_um(void){
  printk("kernel call entry um");
}
