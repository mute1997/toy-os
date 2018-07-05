#include <asm/io.h>
#include <std/printk.h>
#include <trap.h>
#include <proto.h>
#include <i8325.h>

#define ICW1_ICW4	0x01		/* ICW4 (not) needed */
#define ICW1_SINGLE	0x02		/* Single (cascade) mode */
#define ICW1_INTERVAL4	0x04		/* Call address interval 4 (8) */
#define ICW1_LEVEL	0x08		/* Level triggered (edge) mode */
#define ICW1_INIT	0x10		/* Initialization - required! */
 
#define ICW4_8086	0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO	0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		/* Buffered mode/master */
#define ICW4_SFNM	0x10		/* Special fully nested (not) */

/* 
 * Initialize PIC 
 * IRQ0 80 ~ 87
 * IRQ1 112 ~ 119
 */
void intr_init() {
  /* Disable PIC */
  outb(PIC_MASTER_IMR, 0xFF);
  outb(PIC_SLAVE_IMR, 0xFF);
  
  /* Master, Slave ICW1*/
  outb(PIC_MASTER_CMD, 0x11); /* edge trigger mode */
  outb(PIC_SLAVE_CMD, 0x11); /* edge trigger mode */
  
  /* Master, Slave ICW2 */
  outb(PIC_MASTER_DATA, IRQ0_VECTOR); /* IRQ0_VECTOR ~ IRQ0_VECTOR + 7*/ 
  outb(PIC_SLAVE_DATA, IRQ8_VECTOR); /* IRQ8_VECTOR ~ IRQ8_VECTOR+7*/
  
  /* Master, Slave ICW3*/
  outb(PIC_MASTER_DATA, 1<<2);
  outb(PIC_SLAVE_DATA, 0x02);
  
  /* Master, Slave ICW4 */
  outb(PIC_MASTER_DATA, 0x01); /* Non buffer mode */
  outb(PIC_MASTER_DATA, 0x01); /* Non buffer mode */
  
  /* mask all irq */
  outb(PIC_MASTER_DATA, 0xff);
  outb(PIC_SLAVE_DATA, 0xff);

  /* enable keyboard */
  /* TODO remove later */
  outb(PIC_MASTER_IMR, 0xfd);
  outb(PIC_SLAVE_IMR, 0xff);

  enable_intr();

  printk("Initialize PIC... [OK]\n");
}

/* End of interrupt */
void irq_8259_eoi(int irq) {
  if (irq >= 8)
    outb(PIC_SLAVE_CMD, END_OF_INT);
  outb(PIC_MASTER_CMD, END_OF_INT);
}
