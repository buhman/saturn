	.section .text.aree

	bra	next
	nop
	.ascii "For EUROPE."
	/* fill up to 32 bytes with the ascii ' ' (space) character */
	.balign 0x20, 0x20
next:
