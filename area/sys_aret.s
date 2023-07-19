	.section .text.aret

	bra	next
	nop
	.ascii "For TAIWAN and PHILIPINES."
	/* fill up to 32 bytes with the ascii ' ' (space) character */
	.balign 0x20, 0x20
next:
