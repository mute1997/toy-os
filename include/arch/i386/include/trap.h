/* Privileges */
#define INTR_PRIVILEGE 0 /* kernel is ring 0 */
#define USER_PRIVILEGE 3 /* uesr is ring3 */

/* 8251A interrupt controller ports */
#define INT_CTL 0x20
#define INT_CTLMASK 0x21
#define INT2_CTL 0xA0
#define INT2_CTLMASK 0xA1

/* EOI */
#define END_OF_INT 0x20

/* Interrupt by processor */
#define DIVIDE_VECTOR 0
#define DEBUG_VECTOR 1
#define NMI_VECTOR 2
#define BREAKPOINT_VECTOR 3
#define OVERFLOW_VECTOR 4
#define BOUNDS_VECTOR 5
#define INVAL_OP_VECTOR 6
#define COPROC_NOT_VECTOR 7
#define DOUBLE_FAULT_VECTOR 8
#define COPROC_SEG_VECTOR 9
#define INVAL_TSS_VECTOR 10
#define SEG_NOT_VECTOR 11
#define STACK_FAULT_VECTOR 12
#define PROTECTION_VECTOR 13
#define PAGE_FAULT_VECTOR 14
#define COPROC_ERR_VECTOR 16
#define ALIGNMENT_CHECK_VECTOR 17
#define MACHINE_CHECK_VECTOR 18
#define SIMD_EXCEPTION_VECTOR 19

/* system call vector */
#define KERN_CALL_VECTOR_ORIG 32
#define IPC_VECTOR_ORIG 33
#define KERN_CALL_VECTOR_UM 34
#define IPC_VECTOR_UM 35

/* IRQ VECTOR */
#define IRQ0_VECTOR 0x50
#define IRQ8_VECTOR 0x70
#define VECTOR(irq)    \
       (((irq) < 8 ? IRQ0_VECTOR : IRQ8_VECTOR) + ((irq) & 0x07))

/* hardware interrupt handlers */
void hwint00(void);
void hwint01(void);
void hwint02(void);
void hwint03(void);
void hwint04(void);
void hwint05(void);
void hwint06(void);
void hwint07(void);
void hwint08(void);
void hwint09(void);
void hwint10(void);
void hwint11(void);
void hwint12(void);
void hwint13(void);
void hwint14(void);
void hwint15(void);

/* Exception handlers */
void divide_error (void);
void single_step_exception (void);
void nmi (void);
void breakpoint_exception (void);
void overflow (void);
void bounds_check (void);
void inval_opcode (void);
void copr_not_available (void);
void double_fault(void);
void copr_seg_overrun(void);
void inval_tss(void);
void segment_not_present(void);
void stack_exception(void);
void general_protection(void);
void page_fault(void);
void copr_error(void);
void alignment_check(void);
void machine_check(void);
void simd_exception(void);

/* software interrupt handlers */
void ipc_entry_softint_orig(void);
void ipc_entry_softint_um(void);
void kernel_call_entry_orig(void);
void kernel_call_entry_um(void);
