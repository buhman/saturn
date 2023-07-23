	.section .text.areb

	bra	next
	nop
	.ascii "For BRAZIL."
	/* fill up to 32 bytes with the ascii ' ' (space) character */
	.balign 0x20, 0x20
next:
