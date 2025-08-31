#pragma once

#include "type.h"

/* memory offsets */

typedef union vdp2_vram {
  unsigned char   u8[0x080000 / 1];
  unsigned short u16[0x080000 / 2];
  unsigned long  u32[0x080000 / 4];
} vdp2_vram;

static_assert((sizeof (union vdp2_vram)) == 0x080000);

typedef unsigned char vdp2_res0[0x080000];

typedef union vdp2_cram {
  unsigned char   u8[0x001000 / 1];
  unsigned short u16[0x001000 / 2];
  unsigned long  u32[0x001000 / 4];
} vdp2_cram;

static_assert((sizeof (union vdp2_cram)) == 0x001000);

typedef unsigned char vdp2_res1[0x07f000];

typedef struct vdp2_reg {
  reg16 TVMD;   /* TV SCREEN MODE */
  reg16 EXTEN;  /* EXTERNAL SIGNAL ENABLE */
  reg16 TVSTAT; /* SCREEN STATUS */
  reg16 VRSIZE; /* VRAM SIZE */
  reg16 HCNT;   /* H-COUNTER */
  reg16 VCNT;   /* V-COUNTER */
  reg16 _res0;
  reg16 RAMCTL; /* RAM CONTROL */
  union {
    struct {
      reg16 CYCA0L; /* VRAM CYCLE PATTERN (BANK A0) */
      reg16 CYCA0U; /* VRAM CYCLE PATTERN (BANK A0) */
    };
    reg32 CYCA0;
  };
  union {
    struct {
      reg16 CYCA1L; /* VRAM CYCLE PATTERN (BANK A1) */
      reg16 CYCA1U; /* VRAM CYCLE PATTERN (BANK A1) */
    };
    reg32 CYCA1;
  };
  union {
    struct {
      reg16 CYCB0L; /* VRAM CYCLE PATTERN (BANK A0) */
      reg16 CYCB0U; /* VRAM CYCLE PATTERN (BANK A0) */
    };
    reg32 CYCB0;
  };
  union {
    struct {
      reg16 CYCB1L; /* VRAM CYCLE PATTERN (BANK B1) */
      reg16 CYCB1U; /* VRAM CYCLE PATTERN (BANK B1) */
    };
    reg32 CYCB1;
  };
  reg16 BGON;   /* SCREEN DISPLAY ENABLE */
  reg16 MZCTL;  /* MOSAIC CONTROL */
  reg16 SFSEL;  /* SPECIAL FUNCTION CODE SELECT */
  reg16 SFCODE; /* SPECIAL FUNCTION CODE */
  reg16 CHCTLA; /* CHARACTER CONTROL (NBG0, NBG1) */
  reg16 CHCTLB; /* CHARACTER CONTROL (NBG2, NBG3, RGB0) */
  reg16 BMPNA;  /* BITMAP PALETTE NUMBER (NBG0, NBG1) */
  reg16 BMPNB;  /* BITMAP PALETTE NUMBER (RGB0) */
  reg16 PNCN0;  /* PATTERN NAME CONTROL (NBG0) */
  reg16 PNCN1;  /* PATTERN NAME CONTROL (NBG1) */
  reg16 PNCN2;  /* PATTERN NAME CONTROL (NBG2) */
  reg16 PNCN3;  /* PATTERN NAME CONTROL (NBG2) */
  reg16 PNCR;   /* PATTERN NAME CONTROL (RGB0) */
  reg16 PLSZ;   /* PLANE SIZE */
  reg16 MPOFN;  /* MAP OFFSET (NBG0~NBG3) */
  reg16 MPOFR;  /* MAP OFFSET (ROTATION PARAMETER A,B) */
  union {
    struct {
      reg16 MPABN0; /* MAP (NBG0, PLANE A,B) */
      reg16 MPCDN0; /* MAP (NBG0, PLANE C,D) */
    };
    reg32 MPN0;
  };
  union {
    struct {
      reg16 MPABN1; /* MAP (NBG1, PLANE A,B) */
      reg16 MPCDN1; /* MAP (NBG1, PLANE C,D) */
    };
    reg32 MPN1;
  };
  union {
    struct {
      reg16 MPABN2; /* MAP (NBG2, PLANE A,B) */
      reg16 MPCDN2; /* MAP (NBG2, PLANE C,D) */
    };
    reg32 MPN2;
  };
  union {
    struct {
      reg16 MPABN3; /* MAP (NBG3, PLANE A,B) */
      reg16 MPCDN3; /* MAP (NBG3, PLANE C,D) */
    };
    reg32 MPN3;
  };
  reg16 MPABRA; /* MAP (ROTATION PARAMETER A, PLANE A,B) */
  reg16 MPCDRA; /* MAP (ROTATION PARAMETER A, PLANE C,D) */
  reg16 MPEFRA; /* MAP (ROTATION PARAMETER A, PLANE E,F) */
  reg16 MPGHRA; /* MAP (ROTATION PARAMETER A, PLANE G,H) */
  reg16 MPIJRA; /* MAP (ROTATION PARAMETER A, PLANE I,J) */
  reg16 MPKLRA; /* MAP (ROTATION PARAMETER A, PLANE K,L) */
  reg16 MPMNRA; /* MAP (ROTATION PARAMETER A, PLANE M,N) */
  reg16 MPOPRA; /* MAP (ROTATION PARAMETER A, PLANE O,P) */
  reg16 MPABRB; /* MAP (ROTATION PARAMETER B, PLANE A,B) */
  reg16 MPCDRB; /* MAP (ROTATION PARAMETER B, PLANE C,D) */
  reg16 MPEFRB; /* MAP (ROTATION PARAMETER B, PLANE E,F) */
  reg16 MPGHRB; /* MAP (ROTATION PARAMETER B, PLANE G,H) */
  reg16 MPIJRB; /* MAP (ROTATION PARAMETER B, PLANE I,J) */
  reg16 MPKLRB; /* MAP (ROTATION PARAMETER B, PLANE K,L) */
  reg16 MPMNRB; /* MAP (ROTATION PARAMETER B, PLANE M,N) */
  reg16 MPOPRB; /* MAP (ROTATION PARAMETER B, PLANE O,P) */
  reg16 SCXIN0; /* SCREEN SCROLL VALUE (NBG0, HORIZONTAL INTEGER PART) */
  reg16 SCXDN0; /* SCREEN SCROLL VALUE (NBG0, HORIZONTAL FRACTIONAL PART) */
  reg16 SCYIN0; /* SCREEN SCROLL VALUE (NBG0, VERTICAL INTEGER PART) */
  reg16 SCYDN0; /* SCREEN SCROLL VALUE (NBG0, VERTICAL FRACTIONAL PART) */
  reg16 ZMXIN0; /* COORDINATE INCREMENT (NBG0, HORIZONTAL INTEGER PART) */
  reg16 ZMXDN0; /* COORDINATE INCREMENT (NBG0, HORIZONTAL FRACTIONAL PART) */
  reg16 ZMYIN0; /* COORDINATE INCREMENT (NBG0, VERTICAL INTEGER PART) */
  reg16 ZMYDN0; /* COORDINATE INCREMENT (NBG0, VERTICAL FRACTIONAL PART) */
  reg16 SCXIN1; /* SCREEN SCROLL VALUE (NBG1, HORIZONTAL INTEGER PART) */
  reg16 SCXDN1; /* SCREEN SCROLL VALUE (NBG1, HORIZONTAL FRACTIONAL PART) */
  reg16 SCYIN1; /* SCREEN SCROLL VALUE (NBG1, VERTICAL INTEGER PART) */
  reg16 SCYDN1; /* SCREEN SCROLL VALUE (NBG1, VERTICAL FRACTIONAL PART) */
  reg16 ZMXIN1; /* COORDINATE INCREMENT (NBG1, HORIZONTAL INTEGER PART) */
  reg16 ZMXDN1; /* COORDINATE INCREMENT (NBG1, HORIZONTAL FRACTIONAL PART) */
  reg16 ZMYIN1; /* COORDINATE INCREMENT (NBG1, VERTICAL INTEGER PART) */
  reg16 ZMYDN1; /* COORDINATE INCREMENT (NBG1, VERTICAL FRACTIONAL PART) */
  reg16 SCXN2;  /* SCREEN SCROLL VALUE (NBG2, HORIZONTAL) */
  reg16 SCYN2;  /* SCREEN SCROLL VALUE (NBG2, VERTICAL) */
  reg16 SCXN3;  /* SCREEN SCROLL VALUE (NBG3, HORIZONTAL) */
  reg16 SCYN3;  /* SCREEN SCROLL VALUE (NBG3, VERTICAL) */
  reg16 ZMCTL;  /* REDUCTION ENABLE */
  reg16 SCRCTL; /* LINE AND VERTICAL CELL SCROLL CONTROL (NBGO, NBG1) */
  union {
    struct {
      reg16 VCSTAU; /* VERTICAL CELL SCROLL TABLE ADDRESS (NBGO, NBG1) */
      reg16 VCSTAL; /* VERTICAL CELL SCROLL TABLE ADDRESS (NBGO, NBG1) */
    };
    reg32 VCSTA;
  };
  reg16 LSTA0U; /* LINE SCROLL TABLE ADDRESS (NBG0) */
  reg16 LSTA0L; /* LINE SCROLL TABLE ADDRESS (NBG0) */
  reg16 LSTA1U; /* LINE SCROLL TABLE ADDRESS (NBG1) */
  reg16 LSTA1L; /* LINE SCROLL TABLE ADDRESS (NBG1) */
  reg16 LCTAU;  /* LINE COLOR SCREEN TABLE ADDRESS */
  reg16 LCTAL;  /* LINE COLOR SCREEN TABLE ADDRESS */
  union {
    struct {
      reg16 BKTAU;  /* BACK SCREEN TABLE ADDRESS */
      reg16 BKTAL;  /* BACK SCREEN TABLE ADDRESS */
    };
    reg32 BKTA;
  };
  reg16 RPMD;   /* ROTATION PARAMETER MODE */
  reg16 RPRCTL; /* ROTATION PARAMETER READ CONTROL */
  reg16 KTCTL;  /* COEFFICIENT TABLE CONTROL */
  reg16 KTAOF;  /* COEFFICIENT TABLE ADDRESS OFFSET (ROTATION PARAMETER A, B) */
  reg16 OVPNRA; /* SCREEN OVER PATTERN NAME (ROTATION PARAMETER A) */
  reg16 OVPNRB; /* SCREEN OVER PATTERN NAME (ROTATION PARAMETER B) */
  union {
    struct {
      reg16 RPTAU;  /* ROTATION PARAMETER TABLE ADDRESS (ROTATION PARAMETER A,B) */
      reg16 RPTAL;  /* ROTATION PARAMETER TABLE ADDRESS (ROTATION PARAMETER A,B) */
    };
    reg32 RPTA;
  };
  reg16 WPSX0;  /* WINDOW POSITION (W0, HORIZONTAL START POINT) */
  reg16 WPSY0;  /* WINDOW POSITION (W0, VERTICAL START POINT) */
  reg16 WPEX0;  /* WINDOW POSITION (W0, HORIZONTAL END POINT) */
  reg16 WPEY0;  /* WINDOW POSITION (W0, VERTICAL END POINT) */
  reg16 WPSX1;  /* WINDOW POSITION (W1, HORIZONTAL START POINT) */
  reg16 WPSY1;  /* WINDOW POSITION (W1, VERTICAL START POINT) */
  reg16 WPEX1;  /* WINDOW POSITION (W1, HORIZONTAL END POINT) */
  reg16 WPEY1;  /* WINDOW POSITION (W1, VERTICAL END POINT) */
  reg16 WCTLA;  /* WINDOW CONTROL (NBG0, NBG1) */
  reg16 WCTLB;  /* WINDOW CONTROL (NBG2, NBG3) */
  reg16 WCTLC;  /* WINDOW CONTROL (RGB0, SPRITE) */
  reg16 WCTLD;  /* WINDOW CONTROL (PARAMETER WINDOW, COLOR CALC. WINDOW) */
  reg16 LWTA0U; /* LINE WINDOW TABLE ADDRESS (W0) */
  reg16 LWTA0L; /* LINE WINDOW TABLE ADDRESS (W0) */
  reg16 LWTA1U; /* LINE WINDOW TABLE ADDRESS (W1) */
  reg16 LWTA1L; /* LINE WINDOW TABLE ADDRESS (W1) */
  reg16 SPCTL;  /* SPRITE CONTROL */
  reg16 SDCTL;  /* SHADOW CONTROL */
  reg16 CRAOFA; /* COLOR RAM ADDRESS OFFSET (NBG0~NBG3) */
  reg16 CRAOFB; /* COLOR RAM ADDRESS OFFSET (RGB0, SPRITE) */
  reg16 LNCLEN; /* LINE COLOR SCREEN ENABLE */
  reg16 SFPRMD; /* SPECIAL PRIORITY MODE */
  reg16 CCCTL;  /* COLOR CALCULATION CONTROL */
  reg16 SFCCMD; /* SPECIAL COLOR CALCULATION MODE */
  reg16 PRISA;  /* PRIORITY NUMBER (SPRITE 0,1) */
  reg16 PRISB;  /* PRIORITY NUMBER (SPRITE 2,3) */
  reg16 PRISC;  /* PRIORITY NUMBER (SPRITE 4,5) */
  reg16 PRISD;  /* PRIORITY NUMBER (SPRITE 6,7) */
  reg16 PRINA;  /* PRIORITY NUMBER (NBG0, NBG1) */
  reg16 PRINB;  /* PRIORITY NUMBER (NBG2, NBG3) */
  reg16 PRIR;   /* PRIORITY NUMBER (RGB0) */
  reg16 _res1;
  reg16 CCRSA;  /* COLOR CALCULATION RATIO (SPRITE 0,1) */
  reg16 CCRSB;  /* COLOR CALCULATION RATIO (SPRITE 2,3) */
  reg16 CCRSC;  /* COLOR CALCULATION RATIO (SPRITE 4,5) */
  reg16 CCRSD;  /* COLOR CALCULATION RATIO (SPRITE 6,7) */
  reg16 CCRNA;  /* COLOR CALCULATION RATIO (NBG0, NBG1) */
  reg16 CCRNB;  /* COLOR CALCULATION RATIO (NBG2, NBG3) */
  reg16 CCRR;   /* COLOR CALCULATION RATIO (RGB0) */
  reg16 CCRLB;  /* COLOR CALCULATION RATIO (LINE COLOR SCREEN, BACK SCREEN) */
  reg16 CLOFEN; /* COLOR OFFSET ENABLE */
  reg16 CLOFSL; /* COLOR OFFSET SELECT */
  reg16 COAR;   /* COLOR OFFSET A (RED) */
  reg16 COAG;   /* COLOR OFFSET A (GREEN) */
  reg16 COAB;   /* COLOR OFFSET A (BLUE) */
  reg16 COBR;   /* COLOR OFFSET B (RED) */
  reg16 COBG;   /* COLOR OFFSET B (GREEN) */
  reg16 COBB;   /* COLOR OFFSET B (BLUE) */
} vdp2_reg;

static_assert((sizeof (struct vdp2_reg)) == 0x120);

struct vdp2 {
  vdp2_vram vram;
  vdp2_res0 _res0;
  vdp2_cram cram;
  vdp2_res1 _res1;
  vdp2_reg reg;
};

static_assert((sizeof (struct vdp2)) == 0x180120);
static_assert((offsetof (struct vdp2, vram)) == 0x000000);
static_assert((offsetof (struct vdp2, cram)) == 0x100000);
static_assert((offsetof (struct vdp2, reg)) == 0x180000);

extern struct vdp2 vdp2 __asm("vdp2");

/* register bits */

enum tvmd_bit {
  TVMD__DISP = (1 << 15),
  TVMD__BDCLMD = (1 << 8), // display back screen
  TVMD__LSMD__NON_INTERLACE = (0b00 << 6),
  TVMD__LSMD__SINGLE_DENSITY = (0b10 << 6),
  TVMD__LSMD__DOUBLE_DENSITY = (0b11 << 6),

  TVMD__VRESO__224 = (0b00 << 4),
  TVMD__VRESO__240 = (0b01 << 4),
  TVMD__VRESO__256 = (0b10 << 4),

  TVMD__HRESO__NORMAL_320 = (0b000 << 0),
  TVMD__HRESO__NORMAL_352 = (0b001 << 0),
  TVMD__HRESO__HIRES_640 = (0b010 << 0),
  TVMD__HRESO__HIRES_704 = (0b011 << 0),

  TVMD__HRESO__EXCLUSIVE_320 = (0b100 << 0),
  TVMD__HRESO__EXCLUSIVE_352 = (0b101 << 0),
  TVMD__HRESO__EXCLUSIVE_640 = (0b110 << 0),
  TVMD__HRESO__EXCLUSIVE_704 = (0b111 << 0),
};
// enum exten_bit {
// };
enum tvstat_bit {
  TVSTAT__VBLANK = (1 << 3),
};
enum vrsize_bit {
  VRSIZE__VRAMSZ = (1 << 15),
};
// enum hcnt_bit {
// };
// enum vcnt_bit {
// };
enum ramctl_bit {
  RAMCTL__CRKTE = (1 << 15),
  RAMCTL__CRMD__RGB_5BIT_1024 = (0b00 << 12),
  RAMCTL__CRMD__RGB_5BIT_2048 = (0b01 << 12),
  RAMCTL__CRMD__RGB_8BIT_1024 = (0b10 << 12),
  RAMCTL__VRBMD = (1 << 9),
  RAMCTL__VRAMD = (1 << 8),
  RAMCTL__RDBSB1__COEFFICIENT_TABLE = (0b01 << 6),
  RAMCTL__RDBSB1__PATTERN_NAME_TABLE = (0b10 << 6),
  RAMCTL__RDBSB1__CHARACTER_PATTERN_TABLE = (0b11 << 6),
  RAMCTL__RDBSB0__COEFFICIENT_TABLE = (0b01 << 4),
  RAMCTL__RDBSB0__PATTERN_NAME_TABLE = (0b10 << 4),
  RAMCTL__RDBSB0__CHARACTER_PATTERN_TABLE = (0b11 << 4),
  RAMCTL__RDBSA1__COEFFICIENT_TABLE = (0b01 << 2),
  RAMCTL__RDBSA1__PATTERN_NAME_TABLE = (0b10 << 2),
  RAMCTL__RDBSA1__CHARACTER_PATTERN_TABLE = (0b11 << 2),
  RAMCTL__RDBSA0__COEFFICIENT_TABLE = (0b01 << 0),
  RAMCTL__RDBSA0__PATTERN_NAME_TABLE = (0b10 << 0),
  RAMCTL__RDBSA0__CHARACTER_PATTERN_TABLE = (0b11 << 0),
};
// enum cyca0l_bit {
// };
// enum cyca0u_bit {
// };
// enum cyca1l_bit {
// };
// enum cyca1u_bit {
// };
// enum cycb0l_bit {
// };
// enum cycb0u_bit {
// };
// enum cycb1l_bit {
// };
// enum cycb1u_bit {
// };
enum bgon_bit {
  BGON__R0TPON = (1 << 12),
  BGON__N3TPON = (1 << 11),
  BGON__N2TPON = (1 << 10),
  BGON__N1TPON = (1 << 9),
  BGON__N0TPON = (1 << 8),

  BGON__R1ON = (1 << 5),
  BGON__R0ON = (1 << 4),
  BGON__N3ON = (1 << 3),
  BGON__N2ON = (1 << 2),
  BGON__N1ON = (1 << 1),
  BGON__N0ON = (1 << 0),
};
// enum mzctl_bit {
// };
// enum sfsel_bit {
// };
// enum sfcode_bit {
// };
enum chctla_bit {
  CHCTLA__N1CHCN__16_COLOR = (0b00 << 12),
  CHCTLA__N1CHCN__256_COLOR = (0b01 << 12),
  CHCTLA__N1CHCN__2048_COLOR = (0b10 << 12),
  CHCTLA__N1CHCN__32K_COLOR = (0b11 << 12),

  CHCTLA__N1BMSZ__512x256_DOT = (0b00 << 10),
  CHCTLA__N1BMSZ__512x512_DOT = (0b01 << 10),
  CHCTLA__N1BMSZ__1024x256_DOT = (0b10 << 10),
  CHCTLA__N1BMSZ__1024x512_DOT = (0b11 << 10),

  CHCTLA__N1BMEN__CELL_FORMAT = (0 << 9),
  CHCTLA__N1BMEN__BITMAP_FORMAT = (1 << 9),

  CHCTLA__N1CHSZ__1x1_CELL = (0 << 8),
  CHCTLA__N1CHSZ__2x2_CELL = (1 << 8),

  CHCTLA__N0CHCN__16_COLOR = (0b000 << 4),
  CHCTLA__N0CHCN__256_COLOR = (0b001 << 4),
  CHCTLA__N0CHCN__2048_COLOR = (0b010 << 4),
  CHCTLA__N0CHCN__32K_COLOR = (0b011 << 4),
  CHCTLA__N0CHCN__16M_COLOR = (0b100 << 4),

  CHCTLA__N0BMSZ__512x256_DOT = (0b00 << 2),
  CHCTLA__N0BMSZ__512x512_DOT = (0b01 << 2),
  CHCTLA__N0BMSZ__1024x256_DOT = (0b10 << 2),
  CHCTLA__N0BMSZ__1024x512_DOT = (0b11 << 2),

  CHCTLA__N0BMEN__CELL_FORMAT = (0 << 1),
  CHCTLA__N0BMEN__BITMAP_FORMAT = (1 << 1),

  CHCTLA__N0CHSZ__1x1_CELL = (0 << 0),
  CHCTLA__N0CHSZ__2x2_CELL = (1 << 0),
};
enum chctlb_bit {
  CHCTLB__R0CHCN__16_COLOR = (0b000 << 12),
  CHCTLB__R0CHCN__256_COLOR = (0b001 << 12),
  CHCTLB__R0CHCN__2048_COLOR = (0b010 << 12),
  CHCTLB__R0CHCN__32K_COLOR = (0b011 << 12),
  CHCTLB__R0CHCN__16M_COLOR = (0b100 << 12),

  CHCTLB__R0BMSZ__512x256_DOT = (0 << 10),
  CHCTLB__R0BMSZ__512x512_DOT = (1 << 10),

  CHCTLB__R0BMEN__CELL_FORMAT = (0 << 9),
  CHCTLB__R0BMEN__BITMAP_FORMAT = (1 << 9),

  CHCTLB__R0CHSZ__1x1_CELL = (0 << 8),
  CHCTLB__R0CHSZ__2x2_CELL = (1 << 8),

  CHCTLB__N3CHCN__16_COLOR = (0 << 5),
  CHCTLB__N3CHCN__256_COLOR = (1 << 5),

  CHCTLB__N3CHSZ__1x1_CELL = (0 << 4),
  CHCTLB__N3CHSZ__2x2_CELL = (1 << 4),

  CHCTLB__N2CHCN__16_COLOR = (0 << 1),
  CHCTLB__N2CHCN__256_COLOR = (1 << 1),

  CHCTLB__N2CHSZ__1x1_CELL = (0 << 4),
  CHCTLB__N2CHSZ__2x2_CELL = (1 << 4),
};
// enum bmpna_bit {
// };
// enum bmpnb_bit {
// };

enum pncn0_bit {
  PNCN0__N0PNB__2WORD = (0 << 15),
  PNCN0__N0PNB__1WORD = (1 << 15),
  PNCN0__N0CNSM = (1 << 14),
  PNCN0__N0SPR = (1 << 9),
  PNCN0__N0SCC = (1 << 8),
#define PNCN0__N0SPLT(n) ((n) << 5)
#define PNCN0__N0SCN(n) ((n) << 0)
};

enum pncn1_bit {
  PNCN1__N1PNB__2WORD = (0 << 15),
  PNCN1__N1PNB__1WORD = (1 << 15),
  PNCN1__N1CNSM = (1 << 14),
  PNCN1__N1SPR = (1 << 9),
  PNCN1__N1SCC = (1 << 8),
#define PNCN1__N1SPLT(n) ((n) << 5)
#define PNCN1__N1SCN(n) ((n) << 0)
};

enum pncn2_bit {
  PNCN2__N2PNB__2WORD = (0 << 15),
  PNCN2__N2PNB__1WORD = (1 << 15),
  PNCN2__N2CNSM = (1 << 14),
  PNCN2__N2SPR = (1 << 9),
  PNCN2__N2SCC = (1 << 8),
#define PNCN2__N2SPLT(n) ((n) << 5)
#define PNCN2__N2SCN(n) ((n) << 0)
};

enum pncn3_bit {
  PNCN3__N3PNB__2WORD = (0 << 15),
  PNCN3__N3PNB__1WORD = (1 << 15),
  PNCN3__N3CNSM = (1 << 14),
  PNCN3__N3SPR = (1 << 9),
  PNCN3__N3SCC = (1 << 8),
#define PNCN3__N3SPLT(n) ((n) << 5)
#define PNCN3__N3SCN(n) ((n) << 0)
};

enum pncr_bit {
  PNCR__R0PNB__2WORD = (0 << 15),
  PNCR__R0PNB__1WORD = (1 << 15),
  PNCR__R0CNSM = (1 << 14),
  PNCR__R0SPR = (1 << 9),
  PNCR__R0SCC = (1 << 8),
#define PNCR__R0SPLT(n) ((n) << 5)
#define PNCR__R0SCN(n) ((n) << 0)
};

enum plsz_bit {
  PLSZ__RBOVR__ = (0b00 << 14),
  PLSZ__RBPLSZ__1x1 = (0b00 << 12),
  PLSZ__RBPLSZ__2x1 = (0b01 << 12),
  PLSZ__RBPLSZ__2x2 = (0b10 << 12),
  PLSZ__RAOVR__ = (0b00 << 10),
  PLSZ__RAPLSZ__1x1 = (0b00 << 8),
  PLSZ__RAPLSZ__2x1 = (0b01 << 8),
  PLSZ__RAPLSZ__2x2 = (0b10 << 8),

  PLSZ__N3PLSZ__1x1 = (0b00 << 6),
  PLSZ__N3PLSZ__2x1 = (0b01 << 6),
  PLSZ__N3PLSZ__2x2 = (0b11 << 6),

  PLSZ__N2PLSZ__1x1 = (0b00 << 4),
  PLSZ__N2PLSZ__2x1 = (0b01 << 4),
  PLSZ__N2PLSZ__2x2 = (0b11 << 4),

  PLSZ__N1PLSZ__1x1 = (0b00 << 2),
  PLSZ__N1PLSZ__2x1 = (0b01 << 2),
  PLSZ__N1PLSZ__2x2 = (0b11 << 2),

  PLSZ__N0PLSZ__1x1 = (0b00 << 0),
  PLSZ__N0PLSZ__2x1 = (0b01 << 0),
  PLSZ__N0PLSZ__2x2 = (0b11 << 0),
};
// enum mpofn_bit {
#define MPOFN__N3MP(n) (((n) & 0b111) << 12)
#define MPOFN__N2MP(n) (((n) & 0b111) << 8)
#define MPOFN__N1MP(n) (((n) & 0b111) << 4)
#define MPOFN__N0MP(n) (((n) & 0b111) << 0)
// };
// enum mpofr_bit {
#define MPOFR__RBMP(n) (((n) & 0b111) << 4)
#define MPOFR__RAMP(n) (((n) & 0b111) << 0)
// };

// 4.8 Maps § Map Selection Register

// enum mpabn0_bit {
#define MPABN0__N0MPB(n) ((n) << 8)
#define MPABN0__N0MPA(n) ((n) << 0)
// };
// enum mpcdn0_bit {
#define MPCDN0__N0MPD(n) ((n) << 8)
#define MPCDN0__N0MPC(n) ((n) << 0)
// };
#define MPN0__N0MP(n) (((n) << 24) | ((n) << 16) | ((n) << 8) | ((n) << 0))
// enum mpabn1_bit {
#define MPABN1__N1MPB(n) ((n) << 8)
#define MPABN1__N1MPA(n) ((n) << 0)
// };
// enum mpcdn1_bit {
#define MPCDN1__N1MPD(n) ((n) << 8)
#define MPCDN1__N1MPC(n) ((n) << 0)
// };
#define MPN1__N1MP(n) (((n) << 24) | ((n) << 16) | ((n) << 8) | ((n) << 0))
// enum mpabn2_bit {
#define MPABN2__N2MPB(n) ((n) << 8)
#define MPABN2__N2MPA(n) ((n) << 0)
// };
// enum mpcdn2_bit {
#define MPCDN2__N2MPD(n) ((n) << 8)
#define MPCDN2__N2MPC(n) ((n) << 0)
// };
#define MPN2__N2MP(n) (((n) << 24) | ((n) << 16) | ((n) << 8) | ((n) << 0))
// enum mpabn3_bit {
#define MPABN3__N3MPB(n) ((n) << 8)
#define MPABN3__N3MPA(n) ((n) << 0)
// };
// enum mpcdn3_bit {
#define MPCDN3__N3MPD(n) ((n) << 8)
#define MPCDN3__N3MPC(n) ((n) << 0)
// };
#define MPN3__N3MP(n) (((n) << 24) | ((n) << 16) | ((n) << 8) | ((n) << 0))
// enum mpabra_bit {
#define MPABRA__RAMPB(n) (((n) & 0b111111) << 8)
#define MPABRA__RAMPA(n) (((n) & 0b111111) << 0)
// };
// enum mpcdra_bit {
#define MPCDRA__RAMPD(n) (((n) & 0b111111) << 8)
#define MPCDRA__RAMPC(n) (((n) & 0b111111) << 0)
// };
// enum mpefra_bit {
#define MPEFRA__RAMPF(n) (((n) & 0b111111) << 8)
#define MPEFRA__RAMPE(n) (((n) & 0b111111) << 0)
// };
// enum mpghra_bit {
#define MPGHRA__RAMPH(n) (((n) & 0b111111) << 8)
#define MPGHRA__RAMPG(n) (((n) & 0b111111) << 0)
// };
// enum mpijra_bit {
#define MPIJRA__RAMPJ(n) (((n) & 0b111111) << 8)
#define MPIJRA__RAMPI(n) (((n) & 0b111111) << 0)
// };
// enum mpklra_bit {
#define MPKLRA__RAMPL(n) (((n) & 0b111111) << 8)
#define MPKLRA__RAMPK(n) (((n) & 0b111111) << 0)
// };
// enum mpmnra_bit {
#define MPMNRA__RAMPN(n) (((n) & 0b111111) << 8)
#define MPMNRA__RAMPM(n) (((n) & 0b111111) << 0)
// };
// enum mpopra_bit {
#define MPOPRA__RAMPP(n) (((n) & 0b111111) << 8)
#define MPOPRA__RAMPO(n) (((n) & 0b111111) << 0)
// };
// enum mpabrb_bit {
#define MPABRB__RBMPB(n) (((n) & 0b111111) << 8)
#define MPABRB__RBMPA(n) (((n) & 0b111111) << 0)
// };
// enum mpcdrb_bit {
#define MPCDRB__RBMPD(n) (((n) & 0b111111) << 8)
#define MPCDRB__RBMPC(n) (((n) & 0b111111) << 0)
// };
// enum mpefrb_bit {
#define MPEFRB__RBMPF(n) (((n) & 0b111111) << 8)
#define MPEFRB__RBMPE(n) (((n) & 0b111111) << 0)
// };
// enum mpghrb_bit {
#define MPGHRB__RBMPH(n) (((n) & 0b111111) << 8)
#define MPGHRB__RBMPG(n) (((n) & 0b111111) << 0)
// };
// enum mpijrb_bit {
#define MPIJRB__RBMPJ(n) (((n) & 0b111111) << 8)
#define MPIJRB__RBMPI(n) (((n) & 0b111111) << 0)
// };
// enum mpklrb_bit {
#define MPKLRB__RBMPL(n) (((n) & 0b111111) << 8)
#define MPKLRB__RBMPK(n) (((n) & 0b111111) << 0)
// };
// enum mpmnrb_bit {
#define MPMNRB__RBMPN(n) (((n) & 0b111111) << 8)
#define MPMNRB__RBMPM(n) (((n) & 0b111111) << 0)
// };
// enum mpoprb_bit {
#define MPOPRB__RBMPP(n) (((n) & 0b111111) << 8)
#define MPOPRB__RBMPO(n) (((n) & 0b111111) << 0)
// };
// enum scxin0_bit {
// };
// enum scxdn0_bit {
// };
// enum scyin0_bit {
// };
// enum scydn0_bit {
// };
// enum zmxin0_bit {
// };
// enum zmxdn0_bit {
// };
// enum zmyin0_bit {
// };
// enum zmydn0_bit {
// };
// enum scxin1_bit {
// };
// enum scxdn1_bit {
// };
// enum scyin1_bit {
// };
// enum scydn1_bit {
// };
// enum zmxin1_bit {
// };
// enum zmxdn1_bit {
// };
// enum zmyin1_bit {
// };
// enum zmydn1_bit {
// };
// enum scxn2_bit {
// };
// enum scyn2_bit {
// };
// enum scxn3_bit {
// };
// enum scyn3_bit {
// };
// enum zmctl_bit {
// };
// enum scrctl_bit {
// };
// enum vcstau_bit {
// };
// enum vcstal_bit {
// };
// enum lsta0u_bit {
// };
// enum lsta0l_bit {
// };
// enum lsta1u_bit {
// };
// enum lsta1l_bit {
// };
// enum lctau_bit {
// };
// enum lctal_bit {
// };
enum bktau_bit {
  BKTAU__BKCLMD_SINGLE_COLOR = (0 << 15),
  BKTAU__BKCLMD_PER_LINE = (1 << 15),
};
// enum bktal_bit {
// };
enum bkta_bit {
  BKTA__BKCLMD_SINGLE_COLOR = (0 << 31),
  BKTA__BKCLMD_PER_LINE = (1 << 31),
};
enum rpmd_bit {
  RPMD__ROTATION_PARAMETER_A = (0b00 << 0),
  RPMD__ROTATION_PARAMETER_B = (0b01 << 0),
};
// enum rprctl_bit {
// };
// enum ktctl_bit {
// };
// enum ktaof_bit {
// };
// enum ovpnra_bit {
// };
// enum ovpnrb_bit {
// };
// enum rptau_bit {
// };
// enum rptal_bit {
// };
// enum wpsx0_bit {
// };
// enum wpsy0_bit {
// };
// enum wpex0_bit {
// };
// enum wpey0_bit {
// };
// enum wpsx1_bit {
// };
// enum wpsy1_bit {
// };
// enum wpex1_bit {
// };
// enum wpey1_bit {
// };
enum wctla_bit {
  WCTLA__N1LOG__AND = (1 << 15), /* Overlay logic for NBG1  */
  WCTLA__N1SWE = (1 << 13), /* Enable NBG1 on the Sprite window */
  WCTLA__N1SWA__OUTSIDE = (1 << 12), /* Enable the outside of the Sprite window */
  WCTLA__N1W1E = (1 << 11), /* Enable NBG1 on the W1 window */
  WCTLA__N1W1A__OUTSIDE = (1 << 10), /* Enable the outside of the W1 window */
  WCTLA__N1W0E = (1 << 9), /* Enable NBG1 on the W0 window */
  WCTLA__N1W0A__OUTSIDE = (1 << 8), /* Enable the outside of the W0 window */

  WCTLA__N0LOG__AND = (1 << 7), /* Overlay logic for NBG0  */
  WCTLA__N0SWE = (1 << 5), /* Enable NBG0 on the Sprite window */
  WCTLA__N0SWA__OUTSIDE = (1 << 4), /* Enable the outside of the Sprite window */
  WCTLA__N0W1E = (1 << 3), /* Enable NBG0 on the W1 window */
  WCTLA__N0W1A__OUTSIDE = (1 << 2), /* Enable the outside of the W1 window */
  WCTLA__N0W0E = (1 << 1), /* Enable NBG0 on the W0 window */
  WCTLA__N0W0A__OUTSIDE = (1 << 0), /* Enable the outside of the W0 window */
};
enum wctlb_bit {
  WCTLB__N3LOG__AND = (1 << 15), /* Overlay logic for NBG3  */
  WCTLB__N3SWE = (1 << 13), /* Enable NBG3 on the Sprite window */
  WCTLB__N3SWA__OUTSIDE = (1 << 12), /* Enable the outside of the Sprite window */
  WCTLB__N3W1E = (1 << 11), /* Enable NBG3 on the W1 window */
  WCTLB__N3W1A__OUTSIDE = (1 << 10), /* Enable the outside of the W1 window */
  WCTLB__N3W0E = (1 << 9), /* Enable NBG3 on the W0 window */
  WCTLB__N3W0A__OUTSIDE = (1 << 8), /* Enable the outside of the W0 window */

  WCTLB__N2LOG__AND = (1 << 7), /* Overlay logic for NBG2  */
  WCTLB__N2SWE = (1 << 5), /* Enable NBG2 on the Sprite window */
  WCTLB__N2SWA__OUTSIDE = (1 << 4), /* Enable the outside of the Sprite window */
  WCTLB__N2W1E = (1 << 3), /* Enable NBG2 on the W1 window */
  WCTLB__N2W1A__OUTSIDE = (1 << 2), /* Enable the outside of the W1 window */
  WCTLB__N2W0E = (1 << 1), /* Enable NBG2 on the W0 window */
  WCTLB__N2W0A__OUTSIDE = (1 << 0), /* Enable the outside of the W0 window */
};
enum wctlc_bit {
  WCTLC__SPLOG__AND = (1 << 15), /* Overlay logic for Sprite  */
  WCTLC__SPSWE = (1 << 13), /* Enable Sprite on the Sprite window */
  WCTLC__SPSWA__OUTSIDE = (1 << 12), /* Enable the outside of the Sprite window */
  WCTLC__SPW1E = (1 << 11), /* Enable Sprite on the W1 window */
  WCTLC__SPW1A__OUTSIDE = (1 << 10), /* Enable the outside of the W1 window */
  WCTLC__SPW0E = (1 << 9), /* Enable Sprite on the W0 window */
  WCTLC__SPW0A__OUTSIDE = (1 << 8), /* Enable the outside of the W0 window */

  WCTLC__R0LOG__AND = (1 << 7), /* Overlay logic for RBG0  */
  WCTLC__R0SWE = (1 << 5), /* Enable RBG0 on the Sprite window */
  WCTLC__R0SWA__OUTSIDE = (1 << 4), /* Enable the outside of the Sprite window */
  WCTLC__R0W1E = (1 << 3), /* Enable RBG0 on the W1 window */
  WCTLC__R0W1A__OUTSIDE = (1 << 2), /* Enable the outside of the W1 window */
  WCTLC__R0W0E = (1 << 1), /* Enable RBG0 on the W0 window */
  WCTLC__R0W0A__OUTSIDE = (1 << 0), /* Enable the outside of the W0 window */
};
enum wctld_bit {
  WCTLD__CCLOG__AND = (1 << 15), /* Overlay logic for Rotation Parameter  */
  WCTLD__CCSWE = (1 << 13), /* Enable Rotation Parameter on the Sprite window */
  WCTLD__CCSWA__OUTSIDE = (1 << 12), /* Enable the outside of the Sprite window */
  WCTLD__CCW1E = (1 << 11), /* Enable Rotation Parameter on the W1 window */
  WCTLD__CCW1A__OUTSIDE = (1 << 10), /* Enable the outside of the W1 window */
  WCTLD__CCW0E = (1 << 9), /* Enable Rotation Parameter on the W0 window */
  WCTLD__CCW0A__OUTSIDE = (1 << 8), /* Enable the outside of the W0 window */

  WCTLD__RPLOG__AND = (1 << 7), /* Overlay logic for Color Calculation  */
  WCTLD__RPSWE = (1 << 5), /* Enable Color Calculation on the Sprite window */
  WCTLD__RPSWA__OUTSIDE = (1 << 4), /* Enable the outside of the Sprite window */
  WCTLD__RPW1E = (1 << 3), /* Enable Color Calculation on the W1 window */
  WCTLD__RPW1A__OUTSIDE = (1 << 2), /* Enable the outside of the W1 window */
  WCTLD__RPW0E = (1 << 1), /* Enable Color Calculation on the W0 window */
  WCTLD__RPW0A__OUTSIDE = (1 << 0), /* Enable the outside of the W0 window */
};
// enum lwta0u_bit {
// };
// enum lwta0l_bit {
// };
// enum lwta1u_bit {
// };
// enum lwta1l_bit {
// };
enum spctl_bit {
  SPCTL__SPCCCS__LESS_EQUAL    = (0b00 << 12),
  SPCTL__SPCCCS__EQUAL         = (0b01 << 12),
  SPCTL__SPCCCS__GREATER_EQUAL = (0b10 << 12),
  SPCTL__SPCCCS__MSB_1         = (0b11 << 12),
#define SPCTL__SPCCN(n) (((n) & 0b111) << 8)
  SPCTL__SPCLMD = (1 << 5),
  SPCTL__SPWINEN = (1 << 4),
#define SPCTL__SPTYPE(n) (((n) & 0b1111) << 0)
};
enum sdctl_bit {
  SDCTL__TPSDSL = (1 << 8),
  SDCTL__BKSDEN = (1 << 5),
  SDCTL__R0SDEN = (1 << 4),
  SDCTL__N3SDEN = (1 << 3),
  SDCTL__N2SDEN = (1 << 2),
  SDCTL__N1SDEN = (1 << 1),
  SDCTL__N0SDEN = (1 << 0),
};
// enum craofa_bit {
#define CRAOFA__N3CAOS(n) (((n) & 0b111) << 12)
#define CRAOFA__N2CAOS(n) (((n) & 0b111) << 8)
#define CRAOFA__N1CAOS(n) (((n) & 0b111) << 4)
#define CRAOFA__N0CAOS(n) (((n) & 0b111) << 0)
// };
// enum craofb_bit {
#define CRAOFB__SPCAOS(n) (((n) & 0b111) << 4)
#define CRAOFB__R0CAOS(n) (((n) & 0b111) << 0)
// };
enum lnclen_bit {
  LNCLEN__SPLCEN = (1 << 5),
  LNCLEN__R0LCEN = (1 << 4),
  LNCLEN__N3LCEN = (1 << 3),
  LNCLEN__N2LCEN = (1 << 2),
  LNCLEN__N1LCEN = (1 << 1),
  LNCLEN__N0LCEN = (1 << 0),
};
enum sfprmd_bit {
  SFPRMD__R0SPRM__MODE0 = (0b00 << 8),
  SFPRMD__R0SPRM__MODE1 = (0b01 << 8),
  SFPRMD__R0SPRM__MODE2 = (0b10 << 8),

  SFPRMD__N3SPRM__MODE0 = (0b00 << 6),
  SFPRMD__N3SPRM__MODE1 = (0b01 << 6),
  SFPRMD__N3SPRM__MODE2 = (0b10 << 6),

  SFPRMD__N2SPRM__MODE0 = (0b00 << 4),
  SFPRMD__N2SPRM__MODE1 = (0b01 << 4),
  SFPRMD__N2SPRM__MODE2 = (0b10 << 4),

  SFPRMD__N1SPRM__MODE0 = (0b00 << 2),
  SFPRMD__N1SPRM__MODE1 = (0b01 << 2),
  SFPRMD__N1SPRM__MODE2 = (0b10 << 2),

  SFPRMD__N0SPRM__MODE0 = (0b00 << 0),
  SFPRMD__N0SPRM__MODE1 = (0b01 << 0),
  SFPRMD__N0SPRM__MODE2 = (0b10 << 0),
};
enum ccctl_bit {
  CCCTL__BOKEN = (1 << 15),
  CCCTL__BOKN__SPRITE = (0b000 << 12),
  CCCTL__BOKN__RBG0 = (0b001 << 12),
  CCCTL__BOKN__NBG0_OR_RBG1 = (0b010 << 12),
  CCCTL__BOKN__NBG1_OR_EXBG = (0b100 << 12),
  CCCTL__BOKN__NBG2 = (0b101 << 12),
  CCCTL__BOKN__NBG3 = (0b110 << 12),
  CCCTL__EXCCEN = (1 << 10),
  CCCTL__CCRTMD = (1 << 9),
  CCCTL__CCMD = (1 << 8),
  CCCTL__SPCCEN = (1 << 6),
  CCCTL__LCCCEN = (1 << 5),
  CCCTL__R0CCEN = (1 << 4),
  CCCTL__N3CCEN = (1 << 3),
  CCCTL__N2CCEN = (1 << 2),
  CCCTL__N1CCEN = (1 << 1),
  CCCTL__N0CCEN = (1 << 0),
};
enum sfccmd_bit {
  SFCCMD__R0SCCM__PER_SCREEN     = (0b00 << 8),
  SFCCMD__R0SCCM__PER_CHARACTER  = (0b01 << 8),
  SFCCMD__R0SCCM__PER_DOT        = (0b10 << 8),
  SFCCMD__R0SCCM__COLOR_DATA_MSB = (0b11 << 8),

  SFCCMD__N3SCCM__PER_SCREEN     = (0b00 << 6),
  SFCCMD__N3SCCM__PER_CHARACTER  = (0b01 << 6),
  SFCCMD__N3SCCM__PER_DOT        = (0b10 << 6),
  SFCCMD__N3SCCM__COLOR_DATA_MSB = (0b11 << 6),

  SFCCMD__N2SCCM__PER_SCREEN     = (0b00 << 4),
  SFCCMD__N2SCCM__PER_CHARACTER  = (0b01 << 4),
  SFCCMD__N2SCCM__PER_DOT        = (0b10 << 4),
  SFCCMD__N2SCCM__COLOR_DATA_MSB = (0b11 << 4),

  SFCCMD__N1SCCM__PER_SCREEN     = (0b00 << 2),
  SFCCMD__N1SCCM__PER_CHARACTER  = (0b01 << 2),
  SFCCMD__N1SCCM__PER_DOT        = (0b10 << 2),
  SFCCMD__N1SCCM__COLOR_DATA_MSB = (0b11 << 2),

  SFCCMD__N0SCCM__PER_SCREEN     = (0b00 << 0),
  SFCCMD__N0SCCM__PER_CHARACTER  = (0b01 << 0),
  SFCCMD__N0SCCM__PER_DOT        = (0b10 << 0),
  SFCCMD__N0SCCM__COLOR_DATA_MSB = (0b11 << 0),
};
// enum prisa_bit {
#define PRISA__S1PRIN(n) (((n) & 0xff) << 8)
#define PRISA__S0PRIN(n) (((n) & 0xff) << 0)
// };
// enum prisb_bit {
#define PRISA__S3PRIN(n) (((n) & 0xff) << 8)
#define PRISA__S2PRIN(n) (((n) & 0xff) << 0)
// };
// enum prisc_bit {
#define PRISA__S5PRIN(n) (((n) & 0xff) << 8)
#define PRISA__S4PRIN(n) (((n) & 0xff) << 0)
// };
// enum prisd_bit {
#define PRISA__S7PRIN(n) (((n) & 0xff) << 8)
#define PRISA__S6PRIN(n) (((n) & 0xff) << 0)
// };
// enum prina_bit {
#define PRINA__N1PRIN(n) (((n) & 0xff) << 8)
#define PRINA__N0PRIN(n) (((n) & 0xff) << 0)
// };
// enum prinb_bit {
#define PRINB__N3PRIN(n) (((n) & 0xff) << 8)
#define PRINB__N2PRIN(n) (((n) & 0xff) << 0)
// };
// enum prir_bit {
#define PRIR__R0PRIN(n) (((n) & 0xff) << 0)
// };
// enum ccrsa_bit {
#define CCRSA__S1CCRT(n) (((n) & 0xff) << 8)
#define CCRSA__S0CCRT(n) (((n) & 0xff) << 0)
// };
// enum ccrsb_bit {
#define CCRSB__S3CCRT(n) (((n) & 0xff) << 8)
#define CCRSB__S2CCRT(n) (((n) & 0xff) << 0)
// };
// enum ccrsc_bit {
#define CCRSC__S5CCRT(n) (((n) & 0xff) << 8)
#define CCRSC__S4CCRT(n) (((n) & 0xff) << 0)
// };
// enum ccrsd_bit {
#define CCRSD__S7CCRT(n) (((n) & 0xff) << 8)
#define CCRSD__S6CCRT(n) (((n) & 0xff) << 0)
// };
// enum ccrna_bit {
#define CCRNA__N1CCRT(n) (((n) & 0xff) << 8)
#define CCRNA__N0CCRT(n) (((n) & 0xff) << 0)
// };
// enum ccrnb_bit {
#define CCRNB__N3CCRT(n) (((n) & 0xff) << 8)
#define CCRNB__N2CCRT(n) (((n) & 0xff) << 0)
// };
// enum ccrr_bit {
#define CCRR__R0CCRT(n) (((n) & 0xff) << 0)
// };
// enum ccrlb_bit {
#define CCRLB__BKCCRT(n) (((n) & 0xff) << 8)
#define CCRLB__LCCCRT(n) (((n) & 0xff) << 0)
// };
enum clofen_bit {
  CLOFEN__SPCOEN = (1 << 6),
  CLOFEN__BKCOEN = (1 << 5),
  CLOFEN__R0COEN = (1 << 4),
  CLOFEN__N3COEN = (1 << 3),
  CLOFEN__N2COEN = (1 << 2),
  CLOFEN__N1COEN = (1 << 1),
  CLOFEN__N0COEN = (1 << 0),
};
enum clofsl_bit {
  CLOFEN__SPCOSL = (1 << 6),
  CLOFEN__BKCOSL = (1 << 5),
  CLOFEN__R0COSL = (1 << 4),
  CLOFEN__N3COSL = (1 << 3),
  CLOFEN__N2COSL = (1 << 2),
  CLOFEN__N1COSL = (1 << 1),
  CLOFEN__N0COSL = (1 << 0),
};
// enum coar_bit {
#define COAR__COARD() ((n) & 0x1ff)
// };
// enum coag_bit {
#define COAG__COAGR() ((n) & 0x1ff)
// };
// enum coab_bit {
#define COAB__COABL() ((n) & 0x1ff)
// };
// enum cobr_bit {
#define COBR__COBRD() ((n) & 0x1ff)
// };
// enum cobg_bit {
#define COBG__COBGR() ((n) & 0x1ff)
// };
// enum cobb_bit {
#define COBB__COBBL() ((n) & 0x1ff)
// };


//
// pattern name tables
//

#define PATTERN_NAME_TABLE_2WORD__CHARACTER(n) ((n) << 0)
#define PATTERN_NAME_TABLE_2WORD__PALETTE(n) ((n) << 16)

#define PATTERN_NAME_TABLE_1WORD__PALETTE(n) (((n) & 0b1111) << 12)
#define PATTERN_NAME_TABLE_1WORD__CHARACTER(n) (((n) & 0x3ff) << 0)

//
// rotation screen
//

struct vdp2_rotation_parameter_table {
  int32_t screen_start_coordinate_xst;
  int32_t screen_start_coordinate_yst;
  int32_t screen_start_coordinate_zst;
  int32_t screen_vertical_coordinate_increment_dxst;
  int32_t screen_vertical_coordinate_increment_dyst;
  int32_t screen_horizontal_coordinate_increment_dx;
  int32_t screen_horizontal_coordinate_increment_dy;
  int32_t rotation_matrix_parameter_a;
  int32_t rotation_matrix_parameter_b;
  int32_t rotation_matrix_parameter_c;
  int32_t rotation_matrix_parameter_d;
  int32_t rotation_matrix_parameter_e;
  int32_t rotation_matrix_parameter_f;
  int16_t viewpoint_coordinate_px;
  int16_t viewpoint_coordinate_py;
  int16_t viewpoint_coordinate_pz;
  int16_t _pad0;
  int16_t center_point_coordinate_px;
  int16_t center_point_coordinate_py;
  int16_t center_point_coordinate_pz;
  int16_t _pad1;
  int32_t horizontal_shift_mx;
  int32_t horizontal_shift_my;
  int32_t scaling_coefficient_kx;
  int32_t scaling_coefficient_ky;
  int32_t coefficient_table_start_address_kast;
  int32_t coefficient_table_vertical_address_increment_dkast;
  int32_t coefficient_table_horizontal_address_increment_dkax;
};
static_assert((sizeof (struct vdp2_rotation_parameter_table)) == 0x60);
