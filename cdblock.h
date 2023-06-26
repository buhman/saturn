#pragma once

#include "type.h"

struct cr_rr {
  reg16 val;
  reg16 _res;
};

typedef struct cdc_reg {
  reg16 DTR;
  reg8 _res0[6];
  reg16 HIRQ;
  reg16 _res1;
  reg16 HMASK;
  reg8 _res2[10];
  union {
    struct cr_rr CR[4];
    struct cr_rr RR[4];
  };
} cdc_reg;

static_assert((offsetof (struct cdc_reg, DTR)) == 0x00);
static_assert((offsetof (struct cdc_reg, HIRQ)) == 0x08);
static_assert((offsetof (struct cdc_reg, HMASK)) == 0x0c);
static_assert((offsetof (struct cdc_reg, RR)) == 0x18);
static_assert((offsetof (struct cdc_reg, RR[0].val)) == 0x18);
static_assert((offsetof (struct cdc_reg, RR[1].val)) == 0x1c);
static_assert((offsetof (struct cdc_reg, RR[2].val)) == 0x20);
static_assert((offsetof (struct cdc_reg, RR[3].val)) == 0x24);
static_assert((offsetof (struct cdc_reg, CR[0].val)) == 0x18);
static_assert((offsetof (struct cdc_reg, CR[1].val)) == 0x1c);
static_assert((offsetof (struct cdc_reg, CR[2].val)) == 0x20);
static_assert((offsetof (struct cdc_reg, CR[3].val)) == 0x24);

struct cdc {
  cdc_reg reg;
};

extern struct cdc cdc __asm("cdc");

#define CDC__HIRQ__MPST (1 << 13)  // MPEG interrupt status
#define CDC__HIRQ__MPCM (1 << 12)  // End of MPEG undefined operation section
#define CDC__HIRQ__MPED (1 << 11)  // End of MPEG processing
#define CDC__HIRQ__SCDQ (1 << 10)  // Subcode Q update complete
#define CDC__HIRQ__EFLS (1 << 9)   // End of file system processing
#define CDC__HIRQ__ECPY (1 << 8)   // End of copy/move process
#define CDC__HIRQ__EHST (1 << 7)   // End of host I/O processing
#define CDC__HIRQ__ESEL (1 << 6)   // End of selector setting process
#define CDC__HIRQ__DCHG (1 << 5)   // Disk change occured
#define CDC__HIRQ__PEND (1 << 4)   // End of CD playback
#define CDC__HIRQ__BFUL (1 << 3)   // CD buffer full
#define CDC__HIRQ__CSCT (1 << 2)   // 1 sector read complete
#define CDC__HIRQ__DRDY (1 << 1)   // Ready for data transfer
#define CDC__HIRQ__CMOK (1 << 0)   // Ready for command

enum
{
  CMD__GET_CDSTATUS    = 0x00,
  CMD__GET_HWINFO      = 0x01,
  CMD__GET_TOC         = 0x02,
  CMD__GET_SESSINFO    = 0x03,
  CMD__INIT            = 0x04,
  CMD__OPEN            = 0x05,
  CMD__END_DATAXFER    = 0x06,

  CMD__PLAY            = 0x10,
  CMD__SEEK            = 0x11,
  CMD__SCAN            = 0x12,

  CMD__GET_SUBCODE     = 0x20,

  CMD__SET_CDDEVCONN   = 0x30,
  CMD__GET_CDDEVCONN   = 0x31,
  CMD__GET_LASTBUFDST  = 0x32,

  CMD__SET_FILTRANGE   = 0x40,
  CMD__GET_FILTRANGE   = 0x41,
  CMD__SET_FILTSUBHC   = 0x42,
  CMD__GET_FILTSUBHC   = 0x43,
  CMD__SET_FILTMODE    = 0x44,
  CMD__GET_FILTMODE    = 0x45,
  CMD__SET_FILTCONN    = 0x46,
  CMD__GET_FILTCONN    = 0x47,
  CMD__RESET_SEL       = 0x48,

  CMD__GET_BUFSIZE     = 0x50,
  CMD__GET_SECNUM      = 0x51,
  CMD__CALC_ACTSIZE    = 0x52,
  CMD__GET_ACTSIZE     = 0x53,
  CMD__GET_SECINFO     = 0x54,
  CMD__EXEC_FADSRCH    = 0x55,
  CMD__GET_FADSRCH     = 0x56,

  CMD__SET_SECLEN      = 0x60,
  CMD__GET_SECDATA     = 0x61,
  CMD__DEL_SECDATA     = 0x62,
  CMD__GETDEL_SECDATA  = 0x63,
  CMD__PUT_SECDATA     = 0x64,
  CMD__COPY_SECDATA    = 0x65,
  CMD__MOVE_SECDATA    = 0x66,
  CMD__GET_COPYERR     = 0x67,

  CMD__CHANGE_DIR      = 0x70,
  CMD__READ_DIR        = 0x71,
  CMD__GET_FSSCOPE     = 0x72,
  CMD__GET_FINFO       = 0x73,
  CMD__READ_FILE       = 0x74,
  CMD__ABORT_FILE      = 0x75,

  CMD__AUTH_DEVICE     = 0xE0,
  CMD__GET_AUTH        = 0xE1
};
