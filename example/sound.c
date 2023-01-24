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
