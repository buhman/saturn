#include "type.h"

// Because the main CPU cannot access in units of 8 bits, so read and write in
// 16 bit units.
//
// (presumably m68k can do 32-byte accesses)

typedef union scsp_ram {
  unsigned short u16[0x080000 / 2];
  unsigned long  u32[0x080000 / 4];
} scsp_ram;

static_assert((sizeof (union scsp_ram)) == 0x080000);

typedef unsigned char scsp_res0[0x080000];

typedef struct scsp_slot {
  reg16 field[0x18 / 2];
  reg16 _res[0x8 / 2];
} scsp_slot;

static_assert((sizeof (struct scsp_slot)) == 0x20);

typedef struct scsp_dsp {
  reg16 COEF[64];
  reg16 MADRS[32];
  reg16 _res[0x40 / 2];
  reg16 micro[512];
  reg16 internal[370];
} scsp_dsp;

static_assert((sizeof (struct scsp_dsp)) == 0x7e4);

typedef struct scsp_reg {
  scsp_slot slot[32];
  reg16 common[0x30 / 2];
  reg16 _res0[0x1d0 / 2];
  struct {
    reg16 gen_a[32];
    reg16 gen_b[32];
  } direct;
  reg16 _res1[0x80 / 2];
  scsp_dsp dsp;
} scsp_reg;

static_assert((sizeof (struct scsp_reg)) == 0x000ee4);
static_assert((offsetof (struct scsp_reg, common)) == 0x000400);
static_assert((offsetof (struct scsp_reg, direct)) == 0x000600);
static_assert((offsetof (struct scsp_reg, dsp)) == 0x000700);

struct scsp {
  scsp_ram ram;
  scsp_res0 _res0;
  scsp_reg reg;
};

extern struct scsp scsp __asm("scsp");

static_assert((sizeof (struct scsp)) == 0x100ee4);
static_assert((offsetof (struct scsp, ram)) == 0x000000);
static_assert((offsetof (struct scsp, reg)) == 0x100000);

// bits

enum scsp_bits {
  SCSP__0__MEM4MB = (1 << 9),
  SCSP__0__DAC18B = (1 << 8),
};
