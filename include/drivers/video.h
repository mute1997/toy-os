#define	VRAM_MODE	0xC00B8000
#define COLOR_LIGHTGREY 0x07

void flush_screen(void);
void put_str(int mode, int x, int y, int color, char *s);
