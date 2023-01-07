#include "vdp2.h"

void start(void) {
  //
  // vdp2: enable and set Back Screen color
  //

  vdp2.reg.TVMD = ( TVMD__DISP | TVMD__BDCLMD | TVMD__LSMD__NON_INTERLACE
                  | TVMD__VRESO__240 | TVMD__HRESO__NORMAL_320);

  vdp2.reg.BGON = 0;

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

  // Table 4.8  Address value of map designated register by setting
  // (bit 5~0) * 0x4000
  vdp2.vram.u32[(0x4000 / 4)] = PATTERN_NAME_TABLE_2WORD__CHARACTER(1);

  while (1) {}
}
