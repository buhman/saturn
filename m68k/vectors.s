        .section .vectors

        .long  0x7fffc /* Reset - initial stack pointer */
        .long  start  /* Reset - initial program counter */
        .long  start  /* Bus error */
        .long  start  /* Address error */
        .long  start  /* Illegal command */
        .long  start  /* Divide by zero */
        .long  start  /* CHK exception */
        .long  start  /* TRAPV exception */
        .long  start  /* Privilege violation */
        .long  start  /* Trace */
        .long  start  /* Line 1010 emulator */
        .long  start  /* Line 1111 emulator */
        .long  start  /* reserved 12 */
        .long  start  /* reserved 13 */
        .long  start  /* reserved 14 */
        .long  start  /* Uninitialized interrupt vector */
        .long  start  /* reserved 16 */
        .long  start  /* reserved 17 */
        .long  start  /* reserved 18 */
        .long  start  /* reserved 19 */
        .long  start  /* reserved 20 */
        .long  start  /* reserved 21 */
        .long  start  /* reserved 22 */
        .long  start  /* reserved 23 */
        .long  start  /* Spurious interrupt */
        .long  auto_vector_1  /* Auto vector level 1 interrupt */
        .long  auto_vector_2  /* Auto vector level 2 interrupt */
        .long  auto_vector_3  /* Auto vector level 3 interrupt */
        .long  auto_vector_4  /* Auto vector level 4 interrupt */
        .long  auto_vector_5  /* Auto vector level 5 interrupt */
        .long  auto_vector_6  /* Auto vector level 6 interrupt */
        .long  auto_vector_7  /* Auto vector level 7 interrupt */
        .long  start  /* Trap #0 vector */
        .long  start  /* Trap #1 vector */
        .long  start  /* Trap #2 vector */
        .long  start  /* Trap #3 vector */
        .long  start  /* Trap #4 vector */
        .long  start  /* Trap #5 vector */
        .long  start  /* Trap #6 vector */
        .long  start  /* Trap #7 vector */
        .long  start  /* Trap #8 vector */
        .long  start  /* Trap #9 vector */
        .long  start  /* Trap #10 vector */
        .long  start  /* Trap #11 vector */
        .long  start  /* Trap #12 vector */
        .long  start  /* Trap #13 vector */
        .long  start  /* Trap #14 vector */
        .long  start  /* Trap #15 vector */
        .long  start  /* reserved 48 */
        .long  start  /* reserved 49 */
        .long  start  /* reserved 50 */
        .long  start  /* reserved 51 */
        .long  start  /* reserved 52 */
        .long  start  /* reserved 53 */
        .long  start  /* reserved 54 */
        .long  start  /* reserved 55 */
        .long  start  /* reserved 56 */
        .long  start  /* reserved 57 */
        .long  start  /* reserved 58 */
        .long  start  /* reserved 59 */
        .long  start  /* reserved 60 */
        .long  start  /* reserved 61 */
        .long  start  /* reserved 62 */
        .long  start  /* reserved 63 */

        .align 0x400, 0xee
