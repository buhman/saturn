#include "vdp2.h"

void start(void) {
  vdp2.reg.TVMD = ( TVMD__DISP | TVMD__BDCLMD | TVMD__LSMD__NON_INTERLACE
                  | TVMD__VRESO__240 | TVMD__HRESO__NORMAL_320);

  vdp2.reg.BGON = 0;

  vdp2.reg.BKTAU = BKTAU__BKCLMD_SINGLE_COLOR | 0;
  vdp2.reg.BKTAL = 0x4000;

  *((reg16 *)&vdp2.vram[0x8000]) = 31; // red

  while (1) {}
}
