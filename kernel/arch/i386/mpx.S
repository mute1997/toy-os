; global hwint00
; global hwint01
; global hwint02
; global hwint03
; global hwint04
; global hwint05
; global hwint06
; global hwint07
; global hwint08
; global hwint09
; global hwint10
; global hwint11
; global hwint12
; global hwint13
; global hwint14
; global hwint15
; global divide_error
; global single_step_exception
; global nmi
; global breakpoint_exception
; global overflow
; global bounds_check
; global inval_opcode
; global copr_not_available
; global double_fault
; global copr_seg_overrun
; global inval_tss
; global segment_not_present
; global stack_exception
; global general_protection
; global page_fault
; global copr_error
; global alignment_check
; global machine_check
; global simd_exception
; global ipc_entry_softint_orig
; global ipc_entry_softint_um
; global kernel_call_entry_orig
; global kernel_call_entry_um

%define handle_intr
	pushad	
	push	ds
	push	es
	push	fs
	push	gs
	mov	al, 'A'
	mov	[0xb8000], al
	mov	al, 0x20
	out	0x20, al
	pop	gs
	pop	fs
	pop	es
	pop	ds
	popad
  iret

hwint00:
  handle_intr

hwint01:
  handle_intr
  
hwint02:
  handle_intr

hwint03:
  handle_intr
  
hwint04:
  handle_intr
  
hwint05:
  handle_intr
  
hwint06:
  handle_intr
  
hwint07:
  handle_intr
  
hwint08:
  handle_intr
  
hwint09:
  handle_intr
  
hwint10:
  handle_intr
  
hwint11:
  handle_intr
  
hwint12:
  handle_intr
  
hwint13:
  handle_intr
  
hwint14:
  handle_intr

hwint15:
  handle_intr
  
divide_error:
  handle_intr
  
single_step_exception:
  handle_intr
  
nmi:
  handle_intr
  
breakpoint_exception:
  handle_intr
  
overflow:
  handle_intr
  
bounds_check:
  handle_intr
  
inval_opcode:
  handle_intr
  
copr_not_available:
  handle_intr
  
double_fault:
  handle_intr
  
copr_seg_overrun:
  handle_intr
  
inval_tss:
  handle_intr
  
segment_not_present:
  handle_intr
  
stack_exception:
  handle_intr
  
general_protection:
  handle_intr
  
page_fault:
  handle_intr
  
copr_error:
  handle_intr
  
alignment_check:
  handle_intr
  
machine_check:
  handle_intr
  
simd_exception:
  handle_intr
  

; software interrupt handlers
ipc_entry_softint_orig:
  handle_intr
  
ipc_entry_softint_um:
  handle_intr
  
kernel_call_entry_orig:
  handle_intr
  
kernel_call_entry_um:
  handle_intr
