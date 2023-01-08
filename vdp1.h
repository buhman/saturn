#include "type.h"

/* command table */

typedef struct vdp1_cmd {
  u16 CTRL;
  u16 LINK;
  u16 PMOD;
  u16 COLR;
  u16 SRCA;
  u16 SIZE;
  s16 XA;
  s16 YA;
  s16 XB;
  s16 YB;
  s16 XC;
  s16 YC;
  s16 XD;
  s16 YD;
  u16 GDRA;
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
  CTRL__PMOD__MON = (1 << 15),
  CTRL__PMOD__HSS = (1 << 12),
  CTRL__PMOD__PCLP = (1 << 11),
  CTRL__PMOD__CLIP = (1 << 10),
  CTRL__PMOD__CMOD = (1 << 9),
  CTRL__PMOD__MESH = (1 << 8),
  CTRL__PMOD__ECD = (1 << 7),
  CTRL__PMOD__SPD = (1 << 6),
#define CTRL__PMOD__COLOR_MODE ( << 3)
#define CTRL__PMOD__COLOR_CALCULATION ( << 0)
};

/* memory offsets */

typedef union vdp1_vram {
  unsigned char   u8[0x080000 / 1];
  unsigned short u16[0x080000 / 2];
  unsigned long  u32[0x080000 / 4];
  vdp1_cmd       cmd[0x080000 / 0x20];
} vdp1_vram;

static_assert((sizeof (union vdp1_vram)) == 0x080000);

typedef union vdp1_framebuffer {
  unsigned char   u8[0x040000 / 1];
  unsigned short u16[0x040000 / 2];
  unsigned long  u32[0x040000 / 4];
} vdp1_framebuffer;

static_assert((sizeof (union vdp1_framebuffer)) == 0x040000);

typedef unsigned char vdp1_res0[0x040000];

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
  TVMR__TVM__NTSC_PAL = (0 << 2),
  TVMR__TVM__HDTV_31KC = (1 << 2),
  TVMR__TVM__FRAMEBUFFER_NONROTATION = (0 << 1),
  TVMR__TVM__FRAMEBUFFER_ROTATION = (1 << 1),
  TVMR__TVM__16BPP = (0 << 0),
  TVMR__TVM__8BPP = (1 << 0),
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
#define PTMR__EWLR__16BPP_X1(n) ((n / 8 ) << 9)
#define PTMR__EWLR__8BPP_X1(n)  ((n / 16) << 9)
#define PTMR__EWLR__Y1(n) (n << 0)
// }

// enum ewrr_bit {
#define PTMR__EWRR__16BPP_X3(n) (((n + 1) / 8 ) << 9)
#define PTMR__EWLR__8BPP_X3(n)  (((n + 1) / 16) << 9)
#define PTMR__EWRR__Y3(n) (n << 0)
// }
