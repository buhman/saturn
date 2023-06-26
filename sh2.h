#pragma once

#include "type.h"

#include <cstddef>

typedef struct sh2_reg {
  reg8 SMR;      // 0x000
  reg8 BRR;      // 0x001
  reg8 SCR;      // 0x002
  reg8 TDR;      // 0x003
  reg8 SSR;      // 0x004
  reg8 RDR;      // 0x005
  reg8 _res0[10];
  reg8 TIER;     // 0x010
  reg8 FTCSR;    // 0x011
  struct {
    reg8 H;      // 0x012
    reg8 L;      // 0x013
  } FRC;
  struct {
    reg8 H;      // 0x014
    reg8 L;      // 0x015
  } OCRAB;
  reg8 TCR;      // 0x016
  reg8 TOCR;     // 0x017
  struct {
    reg8 H;      // 0x018
    reg8 L;      // 0x018
  } FICR;
  reg8 _res1[70];
  reg16 IPRB;    // 0x060
  reg16 VCRA;    // 0x062
  reg16 VCRB;    // 0x064
  reg16 VCRC;    // 0x066
  reg16 VCRD;    // 0x068
  reg8 _res2[7];
  reg8 DRCR0;    // 0x071
  reg8 DRCR1;    // 0x072
  reg8 _res3[13];
  reg8 WTCSR;    // 0x080
  reg8 WTCNT;    // 0x081
  reg8 _res4[1];
  reg8 WSTCSR;   // 0x083
  reg8 _res5[13];
  reg8 SBYCR;    // 0x091
  reg8 CCR;      // 0x092
  reg8 _res6[77];
  reg16 ICR;     // 0x0e0
  reg16 IPRA;    // 0x0e2
  reg16 VCRWDT;  // 0x0e4
  reg8 _res7[26];
  reg32 DVSR;    // 0x100
  reg32 DVDNT;   // 0x104
  reg32 DVCR;    // 0x108
  reg32 VCRDIV;  // 0x10c
  reg32 DVDNTH;  // 0x110
  reg32 DVDNTL;  // 0x114
  reg8 _res8[40];
  reg16 BARAH;   // 0x140
  reg16 BARAL;   // 0x142
  reg16 BAMRAH;  // 0x144
  reg16 BAMRAL;  // 0x146
  reg16 BBRA;    // 0x148
  reg8 _res9[22];
  reg16 BARBH;   // 0x160
  reg16 BARBL;   // 0x162
  reg16 BAMRBH;  // 0x164
  reg16 BAMRBL;  // 0x166
  reg16 BBRB;    // 0x168
  reg8 _res10[6];
  reg16 BDRBH;   // 0x170
  reg16 BDRBL;   // 0x172
  reg16 BDMRBH;  // 0x174
  reg16 BDMRBL;  // 0x176
  reg16 BRCR;    // 0x178
  reg8 _res11[6];
  reg32 SAR0;    // 0x180
  reg32 DAR0;    // 0x184
  reg32 TCR0;    // 0x188
  reg32 CHCR0;   // 0x18c
  reg32 SAR1;    // 0x190
  reg32 DAR1;    // 0x194
  reg32 TCR1;    // 0x198
  reg32 CHCR1;   // 0x19c
  reg32 VCRMA0;  // 0x1a0
  reg8 _res12[4];
  reg32 VCRDMA1; // 0x1a8
  reg8 _res13[4];
  reg32 DMAOR;   // 0x1b0
  reg8 _res14[44];
  reg32 BCR1;    // 0x1e0
  reg32 BCR2;    // 0x1e4
  reg32 WCR;     // 0x1e8
  reg32 MCR;     // 0x1ec
  reg32 RTCSR;   // 0x1f0
  reg32 RTCNT;   // 0x1f4
  reg32 RTCOR;   // 0x1f8
  reg8 _res15[4];
} sh2_reg;

static_assert((sizeof (struct sh2_reg)) == 0x200);
static_assert((offsetof (struct sh2_reg, OCRAB)) == 0x014);
static_assert((offsetof (struct sh2_reg, BCR1)) == 0x1e0);
static_assert((offsetof (struct sh2_reg, DVSR)) == 0x100);

struct sh2 {
  sh2_reg reg;
};

extern struct sh2 sh2 __asm("sh2");

extern reg32 sh2_vec[0xff] __asm("sh2_vec");

enum tier_bits {
  TIER__ICIE = (1 << 7),
  TIER__OCIAE = (1 << 3),
  TIER__OCIBE = (1 << 2),
  TIER__OVIE = (1 << 1),
};
enum ftcsr_bits {
  FTCSR__ICF = (1 << 7),
  FTCSR__OCFA = (1 << 3),
  FTCSR__OCFB = (1 << 2),
  FTCSR__OVF = (1 << 1),
  FTCSR__CCLRA = (1 << 0),
};
enum tcr_bits {
  TCR__IEDGA__RISING_EDGE = (1 << 7),
  TCR__CKS__INTERNAL_DIV8 = (0b00),
  TCR__CKS__INTERNAL_DIV32 = (0b01),
  TCR__CKS__INTERNAL_DIV128 = (0b10),
  TCR__CKS__EXTERNAL_RISING = (0b11),
};
enum tocr_bits {
  TOCR__OCRS__OCRA = (0 << 4),
  TOCR__OCRS__OCRB = (1 << 4),
  TOCR__OLVLA = (1 << 1),
  TOCR__OLBLB = (1 << 0),
};
// enum vcra_bits {
#define VCRA__SERV(n) (n << 8)
#define VCRA__SRXV(n) (n << 0)
// };
// enum vcrb_bits {
#define VCRB__STXV(n) (n << 8)
#define VCRB__STEV(n) (n << 0)
// };
// enum vcrc_bits {
#define VCRC__FICV(n) (n << 8) // input-capture interrupt vector number
#define VCRC__FOCV(n) (n << 0) // output-compare interrupt vector number
// };
// enum vcrd_bits {
#define VCRD__FOVV(n) (n << 8)
// };
