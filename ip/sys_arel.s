	.section .text.arel

	bra	next
	nop
	.ascii "For LATIN AMERICA."
	/* fill up to 32 bytes with the ascii ' ' (space) character */
	.balign 0x20, 0x20
next:
