#include <asm/io.h>
#include <std/printk.h>
#include <trap.h>
#include <proto.h>

/* TODO */
void intr_init() {
  // printk("Initialize PIC... [OK]");
}

/* Disable master and slave */
void i8259_disable() {
  outb(INT2_CTLMASK, 0xFF);
  outb(INT_CTLMASK, 0xFF);
  inb(INT_CTLMASK);
}

/* End of interrupt for master */
void eoi_8259_master() {
  outb(INT_CTL, END_OF_INT);
}

/* End of interrupt for slave */
void eoi_8259_slave() {
  outb(INT_CTL, END_OF_INT);
  outb(INT2_CTL, END_OF_INT);
}

void irq_8259_eoi(int irq) {
  if (irq < 8)
    eoi_8259_master();
  else
    eoi_8259_slave();
}
