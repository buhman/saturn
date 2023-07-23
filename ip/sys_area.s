	.section .text.area

	bra	next
	nop
	.ascii "For ASIA PAL area."
	/* fill up to 32 bytes with the ascii ' ' (space) character */
	.balign 0x20, 0x20
next:
