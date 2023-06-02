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
static_assert((offsetof (struct scu_reg, AIACK)) == 0xA8);
static_assert((offsetof (struct scu_reg, AREF)) == 0xB8);

struct scu {
  scu_reg reg;
};

extern struct scu scu __asm("scu");

/* bits */

enum ims_bits {
  IMS__A_BUS = (1 << 15),
  IMS__DRAW_END = (1 << 13),
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

  IST__DRAW_END = (1 << 13),
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
  SCU_VEC__DRAW_END,
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
