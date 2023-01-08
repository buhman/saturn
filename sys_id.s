        .section .text.id

        .ascii "SEGA SEGASATURN " /* 00: hardware identifier */
        .ascii "SEGA TP KAISHA-A" /* 10: maker ID */
        .ascii "999999999 V1.000" /* 20: product number, version */
        .ascii "19941122CD-1/1  " /* 30: release date, device information */
        .ascii "JTUE            " /* 40: compatible area symbol */
        .ascii "J               " /* 50: compatible peripheral */
        .ascii "GAME TITLE      " /* 60: game title */
        .ascii "                " /* 70: */
        .ascii "                " /* 80: */
        .ascii "                " /* 90: */
        .ascii "                " /* A0: */
        .ascii "                " /* B0: */
        .ascii "                " /* C0: */
        .long 0x00000000, 0x00000000, 0x00000000, 0x00000000 /* D0: */
        .long _text_size, 0x00000000, 0x00000000, 0x00000000 /* E0: IP SIZE, reserved, STACK-M, STACK-S */
        .long _load_addr, 0x00000000, 0x00000000, 0x00000000 /* F0: Transfer destination address */
        /* Larger than (60020000H+IP SIZE), smaller than (6100000-4) */

        /* IP SIZE of 0x1000 is manually calculated; this is coincidentally the
        /* exact size of ip.bin as generated */
