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

// Formal register names are poorly documented; these are as faithfully as
// possible derived from "4.2 Sound Source Register"
typedef struct scsp_slot {
  struct {     // Loop control
    reg16 LOOP;
    reg16 SA;  // start address
    reg16 LSA; // loop start address
    reg16 LEA; // loop end address
  };
  union {      // EG register
    struct {
      reg16 EGU;
      reg16 EGL;
    };
    reg32 EG;
  };
  reg16 VOLUME; // Sound volume
  reg16 FM;     // FM modulation control
  reg16 PITCH;  // FM pitch control
  reg16 LFO;    // LFO (low-freqency oscillator)
  union {       // slot mixer
    struct {
      reg16 MIXERU;
      reg16 MIXERL;
    };
    reg32 MIXER;
  };
  reg16 _res[0x8 / 2];
} scsp_slot;

static_assert((sizeof (struct scsp_slot)) == 0x20);

// Formal register names are poorly documented; these are as faithfully as
// possible derived from "4.2 Sound Source Register"
typedef struct scsp_ctrl {
  reg16 MIXER;     // master mixer
  reg16 DSP;       // DSP memory control
  union {          // MIDI
    struct {
      reg16 MIDIU;
      reg16 MIDIL;
    };
    reg32 MIDI;
  };
  reg16 STATUS;    // slot status
  reg16 _res[(8 / 2)];
  struct {
    reg16 DMEA;
    reg16 DMAU;
    reg16 DMAL;
  };
  struct {
    reg16 TIMA;
    reg16 TIMB;
    reg16 TIMC;
  };
  struct {
    reg16 SCIEB;
    reg16 SCIPD;
    reg16 SCIRE;
  };
  struct {
    reg16 SCILV0;
    reg16 SCILV1;
    reg16 SCILV2;
  };
  struct {
    reg16 MCIEB;
    reg16 MCIPD;
    reg16 MCIRE;
  };
} scsp_ctrl;

static_assert((sizeof (struct scsp_ctrl)) == 0x30);
static_assert((offsetof (struct scsp_ctrl, STATUS)) == 0x08);
static_assert((offsetof (struct scsp_ctrl, DMEA)) == 0x12);
static_assert((offsetof (struct scsp_ctrl, MCIRE)) == 0x2e);

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
  scsp_ctrl ctrl;
  reg16 _res0[(0x1d0 / 2)];
  struct {
    reg16 gen_a[32];
    reg16 gen_b[32];
  } direct;
  reg16 _res1[(0x80 / 2)];
  scsp_dsp dsp;
} scsp_reg;

static_assert((sizeof (struct scsp_reg)) == 0x000ee4);
static_assert((offsetof (struct scsp_reg, ctrl)) == 0x000400);
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

enum slot_bits {
  LOOP__KYONEX = (    1 << 12), // (KX) execute KEY_ON
  LOOP__KYONB = (     1 << 11), // (KB) record KEY_ON, KEY_OFF
  LOOP__SBCTL = (  0b00 << 10), // source bit control
  LOOP__SSCTL = (  0b00 << 8 ), // sound source control
  LOOP__LPCTL = (  0b00 << 6 ), // loop control
  LOOP__PCM8B = (     1 << 5 ), // (8B) 8bit signed PCM
  LOOP__SA =    (0b0000 << 0 ), // start address
};

enum eg_bits {
  EG__D2R    = (0b00000 << 27), // Decay 2 rate
  EG__D1R    = (0b00000 << 22), // Decay 1 rate
  EG__EGHOLD = (      1 << 21), // (HO) EG hold mode
  EG__AR     = (0b00000 << 16), // Attack rate
  EG__LPSLNK = (      1 << 14), // (LS) Loop start link
  EG__KRS    = ( 0b0000 << 10), // Key rate scaling
  EG__DL     = (0b00000 << 5 ), // Decay level
  EG__RR     = (0b00000 << 0 ), // Release rate
};

enum volume_bits {
  VOLUME__STWINH = (1 << 9), // (SI) Stack write inhibit (FM-related register)
  VOLUME__SDIR   = (1 << 8), // (SD) Sound direct
#define FM__TL(n) ((n) << 0) // Total level
};

enum fm_bits {
  FM__MDL   = (  0b0000 << 12), // Modulation level
  FM__MDXSL = (0b000000 << 6 ), // Select modulation input X
  FM__MDYSL = (0b000000 << 0 ), // Select modulation input Y
};

enum lfo_bits {
  LFO__LFORE  = (      1 << 15), // (RE) LFO reset
  LFO__LFOF   = (0b00000 << 10), // LFO frequency
  LFO__PLFOWS = (   0b00 << 8 ), // Pitch-LFO wave select
  LFO__PLFOS  = (  0b000 << 5 ), // Pitch-LFO sensitivity
  LFO__ALFOWS = (   0b00 << 3 ), // Amplitude-LFO wave select
  LFO__ALFOS  = (  0b000 << 0 ), // Amplitude-LFO sensitivity
};

enum mixer_bits {
  MIXER__ISEL  = ( 0b0000 << 19),
  MIXER__IMXL  = (  0b000 << 16),
  MIXER__DISDL = (  0b000 << 13),
  MIXER__DIPAN = (0b00000 << 8 ),
  MIXER__EFSDL = (  0b000 << 5 ),
  MIXER__EFPAN = (0b00000 << 0 ),
};

//enum pitch_bits {
#define PITCH__OCT(n) ((n) << 11)
#define PITCH__FNS(n) ((n) << 0 )
//};

enum scsp_bits {
  MIXER__MEM4MB = (1 << 9),
  MIXER__DAC18B = (1 << 8),
#define MIXER__MVOL(n) ((n) << 0)
};
