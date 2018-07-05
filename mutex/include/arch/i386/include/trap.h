/* Privileges */
#define INTR_PRIVILEGE 0 /* kernel is ring 0 */
#define USER_PRIVILEGE 3 /* uesr is ring3 */

/* PIC commands */
#define PIC_MASTER_CMD 0x20
#define PIC_SLAVE_CMD  0xA0

/* PIC status */
#define PIC_MASTER_STATUS 0x20
#define PIC_SLAVE_STATUS  0xA0

/* PIC data */
#define PIC_MASTER_DATA 0x21
#define PIC_SLAVE_DATA  0xA1

/* PIC IMR */
#define PIC_MASTER_IMR 0x21
#define PIC_SLAVE_IMR  0xA1

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
#define SYSCALL_VECTOR 0x80

/* IRQ VECTOR */
#define IRQ0_VECTOR 0x50
#define IRQ8_VECTOR 0x70
#define VECTOR(irq)    \
       (((irq) < 8 ? IRQ0_VECTOR : IRQ8_VECTOR) + ((irq) & 0x07))


#ifdef __x86_64__
  typedef unsigned long long int uword_t;
#else
  typedef unsigned int uword_t;
#endif

struct interrupt_frame {
    uword_t ip;
    uword_t cs;
    uword_t flags;
    uword_t sp;
    uword_t ss;
};

/* stub interrupt */
void interrupt_stub(struct interrupt_frame *frame);

/* hardware interrupt handlers */
void hwint00(struct interrupt_frame *frame);
void hwint01(struct interrupt_frame *frame);
void hwint02(struct interrupt_frame *frame);
void hwint03(struct interrupt_frame *frame);
void hwint04(struct interrupt_frame *frame);
void hwint05(struct interrupt_frame *frame);
void hwint06(struct interrupt_frame *frame);
void hwint07(struct interrupt_frame *frame);
void hwint08(struct interrupt_frame *frame);
void hwint09(struct interrupt_frame *frame);
void hwint10(struct interrupt_frame *frame);
void hwint11(struct interrupt_frame *frame);
void hwint12(struct interrupt_frame *frame);
void hwint13(struct interrupt_frame *frame);
void hwint14(struct interrupt_frame *frame);
void hwint15(struct interrupt_frame *frame);

/* Exception handlers */
void divide_error (struct interrupt_frame *frame);
void single_step_exception (struct interrupt_frame *frame);
void nmi (struct interrupt_frame *frame);
void breakpoint_exception (struct interrupt_frame *frame);
void overflow (struct interrupt_frame *frame);
void bounds_check (struct interrupt_frame *frame);
void inval_opcode (struct interrupt_frame *frame);
void copr_not_available (struct interrupt_frame *frame);
void double_fault(struct interrupt_frame *frame);
void copr_seg_overrun(struct interrupt_frame *frame);
void inval_tss(struct interrupt_frame *frame);
void segment_not_present(struct interrupt_frame *frame);
void stack_exception(struct interrupt_frame *frame);
void general_protection(struct interrupt_frame *frame);
void page_fault(struct interrupt_frame *frame);
void copr_error(struct interrupt_frame *frame);
void alignment_check(struct interrupt_frame *frame);
void machine_check(struct interrupt_frame *frame);
void simd_exception(struct interrupt_frame *frame);

/* software interrupt handlers */
int syscall_handler();
