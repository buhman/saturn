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
  reg16 CYCA0L; /* VRAM CYCLE PATTERN (BANK A0) */
  reg16 CYCA0U; /* VRAM CYCLE PATTERN (BANK A0) */
  reg16 CYCA1L; /* VRAM CYCLE PATTERN (BANK A1) */
  reg16 CYCA1U; /* VRAM CYCLE PATTERN (BANK A1) */
  reg16 CYCB0L; /* VRAM CYCLE PATTERN (BANK A0) */
  reg16 CYCB0U; /* VRAM CYCLE PATTERN (BANK A0) */
  reg16 CYCB1L; /* VRAM CYCLE PATTERN (BANK B1) */
  reg16 CYCB1U; /* VRAM CYCLE PATTERN (BANK B1) */
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
  reg16 MPABN0; /* MAP (NBG0, PLANE A,B) */
  reg16 MPCDN0; /* MAP (NBG0, PLANE C,D) */
  reg16 MPABN1; /* MAP (NBG1, PLANE A,B) */
  reg16 MPCDN1; /* MAP (NBG1, PLANE C,D) */
  reg16 MPABN2; /* MAP (NBG2, PLANE A,B) */
  reg16 MPCDN2; /* MAP (NBG2, PLANE C,D) */
  reg16 MPABN3; /* MAP (NBG3, PLANE A,B) */
  reg16 MPCDN3; /* MAP (NBG3, PLANE C,D) */
  reg16 MPABRA; /* MAP (ROTATION PARAMETER A, PLANE A,B) */
  reg16 MPCDRA; /* MAP (ROTATION PARAMETER A, PLANE C,D) */
  reg16 MPEFRA; /* MAP (ROTATION PARAMETER A, PLANE E,F) */
  reg16 MPGHRA; /* MAP (ROTATION PARAMETER A, PLANE G,H) */
  reg16 MPIJRA; /* MAP (ROTATION PARAMETER A, PLANE I,J) */
  reg16 MPKLRA; /* MAP (ROTATION PARAMETER A, PLANE K,L) */
  reg16 MPMNRA; /* MAP (ROTATION PARAMETER A, PLANE M,N) */
  reg16 MPOPRA; /* MAP (ROTATION PARAMETER A, PLANE O,P) */
  reg16 MPABRB; /* MAP (ROTATION PARAMETER B, PLANE B,B) */
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
  reg16 VCSTAU; /* VERTICAL CELL SCROLL TABLE ADDRESS (NBGO, NBG1) */
  reg16 VCSTAL; /* VERTICAL CELL SCROLL TABLE ADDRESS (NBGO, NBG1) */
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
  reg16 RPTAU;  /* ROTATION PARAMETER TABLE ADDRESS (ROTATION PARAMETER A,B) */
  reg16 RPTAL;  /* ROTATION PARAMETER TABLE ADDRESS (ROTATION PARAMETER A,B) */
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

enum bits_tvmd {
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
// enum bits_exten {
// };
enum bits_tvstat {
  TVSTAT__VBLANK = (1 << 3),
};
// enum bits_vrsize {
// };
// enum bits_hcnt {
// };
// enum bits_vcnt {
// };
// enum bits_ramctl {
// };
// enum bits_cyca0l {
// };
// enum bits_cyca0u {
// };
// enum bits_cyca1l {
// };
// enum bits_cyca1u {
// };
// enum bits_cycb0l {
// };
// enum bits_cycb0u {
// };
// enum bits_cycb1l {
// };
// enum bits_cycb1u {
// };
enum bits_bgon {
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
// enum bits_mzctl {
// };
// enum bits_sfsel {
// };
// enum bits_sfcode {
// };
enum bits_chctla {
  CHCTLA__N1CHCN__16_COLOR = (0b00 << 12),
  CHCTLA__N1CHCN__256_COLOR = (0b00 << 12),
  CHCTLA__N1CHCN__2K_COLOR = (0b00 << 12),
  CHCTLA__N1CHCN__32K_COLOR = (0b00 << 12),

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
  CHCTLA__N0CHCN__2K_COLOR = (0b010 << 4),
  CHCTLA__N0CHCN__32K_COLOR = (0b011 << 4),
  CHCTLA__N0CHCN__16M_COLOR = (0b100 << 4),

  CHCTLA__N0BMSZ__512x256_DOT = (0b00 << 2),
  CHCTLA__N0BMSZ__512x512_DOT = (0b01 << 2),
  CHCTLA__N0BMSZ__1024x256_DOT = (0b10 << 2),
  CHCTLA__N0BMSZ__1024x512_DOT = (0b11 << 2),

  CHCTLA__N0BMEN__CELL_FORMAT = (0 << 1),
  CHCTLA__N0BMEN__BITMAP_FORMAT = (0 << 1),

  CHCTLA__N0CHSZ__1x1_CELL = (0 << 0),
  CHCTLA__N0CHSZ__2x2_CELL = (1 << 0),
};
enum bits_chctlb {
  CHCTLB__R0CHCN__16_COLOR = (0b000 << 12),
  CHCTLB__R0CHCN__256_COLOR = (0b001 << 12),
  CHCTLB__R0CHCN__2K_COLOR = (0b010 << 12),
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
// enum bits_bmpna {
// };
// enum bits_bmpnb {
// };

enum bits_pncn0 {
  PNCN0__N0PNB__2WORD = (0 << 15),
  PNCN0__N0PNB__1WORD = (1 << 15),
  PNCN0__N0CNSM = (1 << 14),
  PNCN0__N0SPR = (1 << 9),
  PNCN0__N0SCC = (1 << 8),
#define PNCN0__N0SPLT(n) (n << 5)
#define PNCN0__N0SCN(n) (n << 0)
};

enum bits_pncn1 {
  PNCN1__N1PNB__2WORD = (0 << 15),
  PNCN1__N1PNB__1WORD = (1 << 15),
  PNCN1__N1CNSM = (1 << 14),
  PNCN1__N1SPR = (1 << 9),
  PNCN1__N1SCC = (1 << 8),
#define PNCN1__N1SPLT(n) (n << 5)
#define PNCN1__N1SCN(n) (n << 0)
};

enum bits_pncn2 {
  PNCN2__N2PNB__2WORD = (0 << 15),
  PNCN2__N2PNB__1WORD = (1 << 15),
  PNCN2__N2CNSM = (1 << 14),
  PNCN2__N2SPR = (1 << 9),
  PNCN2__N2SCC = (1 << 8),
#define PNCN2__N2SPLT(n) (n << 5)
#define PNCN2__N2SCN(n) (n << 0)
};

enum bits_pncn3 {
  PNCN3__N3PNB__2WORD = (0 << 15),
  PNCN3__N3PNB__1WORD = (1 << 15),
  PNCN3__N3CNSM = (1 << 14),
  PNCN3__N3SPR = (1 << 9),
  PNCN3__N3SCC = (1 << 8),
#define PNCN3__N3SPLT(n) (n << 5)
#define PNCN3__N3SCN(n) (n << 0)
};

enum bits_pncr {
  PNCR__R0PNB__2WORD = (0 << 15),
  PNCR__R0PNB__1WORD = (1 << 15),
  PNCR__R0CNSM = (1 << 14),
  PNCR__R0SPR = (1 << 9),
  PNCR__R0SCC = (1 << 8),
#define PNCR__R0SPLT(n) (n << 5)
#define PNCR__R0SCN(n) (n << 0)
};

enum bits_plsz {
  PLSZ__RBOVR__ = (0b00 << 14),
  PLSZ__RBPLSZ__ = (0b00 << 12),
  PLSZ__RAOVR__ = (0b00 << 10),
  PLSZ__RAPLSZ__ = (0b00 << 8),

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
// enum bits_mpofn {
#define MPOFN__N3MP(n) (n << 12)
#define MPOFN__N2MP(n) (n << 8)
#define MPOFN__N1MP(n) (n << 4)
#define MPOFN__N0MP(n) (n << 0)
// };
// enum bits_mpofr {
#define MPOFR__RBMP(n) (n << 4)
#define MPOFR__RAMP(n) (n << 0)
// };

// 4.8 Maps § Map Selection Register

// enum bits_mpabn0 {
#define MPABN0__N0MPB(n) (n << 8)
#define MPABN0__N0MPA(n) (n << 0)
// };
// enum bits_mpcdn0 {
#define MPABN0__N0MPD(n) (n << 8)
#define MPABN0__N0MPC(n) (n << 0)
// };
// enum bits_mpabn1 {
#define MPABN1__N1MPB(n) (n << 8)
#define MPABN1__N1MPA(n) (n << 0)
// };
// enum bits_mpcdn1 {
#define MPABN1__N1MPD(n) (n << 8)
#define MPABN1__N1MPC(n) (n << 0)
// };
// enum bits_mpabn2 {
#define MPABN2__N2MPB(n) (n << 8)
#define MPABN2__N2MPA(n) (n << 0)
// };
// enum bits_mpcdn2 {
#define MPABN2__N2MPD(n) (n << 8)
#define MPABN2__N2MPC(n) (n << 0)
// };
// enum bits_mpabn3 {
#define MPABN3__N3MPB(n) (n << 8)
#define MPABN3__N3MPA(n) (n << 0)
// };
// enum bits_mpcdn3 {
#define MPABN3__N3MPD(n) (n << 8)
#define MPABN3__N3MPC(n) (n << 0)
// };
// enum bits_mpabra {
// };
// enum bits_mpcdra {
// };
// enum bits_mpefra {
// };
// enum bits_mpghra {
// };
// enum bits_mpijra {
// };
// enum bits_mpklra {
// };
// enum bits_mpmnra {
// };
// enum bits_mpopra {
// };
// enum bits_mpabrb {
// };
// enum bits_mpcdrb {
// };
// enum bits_mpefrb {
// };
// enum bits_mpghrb {
// };
// enum bits_mpijrb {
// };
// enum bits_mpklrb {
// };
// enum bits_mpmnrb {
// };
// enum bits_mpoprb {
// };
// enum bits_scxin0 {
// };
// enum bits_scxdn0 {
// };
// enum bits_scyin0 {
// };
// enum bits_scydn0 {
// };
// enum bits_zmxin0 {
// };
// enum bits_zmxdn0 {
// };
// enum bits_zmyin0 {
// };
// enum bits_zmydn0 {
// };
// enum bits_scxin1 {
// };
// enum bits_scxdn1 {
// };
// enum bits_scyin1 {
// };
// enum bits_scydn1 {
// };
// enum bits_zmxin1 {
// };
// enum bits_zmxdn1 {
// };
// enum bits_zmyin1 {
// };
// enum bits_zmydn1 {
// };
// enum bits_scxn2 {
// };
// enum bits_scyn2 {
// };
// enum bits_scxn3 {
// };
// enum bits_scyn3 {
// };
// enum bits_zmctl {
// };
// enum bits_scrctl {
// };
// enum bits_vcstau {
// };
// enum bits_vcstal {
// };
// enum bits_lsta0u {
// };
// enum bits_lsta0l {
// };
// enum bits_lsta1u {
// };
// enum bits_lsta1l {
// };
// enum bits_lctau {
// };
// enum bits_lctal {
// };
enum bits_bktau {
  BKTAU__BKCLMD_SINGLE_COLOR = (0 << 15),
  BKTAU__BKCLMD_PER_LINE = (1 << 15),
};
// enum bits_bktal {
// };
// enum bits_rpmd {
// };
// enum bits_rprctl {
// };
// enum bits_ktctl {
// };
// enum bits_ktaof {
// };
// enum bits_ovpnra {
// };
// enum bits_ovpnrb {
// };
// enum bits_rptau {
// };
// enum bits_rptal {
// };
// enum bits_wpsx0 {
// };
// enum bits_wpsy0 {
// };
// enum bits_wpex0 {
// };
// enum bits_wpey0 {
// };
// enum bits_wpsx1 {
// };
// enum bits_wpsy1 {
// };
// enum bits_wpex1 {
// };
// enum bits_wpey1 {
// };
// enum bits_wctla {
// };
// enum bits_wctlb {
// };
// enum bits_wctlc {
// };
// enum bits_wctld {
// };
// enum bits_lwta0u {
// };
// enum bits_lwta0l {
// };
// enum bits_lwta1u {
// };
// enum bits_lwta1l {
// };
// enum bits_spctl {
// };
// enum bits_sdctl {
// };
// enum bits_craofa {
// };
// enum bits_craofb {
// };
// enum bits_lnclen {
// };
// enum bits_sfprmd {
// };
// enum bits_ccctl {
// };
// enum bits_sfccmd {
// };
// enum bits_prisa {
// };
// enum bits_prisb {
// };
// enum bits_prisc {
// };
// enum bits_prisd {
// };
// enum bits_prina {
// };
// enum bits_prinb {
// };
// enum bits_prir {
// };
// enum bits_ccrsa {
// };
// enum bits_ccrsb {
// };
// enum bits_ccrsc {
// };
// enum bits_ccrsd {
// };
// enum bits_ccrna {
// };
// enum bits_ccrnb {
// };
// enum bits_ccrr {
// };
// enum bits_ccrlb {
// };
// enum bits_clofen {
// };
// enum bits_clofsl {
// };
// enum bits_coar {
// };
// enum bits_coag {
// };
// enum bits_coab {
// };
// enum bits_cobr {
// };
// enum bits_cobg {
// };
// enum bits_cobb {
// };


//
// pattern name tables
//

#define PATTERN_NAME_TABLE_2WORD__CHARACTER(n) (n << 0)
#define PATTERN_NAME_TABLE_2WORD__PALETTE(n) (n << 16)
