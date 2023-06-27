        .section .vectors

        .long  0x7fffc /* Reset - initial stack pointer */
        .long  start  /* Reset - initial program counter */
        .long  exception  /* Bus error */
        .long  exception  /* Address error */
        .long  exception  /* Illegal command */
        .long  exception  /* Divide by zero */
        .long  exception  /* CHK exception */
        .long  exception  /* TRAPV exception */
        .long  exception  /* Privilege violation */
        .long  exception  /* Trace */
        .long  exception  /* Line 1010 emulator */
        .long  exception  /* Line 1111 emulator */
        .long  exception  /* reserved 12 */
        .long  exception  /* reserved 13 */
        .long  exception  /* reserved 14 */
        .long  exception  /* Uninitialized interrupt vector */
        .long  exception  /* reserved 16 */
        .long  exception  /* reserved 17 */
        .long  exception  /* reserved 18 */
        .long  exception  /* reserved 19 */
        .long  exception  /* reserved 20 */
        .long  exception  /* reserved 21 */
        .long  exception  /* reserved 22 */
        .long  exception  /* reserved 23 */
        .long  exception  /* Spurious interrupt */
        .long  auto_vector_1  /* Auto vector level 1 interrupt */
        .long  auto_vector_2  /* Auto vector level 2 interrupt */
        .long  auto_vector_3  /* Auto vector level 3 interrupt */
        .long  auto_vector_4  /* Auto vector level 4 interrupt */
        .long  auto_vector_5  /* Auto vector level 5 interrupt */
        .long  auto_vector_6  /* Auto vector level 6 interrupt */
        .long  auto_vector_7  /* Auto vector level 7 interrupt */
        .long  exception  /* Trap #0 vector */
        .long  exception  /* Trap #1 vector */
        .long  exception  /* Trap #2 vector */
        .long  exception  /* Trap #3 vector */
        .long  exception  /* Trap #4 vector */
        .long  exception  /* Trap #5 vector */
        .long  exception  /* Trap #6 vector */
        .long  exception  /* Trap #7 vector */
        .long  exception  /* Trap #8 vector */
        .long  exception  /* Trap #9 vector */
        .long  exception  /* Trap #10 vector */
        .long  exception  /* Trap #11 vector */
        .long  exception  /* Trap #12 vector */
        .long  exception  /* Trap #13 vector */
        .long  exception  /* Trap #14 vector */
        .long  exception  /* Trap #15 vector */
        .long  exception  /* reserved 48 */
        .long  exception  /* reserved 49 */
        .long  exception  /* reserved 50 */
        .long  exception  /* reserved 51 */
        .long  exception  /* reserved 52 */
        .long  exception  /* reserved 53 */
        .long  exception  /* reserved 54 */
        .long  exception  /* reserved 55 */
        .long  exception  /* reserved 56 */
        .long  exception  /* reserved 57 */
        .long  exception  /* reserved 58 */
        .long  exception  /* reserved 59 */
        .long  exception  /* reserved 60 */
        .long  exception  /* reserved 61 */
        .long  exception  /* reserved 62 */
        .long  exception  /* reserved 63 */

	.fill 0x300, 1, 0xee
