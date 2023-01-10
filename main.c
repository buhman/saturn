#include "vdp2.h"
#include "vdp1.h"
#include "scu.h"
#include "smpc.h"
#include "sh2.h"

void fill_32(u32 * buf, u32 v, s32 n)
{
  while (n > 0) {
    *buf = v;
    buf += 1;
    n -= (sizeof (u32));
  }
}

void timer0_int(void) __attribute__ ((interrupt_handler));
void timer0_int(void)
{
  scu.reg.IST &= ~(IST__TIMER0);
}

void oci_int(void) __attribute__ ((interrupt_handler));
void oci_int(void)
{
  // clear OCFA
  sh2.reg.FTCSR &= ~(FTCSR__OCFA);

  while (smpc.reg.SF != 0) {}

  smpc.reg.SF = 0;

  smpc.reg.IREG0 = INTBACK__IREG0__STATUS_DISABLE;
  smpc.reg.IREG1 = ( INTBACK__IREG1__PERIPHERAL_DATA_ENABLE
                   | INTBACK__IREG1__PORT2_15BYTE
                   | INTBACK__IREG1__PORT1_15BYTE
                   );
  smpc.reg.IREG2 = INTBACK__IREG2__MAGIC;

  smpc.reg.COMREG = COMREG__INTBACK;
}

void smpc_int(void) __attribute__ ((interrupt_handler));
void smpc_int(void)
{
  scu.reg.IST &= ~(IST__SMPC);



  smpc.reg.IREG0 = INTBACK__IREG0__BREAK;
}

void start(void)
{
  //
  // vdp2: enable and set Back Screen color
  //

  vdp2.reg.TVMD = ( TVMD__DISP | TVMD__BDCLMD | TVMD__LSMD__NON_INTERLACE
                  | TVMD__VRESO__240 | TVMD__HRESO__NORMAL_320);

  vdp2.reg.BGON = 0;

  // BKTAU/BKTAL are shifted left 1: (0x4000 << 1 = 0x8000)
  vdp2.reg.BKTA = REG_UL(BKTAU__BKCLMD_SINGLE_COLOR, 0x4000);

  // background color, rgb15
  vdp2.vram.u16[0x8000 / 2] = (0x05 << 0); // dark red

  //
  // vdp2: define and place a single character on NBG0
  //

  vdp2.reg.BGON = BGON__N0ON;

  vdp2.reg.CHCTLA = ( CHCTLA__N0CHCN__16_COLOR     // 4 bits per pixel, palettized
                    | CHCTLA__N0BMSZ__512x512_DOT
                    | CHCTLA__N0BMEN__CELL_FORMAT
                    | CHCTLA__N0CHSZ__1x1_CELL
                    );

  vdp2.reg.PNCN0 = PNCN0__N0PNB__2WORD;

  vdp2.reg.PLSZ = PLSZ__N0PLSZ__1x1;

  vdp2.vram.u16[16 +  0] = (1 << 12); // top left pixel of character # 1
  vdp2.vram.u16[16 + 15] = (2 << 0 ); // bottom right pixel of character # 1

  vdp2.cram.u16[1] = (0x31 << 5);  // green
  vdp2.cram.u16[2] = (0x31 << 10); // blue

  // given:
  //   Plane Size: 1h X 1v
  //   Pattern Name Data Size: 2 Words
  // only bits 5~0 are used for map address calculation
  // so MPOFN is effectively ignored
  vdp2.reg.MPOFN = MPOFN__N0MP(0); // bits 8~6
  vdp2.reg.MPABN0 = MPABN0__N0MPB(0) | MPABN0__N0MPA(1); // bits 5~0
  vdp2.reg.MPCDN0 = MPABN0__N0MPB(0) | MPABN0__N0MPA(1); // bits 5~0

  // zeroize NBG0 plane; this should be less than 0x8000 above
  s32 plane_size = 64 * 64 * 4; // is this correct ?
  fill_32(&vdp2.vram.u32[(0x4000 / 4)], 0, plane_size);

  // Table 4.8  Address value of map designated register by setting
  // (bit 5~0) * 0x4000
  vdp2.vram.u32[(0x4000 / 4)] = PATTERN_NAME_TABLE_2WORD__CHARACTER(1);

  //
  // vdp1:
  //

  // The VBE setting must be set immediately after the V-blank IN interrupt.
  //
  // TVM settings must be performed from the second H-blank IN interrupt after
  // the V-blank IN interrupt to the H-blank IN interrupt immediately after the
  // V-blank OUT interrupt.
  vdp1.reg.TVMR = ( TVMR__TVM__NTSC_PAL
                  | TVMR__TVM__FRAMEBUFFER_NONROTATION
                  | TVMR__TVM__16BPP
                  );

  // make FCM and FCT settings immediately after V-blank OUT
  vdp1.reg.FBCR = 0;

  // "A command table must always be stored at address 00000H to 0001EH."
  // we can't trigger a plot yet because we have no (valid) table.
  //vdp1.reg.PTMR = PTMR__PTM__FRAME_CHANGE;

  vdp1.reg.EWDR = 0; // black

  // upper-left
  vdp1.reg.EWLR = PTMR__EWLR__16BPP_X1(0) | PTMR__EWLR__Y1(0);

  // lower-right
  vdp1.reg.EWRR = PTMR__EWRR__16BPP_X3(319) | PTMR__EWRR__Y3(239);

  vdp1.vram.cmd[0].CTRL = CTRL__JP__JUMP_NEXT | CTRL__COMM__USER_CLIP_COORDINATES;
  vdp1.vram.cmd[0].LINK = 0;
  vdp1.vram.cmd[0].XA = 0;
  vdp1.vram.cmd[0].YA = 0;
  vdp1.vram.cmd[0].XC = 319;
  vdp1.vram.cmd[0].YC = 239;

  vdp1.vram.cmd[1].CTRL = CTRL__JP__JUMP_NEXT | CTRL__COMM__SYSTEM_CLIP_COORDINATES;
  vdp1.vram.cmd[1].LINK = 0;
  vdp1.vram.cmd[1].XC = 319;
  vdp1.vram.cmd[1].YC = 239;

  vdp1.vram.cmd[2].CTRL = CTRL__JP__JUMP_NEXT | CTRL__COMM__LOCAL_COORDINATE;
  vdp1.vram.cmd[2].LINK = 0;
  vdp1.vram.cmd[2].XA = 0;
  vdp1.vram.cmd[2].YA = 0;

  vdp1.vram.cmd[3].CTRL = CTRL__JP__JUMP_NEXT | CTRL__COMM__POLYGON;
  vdp1.vram.cmd[3].LINK = 0;
  vdp1.vram.cmd[3].PMOD = CTRL__PMOD__ECD | CTRL__PMOD__SPD;
  vdp1.vram.cmd[3].COLR = 0x2; // palette color #2
  vdp1.vram.cmd[3].XA = 50;
  vdp1.vram.cmd[3].YA = 50;
  vdp1.vram.cmd[3].XB = 150;
  vdp1.vram.cmd[3].YB = 50;
  vdp1.vram.cmd[3].XC = 150;
  vdp1.vram.cmd[3].YC = 150;
  vdp1.vram.cmd[3].XD = 50;
  vdp1.vram.cmd[3].YD = 150;

  vdp1.vram.cmd[4].CTRL = CTRL__JP__JUMP_NEXT | CTRL__COMM__POLYGON;
  vdp1.vram.cmd[4].LINK = 0;
  vdp1.vram.cmd[4].PMOD = CTRL__PMOD__ECD | CTRL__PMOD__SPD;
  vdp1.vram.cmd[4].COLR = (1 << 15) | (0x31 << 10) | (0x31 << 0); // RGB15 magenta
  vdp1.vram.cmd[4].XA = 100;
  vdp1.vram.cmd[4].YA = 50;
  vdp1.vram.cmd[4].XB = 150;
  vdp1.vram.cmd[4].YB = 100;
  vdp1.vram.cmd[4].XC = 100;
  vdp1.vram.cmd[4].YC = 150;
  vdp1.vram.cmd[4].XD =  50;
  vdp1.vram.cmd[4].YD = 100;

  vdp1.vram.cmd[5].CTRL = CTRL__END;

  // priorities
	vdp2.reg.PRISA = 0x0101;
	vdp2.reg.PRISB = 0x0101;
	vdp2.reg.PRISC = 0x0101;
	vdp2.reg.PRISD = 0x0101;

  // start drawing
  vdp1.reg.PTMR = PTMR__PTM__FRAME_CHANGE;

  //
  // scu1:
  //

  // If timer0 is counting at roughly 15.73426 kHz (1/63.5556 µs), we can count
  // to 300µs at roughly T0C = 5 (~317.778 µs). H-Blank-IN subtracts about
  // 10.9µs which is still (~306 µs) more than 300µs.

  vec[SCU_VEC__TIMER0] = (u32)(&timer0_int);
  vec[SCU_VEC__SMPC] = (u32)(&smpc_int);
  //scu.reg.T0C = 5;
  //scu.reg.T1MD = T1MD__TENB;

  // From the SMPC manual:
  //   The SMPC uses the V-BLANK-IN interrupt to execute internal tasks. At this
  //   time, issuing commands for 300 µs from V-BLANK-IN is prohibited.

  // CLKCHG320 (power-on default) NTSC, the FRC's internal clock is 26.8741 MHz.
  // The possible periods are then:
  //
  //  - 0.29768 µs (/8)
  //  - 1.19074 µs (/32)
  //  - 4.76295 µs (/128)
  //
  // (1/(26.8741 MHz)) * 128 * 63 = 300.066 µs

  // FRC, OCRA, OCRB, and FCIR are 16-bit registers, but the FRT bus is an 8-bit
  // bus.

  // TCR set CKS to /128
  // TOCR set OCRS to OCRA
  // TIER set OCIAE
  // FTCSR set CCLRA (clear FRC on compare match A)
  // VCRC set FOCV
  // OCRA set 63
  // FRC set 0

  vec[0x60] = (u32)&oci_int;
  sh2.reg.VCRC = VCRC__FOCV(0x60);

  sh2.reg.TCR = TCR__CKS__INTERNAL_DIV128;
  sh2.reg.TOCR = TOCR__OCRS__OCRA;
  sh2.reg.FTCSR = FTCSR__CCLRA;
  sh2.reg.OCRAB.H = 0;   // Even though Kronos doesn't emulate this, SH7095 says
                        // we are required to write the upper bit prior to
                        // writing the lower byte
  sh2.reg.OCRAB.L = 63;
  sh2.reg.FRC.H = 0;
  sh2.reg.FRC.L = 0;

  // enable output compare interrupt
  sh2.reg.TIER = TIER__OCIAE;

  // reset/enable interrupts

  scu.reg.IST = 0;
  scu.reg.IMS = ~(IMS__SMPC);

  while (1) {
    vec[0] = scu.reg.IST;
  }
}
