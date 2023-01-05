#include "vdp2.h"
#include "smpc.h"
#include "scu.h"

        .section .text

        /* vdp2 */

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
        //add r2,r1  /* add bktal offset from above */
        mov #31,r2 /* blue (RGB15) */
        //shll2 r2
        shll8 r2
        mov r1,r8
        mov r2,r9

        bra _smpc
        nop

        .align 4
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

        /* smpc */
_smpc:
        /* set smpc interrupt vector */
        mov.l vec_table_sm,r1
        mov.l smpc_vector_ptr,r2
        mov.l r2,@r1

        /* enable SM interrupts */
        mov.l ims,r1
        mov.l ims_v,r2
        mov.l @r1,r3
        //and r3,r2
        mov.l r2,@r1

        bra _port1
        nop

        .align 4
vec_table_sm:      .long (0x06000000 + (0x47 * 4))
smpc_vector_ptr:   .long smpc_vector
ims:               .long (CACHE_THROUGH | (SCU_BASE + IMS))
ims_v:             .long (~(IMS__SM))

_port1:
        /* port1 as a input port */
        mov #0,r2
        mov.l ddr1,r1
        mov.b r2,@r1
        mov.l exle,r1
        mov.b r2,@r1
        mov.l iosel,r1
        mov.b r2,@r1

input_loop:
        mov.w r9,@r8

        mov.l tvstat,r1
wait_vblank_out:
        mov.l tvstat,r1
        mov.w   @r1,r0
        tst     #TVSTAT__VBLANK,r0
        bf      wait_vblank_out
wait_vblank_in:
        mov.l tvstat,r1
        mov.w   @r1,r0
        tst     #TVSTAT__VBLANK,r0
        bt      wait_vblank_in

        /* wait for SF to be reset */
        mov.l sf,r1
wait_sf_reset:
        mov.l sf,r1
        mov.b @r1,r0
        tst #1,r0
        bf wait_sf_reset

        /* set SF */
        mov.l sf,r1
        mov #1,r2
        mov.b r2,@r1

        /* set ireg */
        mov.l ireg0,r1
        mov.w ireg0_v,r2
        mov.b r2,@r1

        mov.l ireg1,r1
        mov.w ireg1_v,r2
        mov.b r2,@r1

        mov.l ireg2,r1
        mov.w ireg2_v,r2
        mov.b r2,@r1

        /* issue INTBACK */
        mov.l comreg,r1
        mov #SMPC_INTBACK,r2
        mov.b r2,@r1

        bra input_loop
        nop

        .align 4
tvstat:         .long (CACHE_THROUGH | (VDP2_BASE + TVSTAT))
iosel:          .long (CACHE_THROUGH | (SMPC_BASE + IOSEL))
exle:           .long (CACHE_THROUGH | (SMPC_BASE + EXLE))
ddr1:           .long (CACHE_THROUGH | (SMPC_BASE + DDR1))
comreg:         .long (CACHE_THROUGH | (SMPC_BASE + COMREG))
ireg0:          .long (CACHE_THROUGH | (SMPC_BASE + IREG0))
ireg1:          .long (CACHE_THROUGH | (SMPC_BASE + IREG1))
ireg2:          .long (CACHE_THROUGH | (SMPC_BASE + IREG2))
sf:             .long (CACHE_THROUGH | (SMPC_BASE + SF))
ireg0_v:        .word (SMPC_INTBACK__IREG0__STATUS_DISABLE)
ireg1_v:        .word (SMPC_INTBACK__IREG1__PERIPHERAL_DATA_ENABLE | SMPC_INTBACK__IREG1__PORT2_15BYTE | SMPC_INTBACK__IREG1__PORT1_15BYTE )
ireg2_v:        .word (SMPC_INTBACK__IREG2__MAGIC)

        /* scu-user-manual says "System Manager" is bit 7, Vector 47h (71), level 8 */
        /* the vector table is controlled by VBR */
        /* "SH7604 Hardware Manual" says LDC/SDC can interact with VBR */

        /* Kronos fills the vector table with '0x06000600', which is in turn an
           `rte` instruction.
        */


        .align 4
smpc_vector:
        add r13,r6

        /* reset interrupt status */
        mov.l _ist,r1
        mov #0,r2
        mov.l r2,@r1

        /*
        port status
        peripheral 1 data {peripheral type, data size}
          data
        */


        mov.l _sr,r1
        mov.b @r1,r2
        mov.l oreg0,r1
        mov.b @r1,r3
        mov.l oreg1,r1
        mov.b @r1,r4
        mov.l oreg2,r1
        mov.b @r1,r0
        mov.l oreg3,r1
        mov.b @r1,r5

        tst #1,r0 // 1 if ((r0 & 1) == 0) else 0
        bf not_red
        nop

        bra red
        nop

        .align 4
_ist:              .long (CACHE_THROUGH | (SCU_BASE + IST))
_sr:               .long (CACHE_THROUGH | (SMPC_BASE + SR))
oreg0:             .long (CACHE_THROUGH | (SMPC_BASE + OREG0)) // port status
oreg1:             .long (CACHE_THROUGH | (SMPC_BASE + OREG1)) // {type:4, size:4}
oreg2:             .long (CACHE_THROUGH | (SMPC_BASE + OREG2)) // 1st data
oreg3:             .long (CACHE_THROUGH | (SMPC_BASE + OREG3)) // 2nd data

red:
        mov.l vram2,r1
        mov #31,r2 /* red (RGB15) */
        mov.w r2,@r1

not_red:
        /* set ireg break */
        mov.l ireg0_2,r1
        mov.w ireg0_v_2,r2
        mov.b r2,@r1

        rte
        nop
        nop

        .align 4
vram2:           .long (CACHE_THROUGH | (VDP2_BASE + VRAM))
ireg0_2:          .long (CACHE_THROUGH | (SMPC_BASE + IREG0))
comreg_2:         .long (CACHE_THROUGH | (SMPC_BASE + COMREG))
ireg0_v_2:        .word (SMPC_INTBACK__IREG0__BREAK | SMPC_INTBACK__IREG0__STATUS_DISABLE)
