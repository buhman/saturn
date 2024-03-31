#pragma once

#include "type.h"

typedef struct scu_reg {
  reg32 D0R;
  reg32 D0W;
  reg32 D0C;
  reg32 D0AD;
  reg32 D0EN;
  reg32 D0MD;
  reg32 _res0;
  reg32 _res1;
  reg32 D1R;
  reg32 D1W;
  reg32 D1C;
  reg32 D1AD;
  reg32 D1EN;
  reg32 D1MD;
  reg32 _res2;
  reg32 _res3;
  reg32 D2R;
  reg32 D2W;
  reg32 D2C;
  reg32 D2AD;
  reg32 D2EN;
  reg32 D2MD;
  reg32 _res4;
  reg32 _res5;
  reg32 DTSP;
  reg32 _res6;
  reg32 _res7;
  reg32 _res8;
  reg32 _res9;
  reg32 _res10;
  reg32 _res11;
  reg32 DTSA;
  reg32 PPAF;
  reg32 PPD;
  reg32 PDA;
  reg32 PDD;
  reg32 T0C;
  reg32 T1S;
  reg32 T1MD;
  reg32 _res12;
  reg32 IMS;
  reg32 IST;
  reg32 AIACK;
  reg32 _res13;
  reg32 ASR0;
  reg32 ASR1;
  reg32 AREF;
  reg32 _res14;
  reg32 _res15;
  reg32 RSEL;
  reg32 VER;
  reg32 _res16;
} scu_reg;

static_assert((sizeof (struct scu_reg)) == 0xD0);
static_assert((offsetof (struct scu_reg, D1R)) == 0x20);
static_assert((offsetof (struct scu_reg, T1MD)) == 0x98);
static_assert((offsetof (struct scu_reg, AIACK)) == 0xA8);
static_assert((offsetof (struct scu_reg, AREF)) == 0xB8);

struct scu {
  scu_reg reg;
};

extern struct scu scu __asm("scu");

/* bits */

#define D0R__READ_ADDRESS(n) ((n) & 0x3ffffff)
#define D0W__WRITE_ADDRESS(n) ((n) & 0x3ffffff)
#define D0C__BYTE_COUNT(n) ((n) & 0x7ffff)
enum d0ad_bits {
  D0AD__D0RA__0BYTES = (0 << 8),
  D0AD__D0RA__4BYTES = (1 << 8),
  D0AD__D0WA__0BYTES = (0b000 << 0),
  D0AD__D0WA__2BYTES = (0b001 << 0),
  D0AD__D0WA__4BYTES = (0b010 << 0),
  D0AD__D0WA__8BYTES = (0b011 << 0),
  D0AD__D0WA__16BYTES = (0b100 << 0),
  D0AD__D0WA__32BYTES = (0b101 << 0),
  D0AD__D0WA__64BYTES = (0b110 << 0),
  D0AD__D0WA__128BYTES = (0b111 << 0),
};
enum d0en_bits {
  D0EN__D0EN = (1 << 8),
  D0EN__D0GO = (1 << 0),
};
enum d0md_bits {
  D0MD__D0MOD = (1 << 24),
  D0MD__D0RUP = (1 << 16),
  D0MD__D0WUP = (1 << 8),
  D0MD__D0FT__V_BLANK_IN  = (0b000 << 0),
  D0MD__D0FT__V_BLANK_OUT = (0b001 << 0),
  D0MD__D0FT__H_BLANK_IN  = (0b010 << 0),
  D0MD__D0FT__TIMER_0     = (0b011 << 0),
  D0MD__D0FT__TIMER_1     = (0b100 << 0),
  D0MD__D0FT__SOUND_REQ   = (0b101 << 0),
  D0MD__D0FT__SPRITE_DRAW = (0b110 << 0),
  D0MD__D0FT__FACTOR_BIT  = (0b111 << 0),
};

#define D1R__READ_ADDRESS(n) ((n) & 0x3ffffff)
#define D1W__WRITE_ADDRESS(n) ((n) & 0x3ffffff)
#define D1C__BYTE_COUNT(n) ((n) & 0x7ffff)
enum d1ad_bits {
  D1AD__D1RA__0BYTES = (0 << 8),
  D1AD__D1RA__4BYTES = (1 << 8),
  D1AD__D1WA__0BYTES = (0b000 << 0),
  D1AD__D1WA__2BYTES = (0b001 << 0),
  D1AD__D1WA__4BYTES = (0b010 << 0),
  D1AD__D1WA__8BYTES = (0b011 << 0),
  D1AD__D1WA__16BYTES = (0b100 << 0),
  D1AD__D1WA__32BYTES = (0b101 << 0),
  D1AD__D1WA__64BYTES = (0b110 << 0),
  D1AD__D1WA__128BYTES = (0b111 << 0),
};
enum d1en_bits {
  D1EN__D1EN = (1 << 8),
  D1EN__D1GO = (1 << 0),
};
enum d1md_bits {
  D1MD__D1MOD = (1 << 24),
  D1MD__D1RUP = (1 << 16),
  D1MD__D1WUP = (1 << 8),
  D1MD__D1FT__V_BLANK_IN  = (0b000 << 0),
  D1MD__D1FT__V_BLANK_OUT = (0b001 << 0),
  D1MD__D1FT__H_BLANK_IN  = (0b010 << 0),
  D1MD__D1FT__TIMER_0     = (0b011 << 0),
  D1MD__D1FT__TIMER_1     = (0b100 << 0),
  D1MD__D1FT__SOUND_REQ   = (0b101 << 0),
  D1MD__D1FT__SPRITE_DRAW = (0b110 << 0),
  D1MD__D1FT__FACTOR_BIT  = (0b111 << 0),
};

#define D2R__READ_ADDRESS(n) ((n) & 0x3ffffff)
#define D2W__WRITE_ADDRESS(n) ((n) & 0x3ffffff)
#define D2C__BYTE_COUNT(n) ((n) & 0x7ffff)
enum d2ad_bits {
  D2AD__D2RA__0BYTES = (0 << 8),
  D2AD__D2RA__4BYTES = (1 << 8),
  D2AD__D2WA__0BYTES = (0b000 << 0),
  D2AD__D2WA__2BYTES = (0b001 << 0),
  D2AD__D2WA__4BYTES = (0b010 << 0),
  D2AD__D2WA__8BYTES = (0b011 << 0),
  D2AD__D2WA__16BYTES = (0b100 << 0),
  D2AD__D2WA__32BYTES = (0b101 << 0),
  D2AD__D2WA__64BYTES = (0b110 << 0),
  D2AD__D2WA__128BYTES = (0b111 << 0),
};
enum d2en_bits {
  D2EN__D2EN = (1 << 8),
  D2EN__D2GO = (1 << 0),
};
enum d2md_bits {
  D2MD__D2MOD = (1 << 24),
  D2MD__D2RUP = (1 << 16),
  D2MD__D2WUP = (1 << 8),
  D2MD__D2FT__V_BLANK_IN  = (0b000 << 0),
  D2MD__D2FT__V_BLANK_OUT = (0b001 << 0),
  D2MD__D2FT__H_BLANK_IN  = (0b010 << 0),
  D2MD__D2FT__TIMER_0     = (0b011 << 0),
  D2MD__D2FT__TIMER_1     = (0b100 << 0),
  D2MD__D2FT__SOUND_REQ   = (0b101 << 0),
  D2MD__D2FT__SPRITE_DRAW = (0b110 << 0),
  D2MD__D2FT__FACTOR_BIT  = (0b111 << 0),
};

enum dstp_bits {
  DSTP__FORCE_STOP = (1 << 0),
};

enum dsta_bits {
  DSTA__DACSD = (1 << 22),
  DSTA__DACSB = (1 << 21),
  DSTA__DACSA = (1 << 20),
  DSTA__D1BK  = (1 << 17),
  DSTA__D0BK  = (1 << 16),
  DSTA__D2WT  = (1 << 13),
  DSTA__D2MV  = (1 << 12),
  DSTA__D1WT  = (1 << 9),
  DSTA__D1MV  = (1 << 8),
  DSTA__D0WT  = (1 << 5),
  DSTA__D0MV  = (1 << 4),
  DSTA__DDWT  = (1 << 1),
  DSTA__DDMV  = (1 << 0),
};

enum ppaf_bits {
  PPAF__PR = (1 << 26),
  PPAF__EP = (1 << 25),
  PPAF__T0 = (1 << 23),
  PPAF__S  = (1 << 22),
  PPAF__Z  = (1 << 21),
  PPAF__C  = (1 << 20),
  PPAF__V  = (1 << 19),
  PPAF__E  = (1 << 18),
  PPAF__ES = (1 << 17),
  PPAF__EX = (1 << 16),
  PPAF__LE = (1 << 15),
#define PPAF__PRG_ADDRESS(n) (((n) & 0xff) << 0)
};

enum pda_bits {
  PDA__RA__RAM0 = (0b00 << 6),
  PDA__RA__RAM1 = (0b01 << 6),
  PDA__RA__RAM2 = (0b10 << 6),
  PDA__RA__RAM3 = (0b11 << 6),
#define PDA__RAM_ADDRESS(n) (((n) & 0x3f) << 0)
};

enum ims_bits {
  IMS__A_BUS = (1 << 15),
  IMS__SPRITE_DRAW_END = (1 << 13),
  IMS__DMA_ILLEGAL = (1 << 12),
  IMS__DMA0_END = (1 << 11),
  IMS__DMA1_END = (1 << 10),
  IMS__DMA2_END = (1 << 9),
  IMS__PAD = (1 << 8),
  IMS__SMPC = (1 << 7),
  IMS__SOUND_REQUEST = (1 << 6),
  IMS__DSP_END = (1 << 5),
  IMS__TIMER1 = (1 << 4),
  IMS__TIMER0 = (1 << 3),
  IMS__H_BLANK_IN = (1 << 2),
  IMS__V_BLANK_OUT = (1 << 1),
  IMS__V_BLANK_IN = (1 << 0),
};

enum ist_bits {
  IST__EXT15 = (1 << 31),
  IST__EXT14 = (1 << 30),
  IST__EXT13 = (1 << 29),
  IST__EXT12 = (1 << 28),
  IST__EXT11 = (1 << 27),
  IST__EXT10 = (1 << 26),
  IST__EXT09 = (1 << 25),
  IST__EXT08 = (1 << 24),
  IST__EXT07 = (1 << 23),
  IST__EXT06 = (1 << 22),
  IST__EXT05 = (1 << 21),
  IST__EXT04 = (1 << 20),
  IST__EXT03 = (1 << 19),
  IST__EXT02 = (1 << 18),
  IST__EXT01 = (1 << 17),
  IST__EXT00 = (1 << 16),

  IST__SPRITE_DRAW_END = (1 << 13),
  IST__DMA_ILLEGAL = (1 << 12),
  IST__DMA0_END = (1 << 11),
  IST__DMA1_END = (1 << 10),
  IST__DMA2_END = (1 << 9),
  IST__PAD = (1 << 8),
  IST__SMPC = (1 << 7),
  IST__SOUND_REQUEST = (1 << 6),
  IST__DSP_END = (1 << 5),
  IST__TIMER1 = (1 << 4),
  IST__TIMER0 = (1 << 3),
  IST__H_BLANK_IN = (1 << 2),
  IST__V_BLANK_OUT = (1 << 1),
  IST__V_BLANK_IN = (1 << 0),
};

enum t1md_bits {
  T1MD__T1MD = (1 << 8),
  T1MD__TENB = (1 << 0),
};

enum scu_vec {
  SCU_VEC__V_BLANK_IN = 0x40,
  SCU_VEC__V_BLANK_OUT,
  SCU_VEC__H_BLANK_IN,
  SCU_VEC__TIMER0,
  SCU_VEC__TIMER1,
  SCU_VEC__DSP_END,
  SCU_VEC__SOUND_REQUEST,
  SCU_VEC__SMPC,
  SCU_VEC__PAD,
  SCU_VEC__DMA2_END,
  SCU_VEC__DMA1_END,
  SCU_VEC__DMA0_END,
  SCU_VEC__DMA_ILLEGAL,
  SCU_VEC__SPRITE_DRAW_END,
  __scu_vec_res0,
  __scu_vec_res1,
  SCU_VEC__EXT00,
  SCU_VEC__EXT01,
  SCU_VEC__EXT02,
  SCU_VEC__EXT03,
  SCU_VEC__EXT04,
  SCU_VEC__EXT05,
  SCU_VEC__EXT06,
  SCU_VEC__EXT07,
  SCU_VEC__EXT08,
  SCU_VEC__EXT09,
  SCU_VEC__EXT10,
  SCU_VEC__EXT11,
  SCU_VEC__EXT12,
  SCU_VEC__EXT13,
  SCU_VEC__EXT14,
  SCU_VEC__EXT15,
};

static_assert(SCU_VEC__EXT15 == 0x5f);
