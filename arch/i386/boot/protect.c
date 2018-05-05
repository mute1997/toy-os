#include <asm/types.h>
#include <std/printk.h>
#include <std/string.h>
#include <archtypes.h>
#include <trap.h>

#define load_gdt(dtr) __asm__ __volatile__ ("lgdt %0"::"m"(dtr))
#define load_idt(dtr) __asm__ __volatile__("lidt %0"::"m" (*dtr))
#define init_seg() __asm__ __volatile__ ("\n \
    mov %ds,%ax \n \
    mov %es,%ax \n \
    mov %fs,%ax \n \
    mov %gs,%ax \n \
    mov %ss,%ax \n \
    ")

static struct desctableptr gdt_desc, idt_desc;
struct desc_struct gdt[GDT_ENTRIES]; /* GDT */
struct gatedesc idt[IDT_SIZE]; /* IDT */

static struct gate_table gate_table_pic[] = {
	{ hwint00, VECTOR( 0), INTR_PRIVILEGE },
	{ hwint01, VECTOR( 1), INTR_PRIVILEGE },
	{ hwint02, VECTOR( 2), INTR_PRIVILEGE },
	{ hwint03, VECTOR( 3), INTR_PRIVILEGE },
	{ hwint04, VECTOR( 4), INTR_PRIVILEGE },
	{ hwint05, VECTOR( 5), INTR_PRIVILEGE },
	{ hwint06, VECTOR( 6), INTR_PRIVILEGE },
	{ hwint07, VECTOR( 7), INTR_PRIVILEGE },
	{ hwint08, VECTOR( 8), INTR_PRIVILEGE },
	{ hwint09, VECTOR( 9), INTR_PRIVILEGE },
	{ hwint10, VECTOR(10), INTR_PRIVILEGE },
	{ hwint11, VECTOR(11), INTR_PRIVILEGE },
	{ hwint12, VECTOR(12), INTR_PRIVILEGE },
	{ hwint13, VECTOR(13), INTR_PRIVILEGE },
	{ hwint14, VECTOR(14), INTR_PRIVILEGE },
	{ hwint15, VECTOR(15), INTR_PRIVILEGE },
	{ NULL, 0, 0}
};

static struct gate_table gate_table_exceptions[] = {
	{ divide_error, DIVIDE_VECTOR, INTR_PRIVILEGE },
	{ single_step_exception, DEBUG_VECTOR, INTR_PRIVILEGE },
	{ nmi, NMI_VECTOR, INTR_PRIVILEGE },
	{ breakpoint_exception, BREAKPOINT_VECTOR, USER_PRIVILEGE },
	{ overflow, OVERFLOW_VECTOR, USER_PRIVILEGE },
	{ bounds_check, BOUNDS_VECTOR, INTR_PRIVILEGE },
	{ inval_opcode, INVAL_OP_VECTOR, INTR_PRIVILEGE },
	{ copr_not_available, COPROC_NOT_VECTOR, INTR_PRIVILEGE },
	{ double_fault, DOUBLE_FAULT_VECTOR, INTR_PRIVILEGE },
	{ copr_seg_overrun, COPROC_SEG_VECTOR, INTR_PRIVILEGE },
	{ inval_tss, INVAL_TSS_VECTOR, INTR_PRIVILEGE },
	{ segment_not_present, SEG_NOT_VECTOR, INTR_PRIVILEGE },
	{ stack_exception, STACK_FAULT_VECTOR, INTR_PRIVILEGE },
	{ general_protection, PROTECTION_VECTOR, INTR_PRIVILEGE },
	{ page_fault, PAGE_FAULT_VECTOR, INTR_PRIVILEGE },
	{ copr_error, COPROC_ERR_VECTOR, INTR_PRIVILEGE },
	{ alignment_check, ALIGNMENT_CHECK_VECTOR, INTR_PRIVILEGE },
	{ machine_check, MACHINE_CHECK_VECTOR, INTR_PRIVILEGE },
	{ simd_exception, SIMD_EXCEPTION_VECTOR, INTR_PRIVILEGE },
	{ ipc_entry_softint_orig, IPC_VECTOR_ORIG, USER_PRIVILEGE },
	{ kernel_call_entry_orig, KERN_CALL_VECTOR_ORIG, USER_PRIVILEGE },
	{ ipc_entry_softint_um, IPC_VECTOR_UM, USER_PRIVILEGE },
	{ kernel_call_entry_um, KERN_CALL_VECTOR_UM, USER_PRIVILEGE },
	{ NULL, 0, 0}
};

void int_gate(struct gatedesc *desc, unsigned vec_nr, u32 offset, unsigned dp1_type) {
  desc->offset_low = offset;
  desc->selector = KERN_CS_SELECTOR;
  desc->p_dp1_type = dp1_type;
  desc->offset_high = offset >> 16;
}

void idt_copy_vectors(struct gate_table* first) {
  struct gate_table *gtp;
  for (gtp=first;gtp->gate;gtp++) {
    int_gate(idt, gtp->vec_nr, (u32)gtp->gate, PRESENT | INT_GATE_TYPE | (gtp->privilege << 5));
  }
}

void idt_copy_vectors_pic() {
	idt_copy_vectors(gate_table_pic);
}

void idt_init() {
  idt_copy_vectors_pic();
  idt_copy_vectors(gate_table_exceptions);
}


/* Init Segment descriptor */
void init_segment(struct desc_struct *desc, u32 base, u32 size) {
  desc->base_low = base;
  desc->base_middle = base >> 16;
  desc->base_high = base >> 24;
  desc->limit_low = size >> 12;
  desc->granularity =  GRANULAR | (size >> (PAGE_GRAN_SHIFT + GRANULARITY_SHIFT)) | DEFAULT;
}

void init_data_segment(struct desc_struct *desc, u32 base, u32 size, int privilege) {
  init_segment(desc, base, size);
  desc->access = (privilege << 5) | (PRESENT | SEGMENT | WRITABLE);
}

void init_code_segment(struct desc_struct *desc, u32 base, u32 size, int privilege) {
  init_segment(desc, base, size);
  desc->access = (privilege << 5) | (PRESENT | SEGMENT | EXECUTABLE | READABLE);
}

void switch_to_new_idt() {
  idt_init();
  load_idt(&idt_desc);
}

void switch_to_new_gdt() {
  load_gdt(gdt_desc);
  init_seg();
}

void prot_load_selectors() {
  /* set new IDT */
  switch_to_new_idt();
  printk("Setup idt...  [OK]");

  /* set new GDT */
  switch_to_new_gdt();
  printk("Setup gdt...  [OK]");
}

void prot_init() {
  /* Init GDT */
  memset(gdt, 0, sizeof(gdt));
  memset(idt, 0, sizeof(idt));

  /* set GDT pointer */
  gdt_desc.base = (u32)gdt;
  gdt_desc.limit = sizeof(gdt)-1;
  idt_desc.base = (u32)idt;
  idt_desc.limit = sizeof(idt)-1;

  /* Init GDT segments */
  init_code_segment(&gdt[KERN_CS_INDEX], 0, 0xFFFFFFFF, KERNEL_PRIVILEGE); /* kernel code */
  init_data_segment(&gdt[KERN_DS_INDEX], 0, 0xFFFFFFFF, KERNEL_PRIVILEGE); /* kernel data */
  init_code_segment(&gdt[USER_CS_INDEX], 0, 0xFFFFFFFF, USER_PRIVILEGE); /* user code */
  init_data_segment(&gdt[USER_DS_INDEX], 0, 0xFFFFFFFF, USER_PRIVILEGE);  /* user data */
  init_segment(&gdt[LDT_INDEX], 0x0, 0); /* unusable LDT */
  gdt[LDT_INDEX].access = PRESENT | LDT;

  prot_load_selectors();
}
