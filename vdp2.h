#define CACHE_THROUGH 0x20000000

#define VDP2_BASE 0x05E00000

/* */
#define VRAM 0x000000

#define TVMD 0x180000

#define TVMD__DISP (1 << 15)
#define TVMD__BDCLMD (1 << 8) // display back screen
#define TVMD__LSMD__NON_INTERLACE (0b00 << 6)
#define TVMD__LSMD__SINGLE_DENSITY (0b10 << 6)
#define TVMD__LSMD__DOUBLE_DENSITY (0b11 << 6)

#define TVMD__VRESO__224 (0b00 << 4)
#define TVMD__VRESO__240 (0b01 << 4)
#define TVMD__VRESO__256 (0b10 << 4)

#define TVMD__HRESO__NORMAL_320 (0b000 << 0)
#define TVMD__HRESO__NORMAL_352 (0b001 << 0)
#define TVMD__HRESO__HIRES_640 (0b010 << 0)
#define TVMD__HRESO__HIRES_704 (0b011 << 0)

#define TVMD__HRESO__EXCLUSIVE_320 (0b100 << 0)
#define TVMD__HRESO__EXCLUSIVE_352 (0b101 << 0)
#define TVMD__HRESO__EXCLUSIVE_640 (0b110 << 0)
#define TVMD__HRESO__EXCLUSIVE_704 (0b111 << 0)

/* */

#define BKTAU 0x1800AC

#define BKTAU__BKCLMD_SINGLE_COLOR (0 << 15)
#define BKTAU__BKCLMD_PER_LINE (1 << 15)

#define BKTAL 0x1800AE

/* */

#define RAMCTL 0x18000E

#define BGON   0x180020

/* */
#define TVSTAT 0x180004

#define TVSTAT__VBLANK (1 << 3)
