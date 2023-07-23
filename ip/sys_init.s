	/*
	This is a partial decompilation of sys_init.o from SBL6.

	This appears to have two independent purposes:

	- *((uint32_t*)(0x0)) = *((uint32_t*)(0x060002dc)) (not sure why that's useful)
	- copy 88 bytes starting at PATCHPG and ending at ENDOFPG to *(0x06000260)

	Execution continues at the code/section that immediately
	follows this one. This is by convention whatever is in
	`smpsys.c`.

	When assembled, this is byte-identical to sys_init.o from
	SBL6.
	*/

	.section .text.init

START:
	mov.l	A_INSTAL,r7 /* 0x06000260 */
	mov.l	A_SFTRES,r5 /* 0x060002dc */
	mov.l	@r7,r7
	mov.l	@r5,r3
	mova	PATSFTRS,r0 /* 0x00000000 */
	mov.l	r3,@r0

	/* "INSTALL" is roughly an inlined 'memcpy', which copies PATCHPG to A_INSTAL */
INSTALL:
	mova	PATCHPG,r0
	mov	r7,r1
	mov	#22,r2 /* PATCHPG is 88 bytes long, and is copied 4 bytes at a time */

INSTAL1:
	mov.l	@r0+,r4
	dt	r2
	mov.l	r4,@r1
	bf.s	INSTAL1
	add	#4,r1

SETHOOK:
	bra	ENDOFPG
	mov.l	r7,@r5

A_SFTRES:
	.word 0x0600
	.word 0x02dc

A_INSTAL:
	.word 0x0600
	.word 0x0260

PATCHPG:
	mov.w	A_CCR,r3 /* 0xfe92 */
	mov	#0,r0
	mov.b	r0,@r3
	mov	#16,r0
	mov.b	r0,@r3
	mov.l	@r15+,r0
	mov.l	A_DEFSTK,r15 /* 0x06002000 */
	mov.l	r0,@-r15
	mov.l	PATSFTRS,r1 /* 0x00000000 */
	mov	#1,r0
	mov	#3,r4
	sts.l	pr,@-r15
	jsr	@r1
	mov.b	r0,@r3

_CDPAT_InitSctLen:
	mov.l	CDB_HIRQ,r5 /* 0x25890008 */
	mov	#-2,r3
	mov.w	r3,@r5
	mov.w	CONST_6000,r0 /* 0x6000 */
	mov.w	r0,@(16,r5)
	mov	#0,r0
	mov.w	r0,@(20,r5)
	mov.w	r0,@(24,r5)
	mov.w	r0,@(28,r5)
	mov.w	CONST_0900,r7 /* 0x0900 */
LOOP:
	mov.w	@r5,r0
	tst	#1,r0
	bf	BREAK_LOOP
	dt	r7
	bf	LOOP
BREAK_LOOP:
	mov.w	@(16,r5),r0
	mov.w	@(20,r5),r0
	lds.l	@r15+,pr
	mov.w	@(24,r5),r0
	rts
	mov.w	@(28,r5),r0

CONST_6000:
	.word 0x6000
CONST_0900:
	.word 0x0900
A_CCR:
	.word 0xfe92
CDB_HIRQ:
	.word 0x2589
	.word 0x0008

A_DEFSTK:
	.word 0x0600
	.word 0x2000

PATSFTRS:
	.word 0x0000
	.word 0x0000
ENDOFPG:
