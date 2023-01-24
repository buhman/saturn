#include "vdp2.h"
#include "vdp1.h"
#include "scu.h"
#include "smpc.h"
#include "sh2.h"
#include "scsp.h"
#include "m68k.h"

void fill_32(u32 * buf, u32 v, s32 n)
{
  while (n > 0) {
    *buf++ = v;
    n -= (sizeof (u32));
  }
}

void copy_16(u16 * src, u16 * dst, s32 n)
{
  while (n > 0) {
    *dst++ = *src++;
    n -= (sizeof (u16));
  }
}

static inline void put_pixel(int cx, int cy, u16 color)
{
  #define CW 320
  #define CH 240
  int sx = (CW / 2) + cx;
  int sy = (CH / 2) - cy;
  vdp2.vram.u16[512 * sy + sx] = (1 << 15) | color;
}

void start(void)
{
  // DISP: Please make sure to change this bit from 0 to 1 during V blank.
  vdp2.reg.TVMD = ( TVMD__DISP | TVMD__LSMD__NON_INTERLACE
                  | TVMD__VRESO__240 | TVMD__HRESO__NORMAL_320);

  //
  // vdp2: bitmap mode
  //

  vdp2.reg.BGON = BGON__N0ON;

  vdp2.reg.CHCTLA = ( CHCTLA__N0CHCN__32K_COLOR     // 15 bits per pixel, RGB
                    | CHCTLA__N0BMSZ__512x256_DOT
                    | CHCTLA__N0BMEN__BITMAP_FORMAT
                    );

  vdp2.reg.MPOFN = MPOFN__N0MP(0); // bits 2~0
  // (boundary address value of the bit map pattern) =
  //    (map offset register value 3 bit) x 20000H

  // zeroize NBG0 (black)
  s32 plane_size = 512 * 256 * 2;
  fill_32(&vdp2.vram.u32[0x0 / 4], (1 << 15) | (1 << 31), plane_size);

  //vdp2.vram.u16[0x0 / 2] = (1 << 15) | 0x31;
  //vdp2.vram.u16[((512 * 239 + 319) * 2) / 2] = (1 << 15) | 0x7fff;

  put_pixel(0, 100, 0x3f);
  put_pixel(0, 0, 0x7fff);

  while (1) {}
}
