#define MEMORY_HIGH_LIMIT 0x00EFFFFF

struct kmem {
  u32* phys_start;
  u32* phys_end;
};

int is_kernel_section(u32 addr);
void setup_physical_memory(u32 addr);
void setup_heap(void);
