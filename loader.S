#include "multiboot.h"

.text
.code32 // 32bitコード
.intel_syntax noprefix // intelスタイル

.global _start
_start:
  jmp entry
  .align 4 // 4バイトごとにアライン
  .long MULTIBOOT_HEADER_MAGIC // 32ビットのMULTIBOOT_HEADER_MAGICを領域に確保する
  .long MULTIBOOT_HEADER_FLAGS
  .long MULTIBOOT_HEADER_CHECKSUM

entry:
  push ebx // multiboot_info構造体のポインタをプッシュ
  push eax // MBOOT_HEADER_MAGICをプッシュ
  jmp main // mainにジャンプ
