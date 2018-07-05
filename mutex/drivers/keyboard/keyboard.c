#include <drivers/keyboard.h>
#include <mm.h>

char scancodes[0xff];
char shifted_scancodes[0xff];
int is_pressed_shift = NOT_PRESS;

void init_keyboard() {
  memset(scancodes, NULL, sizeof(scancodes));

  int alphabet[] = {
    0x1e, 0x30, 0x2e, 0x20, 0x12,
    0x21, 0x22, 0x23, 0x17, 0x24,
    0x25, 0x26, 0x32, 0x31, 0x18,
    0x19, 0x10, 0x13, 0x1f, 0x14,
    0x16, 0x2f, 0x11, 0x2d, 0x15,
    0x2c};

  int numbers[] = {0x0b, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a};

  // alphabet
  char a = 'a';
  int index;
  for (int i=0;i<26;i++) {
    index = alphabet[i];
    scancodes[index] = a;
    a++;
  }

  // number
  char n = '0';
  for (int i=0;i<10;i++) {
    index = numbers[i];
    scancodes[index] = n;
    n++;
  }

  // number
  shifted_scancodes[0x0b] = ')';
  shifted_scancodes[0x02] = '!';
  shifted_scancodes[0x03] = '@';
  shifted_scancodes[0x04] = '#';
  shifted_scancodes[0x05] = '$';
  shifted_scancodes[0x06] = '%';
  shifted_scancodes[0x07] = '^';
  shifted_scancodes[0x08] = '&';
  shifted_scancodes[0x09] = '*';
  shifted_scancodes[0x0a] = '(';
}

char get_char_from_scancode(int scancode) {
  // shift
  if (scancode == 0x2a || scancode == 0x36) {
    is_pressed_shift = PRESS;
  } else if (scancode == 0xaa || scancode == 0xb6) {
    is_pressed_shift = NOT_PRESS;
  }

  if (is_pressed_shift) return shifted_scancodes[scancode];
  return scancodes[scancode];
}
