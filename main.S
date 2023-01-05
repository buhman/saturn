#include "vdp2.h"

        .section .text

        /* set TV Mode (see the definition of tvmd_* below) */
        mov.l tvmd,r1
        mov.w tvmd_v,r2
        mov.w tvmd_r,r3
        or r3,r2
        mov.w r2,@r1

        /* turn off all screens (make BACK visible) */
        mov.l bgon,r1
        mov #0,r2
        mov.w r2,@r1

        /* set the Back Screen color mode to "single color" */
        /* set the high bits of the Back Screen Table Address to zero */
        mov.l bktau,r1
        mov.w bktau_v,r2
        mov.w r2,@r1

        /* set the low bits of Back Screen Table Address */
        /* (relative to the beginning of VDP2 VRAM) */
        mov.l bktal,r1
        mov.w bktal_v,r2
        mov.w r2,@r1

        /* write "red" to VDP2 VRAM */
        mov.l vram,r1
        add r2,r1  /* add bktal offset from above */
        mov #31,r2 /* red (RGB15) */
        mov.w r2,@r1

        /* */

forever:
        bra forever
        nop

        .align 4
tvstat:         .long (CACHE_THROUGH | (VDP2_BASE + TVSTAT))

tvmd:           .long (CACHE_THROUGH | (VDP2_BASE + TVMD))
tvmd_v:         .word (TVMD__DISP | TVMD__BDCLMD | TVMD__LSMD__NON_INTERLACE)
tvmd_r:         .word (TVMD__VRESO__240 | TVMD__HRESO__NORMAL_320)

bktal:          .long (CACHE_THROUGH | (VDP2_BASE + BKTAL))
bktal_v:        .long 32768

bgon:           .long (CACHE_THROUGH | (VDP2_BASE + BGON))

bktau:          .long (CACHE_THROUGH | (VDP2_BASE + BKTAU))
bktau_v:        .word (BKTAU__BKCLMD_SINGLE_COLOR)

        .align 4
ramctl:         .long (CACHE_THROUGH | (VDP2_BASE + RAMCTL))

vram:           .long (CACHE_THROUGH | (VDP2_BASE + VRAM))
