#include "type.h"

struct ireg {
  reg8 _res0;
  reg8 IREG0;
  reg8 _res1;
  reg8 IREG1;
  reg8 _res2;
  reg8 IREG2;
  reg8 _res3;
  reg8 IREG3;
  reg8 _res4;
  reg8 IREG4;
  reg8 _res5;
  reg8 IREG5;
  reg8 _res6;
  reg8 IREG6;

  inline constexpr reg8 & operator[](uint32_t i)
  {
    switch (i) {
    default:
    case 0:  return IREG0;
    case 1:  return IREG1;
    case 2:  return IREG2;
    case 3:  return IREG3;
    case 4:  return IREG4;
    case 5:  return IREG5;
    case 6:  return IREG6;
    }
  };
};

static_assert((sizeof (struct ireg)) == 14);
static_assert((offsetof (struct ireg, IREG0)) == 0x1);
static_assert((offsetof (struct ireg, IREG1)) == 0x3);
static_assert((offsetof (struct ireg, IREG6)) == 0xd);


struct oreg {
  reg8 _res24;
  reg8 OREG0;
  reg8 _res25;
  reg8 OREG1;
  reg8 _res26;
  reg8 OREG2;
  reg8 _res27;
  reg8 OREG3;
  reg8 _res28;
  reg8 OREG4;
  reg8 _res29;
  reg8 OREG5;
  reg8 _res30;
  reg8 OREG6;
  reg8 _res31;
  reg8 OREG7;
  reg8 _res32;
  reg8 OREG8;
  reg8 _res33;
  reg8 OREG9;
  reg8 _res34;
  reg8 OREG10;
  reg8 _res35;
  reg8 OREG11;
  reg8 _res36;
  reg8 OREG12;
  reg8 _res37;
  reg8 OREG13;
  reg8 _res38;
  reg8 OREG14;
  reg8 _res39;
  reg8 OREG15;
  reg8 _res40;
  reg8 OREG16;
  reg8 _res41;
  reg8 OREG17;
  reg8 _res42;
  reg8 OREG18;
  reg8 _res43;
  reg8 OREG19;
  reg8 _res44;
  reg8 OREG20;
  reg8 _res45;
  reg8 OREG21;
  reg8 _res46;
  reg8 OREG22;
  reg8 _res47;
  reg8 OREG23;
  reg8 _res48;
  reg8 OREG24;
  reg8 _res49;
  reg8 OREG25;
  reg8 _res50;
  reg8 OREG26;
  reg8 _res51;
  reg8 OREG27;
  reg8 _res52;
  reg8 OREG28;
  reg8 _res53;
  reg8 OREG29;
  reg8 _res54;
  reg8 OREG30;
  reg8 _res55;
  reg8 OREG31;

  inline constexpr reg8 const& operator[](uint32_t i) const
  {
    switch (i) {
    default:
    case 0:  return OREG0;
    case 1:  return OREG1;
    case 2:  return OREG2;
    case 3:  return OREG3;
    case 4:  return OREG4;
    case 5:  return OREG5;
    case 6:  return OREG6;
    case 7:  return OREG7;
    case 8:  return OREG8;
    case 9:  return OREG9;
    case 10: return OREG10;
    case 11: return OREG11;
    case 12: return OREG12;
    case 13: return OREG13;
    case 14: return OREG14;
    case 15: return OREG15;
    case 16: return OREG16;
    case 17: return OREG17;
    case 18: return OREG18;
    case 19: return OREG19;
    case 20: return OREG20;
    case 21: return OREG21;
    case 22: return OREG22;
    case 23: return OREG23;
    case 24: return OREG24;
    case 25: return OREG25;
    case 26: return OREG26;
    case 27: return OREG27;
    case 28: return OREG28;
    case 29: return OREG29;
    case 30: return OREG30;
    case 31: return OREG31;
    }
  };
};

static_assert((sizeof (struct oreg)) == 64);
static_assert((offsetof (struct oreg, OREG0)) == 0x1);
static_assert((offsetof (struct oreg, OREG1)) == 0x3);

struct smpc_reg {
  struct ireg ireg;
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
  struct oreg oreg;
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

static_assert((sizeof (smpc_reg)) == 0x80);
static_assert((offsetof (struct smpc_reg, oreg.OREG0)) == 0x21);
static_assert((offsetof (struct smpc_reg, oreg.OREG1)) == 0x23);
static_assert((offsetof (struct smpc_reg, oreg.OREG31)) == 0x5f);
static_assert((offsetof (struct smpc_reg, SF)) == 0x63);

struct smpc {
  smpc_reg reg;
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
#define PERIPHERAL_ID__IS_DIGITAL_PAD(oreg) (((oreg >> 4) & 0b1111) == 0b0000)
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
