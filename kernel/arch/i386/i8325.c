#include <asm/io.h>
#include <asm/i8259.h>
#include <std/printk.h>
#include <trap.h>

/* TODO */
void intr_init() {
  printk("Initialize PIC... [OK]");
}

/* Disable master and slave */
void i8259_disable() {
  // outb(INT2_CTLMASK, 0xFF);
  // outb(INT_CTLMASK, 0xFF);
  // inb(INT_CTLMASK);
}

/* TODO */
void eoi_8259_master() {
}

/* TODO */
void eoi_8259_slave() {
}

/* TODO */
void irq_8259_eoi(int irq) {
  if (irq < 8)
    eoi_8259_master();
  else
    eoi_8259_slave();
}
