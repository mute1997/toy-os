global handle_intr

handle_intr:
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
