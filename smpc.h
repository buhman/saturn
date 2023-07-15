#pragma once

#include "type.h"

struct ioreg {
  reg8 _res;
  reg8 val;
};

struct smpc_reg {
  struct ioreg IREG[7];
  reg8 _res7;
  reg8 _res8;
  reg8 _res9;
  reg8 _res10;
  reg8 _res11;
  reg8 _res12;
  reg8 _res13;
  reg8 _res14;
  reg8 _res15;
  reg8 _res16;
  reg8 _res17;
  reg8 _res18;
  reg8 _res19;
  reg8 _res20;
  reg8 _res21;
  reg8 _res22;
  reg8 _res23;
  reg8 COMREG;
  struct ioreg OREG[32];
  reg8 _res56;
  reg8 SR;
  reg8 _res57;
  reg8 SF;
  reg8 _res58;
  reg8 _res59;
  reg8 _res60;
  reg8 _res61;
  reg8 _res62;
  reg8 _res63;
  reg8 _res64;
  reg8 _res65;
  reg8 _res66;
  reg8 _res67;
  reg8 _res68;
  reg8 _res69;
  reg8 _res70;
  reg8 _res71;
  reg8 _res72;
  reg8 _res73;
  reg8 _res74;
  reg8 PDR1;
  reg8 _res75;
  reg8 PDR2;
  reg8 _res76;
  reg8 DDR1;
  reg8 _res77;
  reg8 DDR2;
  reg8 _res78;
  reg8 IOSEL;
  reg8 _res79;
  reg8 EXLE;
};

static_assert((sizeof (struct smpc_reg)) == 0x80);
static_assert((sizeof (((struct smpc_reg){}).IREG)) == 14);
static_assert((sizeof (((struct smpc_reg){}).OREG)) == 64);
static_assert((offsetof (struct smpc_reg, IREG[0].val)) == 0x1);
static_assert((offsetof (struct smpc_reg, IREG[1].val)) == 0x3);
static_assert((offsetof (struct smpc_reg, IREG[6].val)) == 0xd);
static_assert((offsetof (struct smpc_reg, OREG[0].val)) == 0x21);
static_assert((offsetof (struct smpc_reg, OREG[1].val)) == 0x23);
static_assert((offsetof (struct smpc_reg, OREG[31].val)) == 0x5f);
static_assert((offsetof (struct smpc_reg, COMREG)) == 0x1f);
static_assert((offsetof (struct smpc_reg, SR)) == 0x61);
static_assert((offsetof (struct smpc_reg, SF)) == 0x63);

struct smpc {
  struct smpc_reg reg;
};

extern struct smpc smpc __asm("smpc");

/* bits */

enum comreg_bit {
  COMREG__MSHON = 0x00,
  COMREG__SSHON = 0x02,
  COMREG__SSHOFF = 0x03,
  COMREG__SNDON = 0x06,
  COMREG__SNDOFF = 0x07,
  COMREG__CDON = 0x08,
  COMREG__CDOFF = 0x09,
  COMREG__SYSRES = 0x0D,
  COMREG__CKCHG352 = 0x0E,
  COMREG__CKCHG320 = 0x0F,
  COMREG__INTBACK = 0x10,
  COMREG__SETTIME = 0x16,
  COMREG__SETSMEM = 0x17,
  COMREG__NMIREQ = 0x18,
  COMREG__RESENAB = 0x19,
  COMREG__RESDISA = 0x1A,
};

enum oreg_bit {
  OREG31__MSHON    = 0b0000'0000,
  OREG31__SSHON    = 0b0000'0010,
  OREG31__SSHOFF   = 0b0000'0011,
  OREG31__SNDON    = 0b0000'0110,
  OREG31__SNDOFF   = 0b0000'0111,
  OREG31__CDON     = 0b0000'1000,
  OREG31__CDOFF    = 0b0000'1001,
  OREG31__SYSRES   = 0b0000'1101,
  OREG31__CKCHG352 = 0b0000'1110,
  OREG31__CKCHG320 = 0b0000'1111,
  OREG31__NMIREQ   = 0b0001'1000,
  OREG31__RESENAB  = 0b0001'1001,
  OREG31__RESDISA  = 0b0001'1010,
};

enum intback_ireg_bit {
  INTBACK__IREG0__CONTINUE = (1 << 7),
  INTBACK__IREG0__BREAK = (1 << 6),
  INTBACK__IREG0__STATUS_DISABLE = (0x00),
  INTBACK__IREG0__STATUS_ENABLE = (0x01),


  INTBACK__IREG1__PORT2_15BYTE = (0b00 << 6),
  INTBACK__IREG1__PORT2_256BYTE = (0b01 << 6),
  INTBACK__IREG1__PORT2_0BYTE = (0b11 << 6),
  INTBACK__IREG1__PORT1_15BYTE = (0b00 << 4),
  INTBACK__IREG1__PORT1_256BYTE = (0b01 << 4),
  INTBACK__IREG1__PORT1_0BYTE = (0b11 << 4),
  INTBACK__IREG1__PERIPHERAL_DATA_ENABLE = (1 << 3),
  INTBACK__IREG1__NOT_OPTIMIZED = (1 << 1),

  INTBACK__IREG2__MAGIC = (0xF0),
};

enum sr_bit {
  SR__PDL = (1 << 6),
  SR__NPE = (1 << 5),
  SR__RESB = (1 << 4),
  SR__P2MD1 = (1 << 3),
  SR__P2MD0 = (1 << 2),
  SR__P1MD1 = (1 << 1),
  SR__P1MD0 = (1 << 0),
#define SR__P2MD__15BYTE(sr) (((sr & 0b00001100)) == (0b00 << 2))
#define SR__P2MD__255BYTE(sr) (((sr & 0b00001100)) == (0b01 << 2))
#define SR__P2MD__0BYTE(sr) (((sr & 0b00001100)) == (0b11 << 2))

#define SR__P1MD__15BYTE(sr) (((sr & 0b00000011)) == (0b00 << 0))
#define SR__P1MD__255BYTE(sr) (((sr & 0b00000011)) == (0b01 << 0))
#define SR__P1MD__0BYTE(sr) (((sr & 0b00000011)) == (0b11 << 0))
};

//enum port_status {
#define PORT_STATUS__CONNECTORS(oreg) ((oreg >> 0) & 0b1111)
#define PORT_STATUS__MULTITAP_ID(oreg) ((oreg >> 4) & 0b1111)
//}

//enum peripheral_id {
#define PERIPHERAL_ID__DATA_SIZE(oreg) ((oreg >> 0) & 0b1111)
#define PERIPHERAL_ID__TYPE(oreg) ((oreg >> 4) & 0b1111)
//}


enum digital_bit {
  DIGITAL__1__RIGHT = (1 << 7),
  DIGITAL__1__LEFT = (1 << 6),
  DIGITAL__1__DOWN = (1 << 5),
  DIGITAL__1__UP = (1 << 4),
  DIGITAL__1__START = (1 << 3),
  DIGITAL__1__A = (1 << 2),
  DIGITAL__1__C = (1 << 1),
  DIGITAL__1__B = (1 << 0),

  DIGITAL__2__R = (1 << 7),
  DIGITAL__2__X = (1 << 6),
  DIGITAL__2__Y = (1 << 5),
  DIGITAL__2__Z = (1 << 4),
  DIGITAL__2__L = (1 << 3),
};

//enum keyboard_bit {
#define KEYBOARD__MAKE(oreg) (((oreg) & (0b1000)) != 0)
#define KEYBOARD__BREAK(oreg) (((oreg) & (0b0001)) != 0)
//};
