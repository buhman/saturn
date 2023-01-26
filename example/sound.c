//
// scsp
//

// The SCSP will initialize the internal registers, etc. for about 30µ sec
// after the reset has been released.  For this reason, access is not allowed
// during the 30µ sec.

// Before downloading anything, make sure to set MEM4MB bit to 1 and DAC18B
// bit to 0 within the sound CPU (address) 10400H address.

smpc.reg.COMREG = COMREG__SNDON;
while (smpc.reg.OREG31 != 0b00000110) {}
for (long i = 0; i < 807; i++) { asm volatile ("nop"); }   // wait for (way) more than 30µs

scsp.reg.common[0] = SCSP__0__MEM4MB | SCSP__0__DAC18B;

u16 * m68k_main_start = (u16 *)&_binary_m68k_main_bin_start;
u32 m68k_main_size = (u32)&_binary_m68k_main_bin_size;
copy_16(m68k_main_start, &scsp.ram.u16[0], m68k_main_size);

smpc.reg.COMREG = COMREG__SNDOFF;
while (smpc.reg.OREG31 != 0b00000111) {}
for (long i = 0; i < 807; i++) { asm volatile ("nop"); }   // wait for (way) more than 30µs

smpc.reg.COMREG = COMREG__SNDON;
while (smpc.reg.OREG31 != 0b00000110) {}
for (long i = 0; i < 807; i++) { asm volatile ("nop"); }   // wait for (way) more than 30µs

scsp.reg.common[0] = SCSP__0__MEM4MB | SCSP__0__DAC18B;

///

static signed int left_phase;

static void fill_data(int16_t * output, int len)
{
  for (int i = 0; i < len; i++) {
    *output++ = (signed short)left_phase;
    left_phase += 327 / 2;
    if (left_phase >= 32767) left_phase = -32768;
  }
}

#include "scsp.h"

void main_sound(void)
{
  while ((smpc.reg.SF & 0x01) == 1);

  smpc.reg.SF = 1;

  smpc.reg.COMREG = COMREG__SNDON;
  while ((smpc.reg.SF & 0x01) == 1);
  while (smpc.reg.OREG31 != 0b00000110) {}

  for (long i = 0; i < 807; i++) { asm volatile ("nop"); }   // wait for (way) more than 30µs

  scsp.reg.common[0] = SCSP__0__MEM4MB | SCSP__0__DAC18B | 15;

  left_phase = 0;
  fill_data((int16_t*)&scsp.ram.u16[0], 44100);

  scsp_slot& slot = scsp.reg.slot[0];

  while (1) {
    left_phase = 0;
    fill_data((int16_t*)&scsp.ram.u16[0], 44100);

    slot.field[0] = (1 << 11) | (1 << 5); // kx
    slot.field[1] = 0; // start_addr
    slot.field[2] = 0; // loop start address
    slot.field[3] = 44100; // loop end address
    slot.field[4] = 31; // d2r d1r ar
    //slot.field[5] = (1 << 14) | (0xf << 10) | 0; // krs dl rr (key_decay_release)
    slot.field[5] = 31; // krs dl rr (key_decay_release)
    slot.field[6] = 1 << 3; // tl (attenuation)
    slot.field[7] = 0; // mdl mdxsl mdysl (fm_data)
    slot.field[8] = 0; // oct fns (ofc_fns)
    slot.field[9] = 0; // lfof plfows (lfo_data)
    slot.field[10] = 0; // isel imxl (input_sel)
    slot.field[11] = (7 << 13); // disdl dipan efpan (pan_send)

    slot.field[0] |= (1 << 12);

    for (int32_t i = 0; i < 800000; i++) { asm volatile ("nop"); }

    slot.field[0] |= (1 << 12);
    slot.field[0] = 0;
  }
}
