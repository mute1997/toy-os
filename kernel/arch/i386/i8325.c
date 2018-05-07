#include <asm/io.h>
#include <asm/i8259.h>
#include <std/printk.h>
#include <trap.h>

/* TODO */
void intr_init() {
  // reprogram PCI
  // Initialize Commond Word
  // ICW1 : initialization for master & slave
  outb(0x20, 0x11);
  outb(0xA0, 0x11);
  // ICW2 : specify interrupt numbers
  outb(0x21, 0x20);      // PIC1 = 0x20-0x27
  outb(0xA1, 0x28);      // PIC2 = 0x28-0x2F
  // ICW3 : set pin wired to master/slaves
  outb(0x21, 0x4);
  outb(0xA1, 0x2);
  // ICW4 : set additional option
  outb(0x21, 0x1);
  outb(0xA1, 0x1);
  // Mask interrupts
  outb(0x21, 0xFD);
  outb(0xA1, 0xFF);
  printk("Initialize PIC... [OK]");
}

/* Disable master and slave */
void i8259_disable() {
  outb(INT2_CTLMASK, 0xFF);
  outb(INT_CTLMASK, 0xFF);
  inb(INT_CTLMASK);
}

/* TODO */
void eoi_8259_master() {
}

/* TODO */
void eoi_8259_slave() {
}

void irq_8259_eoi(int irq) {
  if (irq < 8)
    eoi_8259_master();
  else
    eoi_8259_slave();
}
