#define SMPC_BASE 0x00100000

#define COMREG 0x01F
#define SR 0x061
#define SF 0x063

#define IREG0 0x001
#define IREG1 0x003
#define IREG2 0x005
#define IREG3 0x007
#define IREG4 0x009
#define IREG5 0x00B
#define IREG6 0x00D

#define OREG0  0x021
#define OREG1  0x023
#define OREG2  0x025
#define OREG3  0x027
#define OREG4  0x029
#define OREG5  0x02B
#define OREG6  0x02D
#define OREG7  0x02F
#define OREG8  0x031
#define OREG9  0x033
#define OREG10 0x035
#define OREG11 0x037
#define OREG12 0x039
#define OREG13 0x03B
#define OREG14 0x03D
#define OREG15 0x03F
#define OREG16 0x041
#define OREG17 0x043
#define OREG18 0x045
#define OREG19 0x047
#define OREG20 0x049
#define OREG21 0x04B
#define OREG22 0x04D
#define OREG23 0x04F
#define OREG24 0x051
#define OREG25 0x053
#define OREG26 0x055
#define OREG27 0x057
#define OREG28 0x059
#define OREG29 0x05B
#define OREG30 0x05D
#define OREG31 0x05F

#define PDR1 0x075
#define DDR1 0x079
#define PDR2 0x077
#define DDR2 0x07B

#define IOSEL 0x07D
#define IOSEL__SMPC_1 (0 << 0)
#define IOSEL__SMPC_2 (0 << 1)
#define IOSEL__SH2_1 (1 << 0)
#define IOSEL__SH2_2 (1 << 1)

#define EXLE  0x07F
#define EXLE__1 (1 << 0)
#define EXLE__2 (1 << 1)

/* SMPC commands */

#define SMPC_INTBACK 0x10

#define SMPC_INTBACK__IREG0__STATUS_DISABLE (0x00)
#define SMPC_INTBACK__IREG0__STATUS_ENABLE (0x01)
#define SMPC_INTBACK__IREG0__BREAK (1 << 6)
#define SMPC_INTBACK__IREG0__CONTINUE (1 << 7)

#define SMPC_INTBACK__IREG1__NOT_OPTIMIZED (1 << 1)
#define SMPC_INTBACK__IREG1__PERIPHERAL_DATA_ENABLE (1 << 3)
#define SMPC_INTBACK__IREG1__PORT2_15BYTE (0b00 << 6)
#define SMPC_INTBACK__IREG1__PORT2_256BYTE (0b01 << 6)
#define SMPC_INTBACK__IREG1__PORT2_0BYTE (0b11 << 6)
#define SMPC_INTBACK__IREG1__PORT1_15BYTE (0b00 << 4)
#define SMPC_INTBACK__IREG1__PORT1_256BYTE (0b01 << 4)
#define SMPC_INTBACK__IREG1__PORT1_0BYTE (0b11 << 4)


#define SMPC_INTBACK__IREG2__MAGIC (0xF0)
