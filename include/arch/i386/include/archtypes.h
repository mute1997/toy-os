#include <asm/types.h>

#define LDT 2
#define GDT_ENTRIES 7
#define IDT_SIZE 256

#define GRANULARITY_SHIFT 16
#define PAGE_GRAN_SHIFT 12
#define DEFAULT 0x40

#define SEG_SELECTOR(i) ((i)*8)
#define KERN_CS_SELECTOR SEG_SELECTOR(KERN_CS_INDEX)

/* GDT Layout */
#define KERN_CS_INDEX 1
#define KERN_DS_INDEX 2
#define USER_CS_INDEX 3
#define USER_DS_INDEX 4
#define LDT_INDEX 5

/* GDT access byte */
#define PRESENT 0x80
#define SEGMENT 0x10
#define EXECUTABLE 0x08
#define DIRECTION 0x04
#define READABLE 0x02
#define WRITABLE 0x02
#define ACCESS 0x01

/* GDT Granularity byre */
#define GRANULAR 0x80

#define INT_286_GATE 6
#define DESC_386_BIT 0x08
#define INT_GATE_TYPE (INT_286_GATE | DESC_386_BIT)

/* Segment descriptor */
struct desc_struct {
  u16 limit_low;
  u16 base_low;
  u8 base_middle;
  u8 access;
  u8 granularity;
  u8 base_high;
} __attribute__((packed));

/* Gate Descriptor  */
struct gatedesc {
  u16 offset_low;
  u16 selector;
  u8 pad;
  u8 p_dp1_type;
  u16 offset_high;
} __attribute__((packed));

/* Descriptor table pointer */
struct desctableptr {
  u16 limit;
  u32 base;
} __attribute__((packed));

struct gate_table {
  void(*gate) (void);
  u8 vec_nr;
  u8 privilege;
};
