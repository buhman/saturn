void v_blank_in_int(void) __attribute__ ((interrupt_handler));
void v_blank_in_int(void)
{
  scu.reg.IST &= ~(IST__V_BLANK_IN);

  // reset FRC to zero
  sh2.reg.FRC.H = 0;
  sh2.reg.FRC.L = 0;

  // enable output compare interrupt
  sh2.reg.TIER = TIER__OCIAE;
}

void oci_int(void) __attribute__ ((interrupt_handler));
void oci_int(void)
{
  // clear OCFA
  sh2.reg.FTCSR &= ~(FTCSR__OCFA);

  while (smpc.reg.SF != 0) {}

  smpc.reg.SF = 0;

  smpc.reg.IREG0 = INTBACK__IREG0__STATUS_DISABLE;
  smpc.reg.IREG1 = ( INTBACK__IREG1__PERIPHERAL_DATA_ENABLE
                   | INTBACK__IREG1__PORT2_0BYTE
                   | INTBACK__IREG1__PORT1_15BYTE
                   );
  smpc.reg.IREG2 = INTBACK__IREG2__MAGIC;

  smpc.reg.COMREG = COMREG__INTBACK;

  // disable output compare interrupt (to be re-enabled on the next v_blank_in)
  sh2.reg.TIER = 0;
}

void smpc_int(void) __attribute__ ((interrupt_handler));
void smpc_int(void)
{
  scu.reg.IST &= ~(IST__SMPC);

  if (smpc.reg.SR & SR__PDL) {
    // to get all controller data, one should check SR__NPE and send CONTINUE
    // requests as needed

    // assuming SR__PDL is set and SR__P1MD is not 0-byte-mode:
    //   smpc.reg.OREG0 (port 1 status)
    //   smpc.reg.OREG1 (peripheral 1 data[0] {type,size})
    //   smpc.reg.OREG2 (peripheral 1 data[1])

    if ((smpc.reg.OREG2 & DIGITAL__1__C) == 0) {
      // if C is pressed, swap the color palette
      vdp2.cram.u16[1] = (0x31 << 10); // blue
      vdp2.cram.u16[2] = (0x31 << 5);  // green
    } else {
      // if C is not pressed, restore the original palette
      vdp2.cram.u16[1] = (0x31 << 5);  // green
      vdp2.cram.u16[2] = (0x31 << 10); // blue
    }
  }

  smpc.reg.IREG0 = INTBACK__IREG0__BREAK;
}


//
  // scu1:
  //

  // If timer0 is counting at roughly 15.73426 kHz (1/63.5556 µs), we can count
  // to 300µs at roughly T0C = 5 (~317.778 µs). H-Blank-IN subtracts about
  // 10.9µs which is still (~306 µs) more than 300µs.

  vec[SCU_VEC__SMPC] = (u32)(&smpc_int);
  vec[SCU_VEC__V_BLANK_IN] = (u32)(&v_blank_in_int);
  //scu.reg.T0C = 5;
  //scu.reg.T1MD = T1MD__TENB;

  // From the SMPC manual:
  //   The SMPC uses the V-BLANK-IN interrupt to execute internal tasks. At this
  //   time, issuing commands for 300 µs from V-BLANK-IN is prohibited.

  // CLKCHG320 (power-on default) NTSC, the FRC's internal clock is 26.8741 MHz.
  // The possible periods are then:
  //
  //  - 0.29768 µs (/8)
  //  - 1.19074 µs (/32)
  //  - 4.76295 µs (/128)
  //
  // (1/(26.8741 MHz)) * 128 * 63 = 300.066 µs

  // FRC, OCRA, OCRB, and FCIR are 16-bit registers, but the FRT bus is an 8-bit
  // bus.

  // TCR set CKS to /128
  // TOCR set OCRS to OCRA
  // TIER set OCIAE
  // FTCSR set CCLRA (clear FRC on compare match A)
  // VCRC set FOCV
  // OCRA set 63
  // FRC set 0

  vec[0x60] = (u32)&oci_int;
  sh2.reg.VCRC = VCRC__FOCV(0x60);

  sh2.reg.TCR = TCR__CKS__INTERNAL_DIV128;
  sh2.reg.TOCR = TOCR__OCRS__OCRA;
  sh2.reg.FTCSR = FTCSR__CCLRA;
  sh2.reg.OCRAB.H = 0;   // Even though Kronos doesn't emulate this, SH7095 says
                         // we are required to write the upper bit prior to
                         // writing the lower byte
  sh2.reg.OCRAB.L = 63;

  // reset/enable interrupts
  scu.reg.IST = 0;
  scu.reg.IMS = ~(IMS__SMPC | IMS__V_BLANK_IN);
