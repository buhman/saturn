#pragma once

#include "type.h"

/* command table */

typedef struct cmd_point {
  s16 X;
  s16 Y;
} cmd_point;

typedef struct vdp1_cmd {
  u16 CTRL;
  u16 LINK;
  u16 PMOD;
  u16 COLR;
  u16 SRCA;
  u16 SIZE;
  union {
    struct {
      s16 XA;
      s16 YA;
      s16 XB;
      s16 YB;
      s16 XC;
      s16 YC;
      s16 XD;
      s16 YD;
    };
    struct {
      cmd_point A;
      cmd_point B;
      cmd_point C;
      cmd_point D;
    };
    cmd_point point[4];
  };
  u16 GRDA;
  u16 _dummy;
} vdp1_cmd;

static_assert((sizeof (struct vdp1_cmd)) == 0x20);

/* command table bits */

enum ctrl_bit {
  CTRL__END = (1 << 15),

  CTRL__JP__JUMP_NEXT   = (0b000 << 12),
  CTRL__JP__JUMP_ASSIGN = (0b001 << 12),
  CTRL__JP__JUMP_CALL   = (0b010 << 12),
  CTRL__JP__JUMP_RETURN = (0b011 << 12),

  CTRL__JP__SKIP_NEXT   = (0b100 << 12),
  CTRL__JP__SKIP_ASSIGN = (0b101 << 12),
  CTRL__JP__SKIP_CALL   = (0b110 << 12),
  CTRL__JP__SKIP_RETURN = (0b111 << 12),

  CTRL__ZP__TWO           = (0b0000 << 8),
  CTRL__ZP__UPPER_LEFT    = (0b0101 << 8),
  CTRL__ZP__UPPER_CENTER  = (0b0110 << 8),
  CTRL__ZP__UPPER_RIGHT   = (0b0111 << 8),
  CTRL__ZP__CENTER_LEFT   = (0b1001 << 8),
  CTRL__ZP__CENTER_CENTER = (0b1010 << 8),
  CTRL__ZP__CENTER_RIGHT  = (0b1011 << 8),
  CTRL__ZP__LOWER_LEFT    = (0b1101 << 8),
  CTRL__ZP__LOWER_CENTER  = (0b1110 << 8),
  CTRL__ZP__LOWER_RIGHT   = (0b1111 << 8),

  CTRL__DIR__NOT_INVERTED          = (0b00 << 4),
  CTRL__DIR__INVERTED_HORIZONTALLY = (0b01 << 4),
  CTRL__DIR__INVERTED_VERTICALLY   = (0b10 << 4),

  CTRL__COMM__NORMAL_SPRITE    = (0b0000),
  CTRL__COMM__SCALED_SPRITE    = (0b0001),
  CTRL__COMM__DISTORTED_SPRITE = (0b0010),
  CTRL__COMM__POLYGON          = (0b0100),
  CTRL__COMM__POLYLINE         = (0b0101),
  CTRL__COMM__LINE             = (0b0110),

  CTRL__COMM__USER_CLIP_COORDINATES   = (0b1000),
  CTRL__COMM__SYSTEM_CLIP_COORDINATES = (0b1001),
  CTRL__COMM__LOCAL_COORDINATE        = (0b1010),
};

enum pmod_bit {
  PMOD__MON = (1 << 15),
  PMOD__HSS = (1 << 12),
  PMOD__PCLP = (1 << 11),
  PMOD__CLIP = (1 << 10),
  PMOD__CMOD = (1 << 9),
  PMOD__MESH = (1 << 8),
  PMOD__ECD = (1 << 7),
  PMOD__SPD = (1 << 6),
#define PMOD__COLOR_MODE__COLOR_BANK_16   (0b000 << 3)
#define PMOD__COLOR_MODE__LOOKUP_TABLE_16 (0b001 << 3)
#define PMOD__COLOR_MODE__COLOR_BANK_64   (0b010 << 3)
#define PMOD__COLOR_MODE__COLOR_BANK_128  (0b011 << 3)
#define PMOD__COLOR_MODE__COLOR_BANK_256  (0b100 << 3)
#define PMOD__COLOR_MODE__RGB             (0b101 << 3)

#define PMOD__COLOR_CALCULATION__GOURAUD_SHADING (0b100 << 0)
#define PMOD__COLOR_CALCULATION__HALF_ORIGINAL_GRAPHIC (0b010 << 0)
#define PMOD__COLOR_CALCULATION__HALF_BACKGROUND (0b001 << 0)
};

// see "Pixel Data in Frame Buffer" in VDP1 manual
// see "Figure 9.1" in VDP2 manual
//  - these two figures refer to the same bits (VDP1 framebuffer data)
// see "Scroll Dot Pixels" in the VDP2 manual
//   - "Dot Color" (DC0, DC1, ...) is described in the "Scroll Dot
//     Pixels" section.
enum colr_bit {
  COLR__RGB = (1 << 15)
#define COLR__LOOKUP_TABLE__ADDRESS(n) ((n) >> 3)

#define COLR__COLOR_BANK__4BPP__PALETTE(n) (((n) & 0x7f) << 4)
#define COLR__COLOR_BANK__TYPE0__PR(n) (((n) &  0b11) << 14)
#define COLR__COLOR_BANK__TYPE0__CC(n) (((n) & 0b111) << 11)

#define COLR__COLOR_BANK__TYPE1__PR(n) (((n) & 0b111) << 13)
#define COLR__COLOR_BANK__TYPE1__CC(n) (((n) &  0b11) << 11)
};

//enum srca_bit {
#define SRCA(n) ((n) >> 3)
//};

//enum size_bit {
#define SIZE__Y(n) ((n) << 0)
#define SIZE__X(n) (((n) >> 3) << 8)
//};

/* memory offsets */

typedef union vdp1_vram {
  uint8_t   u8[0x080000 / 1];
  uint16_t  u16[0x080000 / 2];
  uint32_t  u32[0x080000 / 4];
  vdp1_cmd  cmd[0x080000 / 0x20];
} vdp1_vram;

static_assert((sizeof (union vdp1_vram)) == 0x080000);

typedef union vdp1_framebuffer {
  uint8_t   u8[0x040000 / 1];
  uint16_t  u16[0x040000 / 2];
  uint32_t  u32[0x040000 / 4];
} vdp1_framebuffer;

static_assert((sizeof (union vdp1_framebuffer)) == 0x040000);

typedef u8 vdp1_res0[0x040000];

typedef struct vdp1_reg {
  reg16 TVMR;   /* TV MODE SELECTION */
  reg16 FBCR;   /* FRAME BUFFER CHANGE MODE */
  reg16 PTMR;   /* PLOT TROGGER */
  reg16 EWDR;   /* ERASE/WRITE DATA */
  reg16 EWLR;   /* ERASE/WRITE UPPER-LEFT COORDINATE */
  reg16 EWRR;   /* ERASE/WRITE LOWER-RIGHT COORDINATE */
  reg16 ENDR;   /* PLOT ABNORMAL END */
  reg16 _res0;
  reg16 EDSR;   /* TRANSFER END STATUS */
  reg16 LOPR;   /* LAST OPERATION COMMAND ADDRESS */
  reg16 COPR;   /* CURRENT OPERATION COMMAND ADDRESS */
  reg16 MODR;   /* MODE STATUS */
} vdp1_reg;

static_assert((offsetof (struct vdp1_reg, ENDR)) == 0x0C);
static_assert((offsetof (struct vdp1_reg, EDSR)) == 0x10);
static_assert((sizeof (struct vdp1_reg)) == 24);

struct vdp1 {
  vdp1_vram vram;
  vdp1_framebuffer framebuffer;
  vdp1_res0 _res0;
  vdp1_reg reg;
};

static_assert((sizeof (struct vdp1)) == 0x100018);
static_assert((offsetof (struct vdp1, vram)) == 0x000000);
static_assert((offsetof (struct vdp1, framebuffer)) == 0x080000);
static_assert((offsetof (struct vdp1, reg)) == 0x100000);

extern struct vdp1 vdp1 __asm("vdp1");

/* register bits */

enum tvmr_bit {
  TVMR__VBE = (1 << 3),
  TVMR__TVM__NORMAL = (0b000 << 0),
  TVMR__TVM__HIGH_RESOLUTION = (0b001 << 0),
  TVMR__TVM__ROTATION_16 = (0b010 << 0),
  TVMR__TVM__ROTATION_8 = (0b011 << 0),
  TVMR__TVM__HDTV = (0b100 << 0),
};

enum fbcr_bit {
  FBCR__EOS = (1 << 4),
  FBCR__DIE = (1 << 3),
  FBCR__DIL = (1 << 2),
  FBCR__FCM = (1 << 1),
  FBCR__FCT = (1 << 0),
};

enum ptmr_bit {
  PTMR__PTM__IDLE = 0b00,
  PTMR__PTM__NOW = 0b01,
  PTMR__PTM__FRAME_CHANGE = 0b10,
};

// enum ewlr_bit {
#define EWLR__16BPP_X1(n) ((n / 8 ) << 9)
#define EWLR__8BPP_X1(n)  ((n / 16) << 9)
#define EWLR__Y1(n) (n << 0)
// }

// enum ewrr_bit {
#define EWRR__16BPP_X3(n) (((n + 1) / 8 ) << 9)
#define EWLR__8BPP_X3(n)  (((n + 1) / 16) << 9)
#define EWRR__Y3(n) (n << 0)
// }
