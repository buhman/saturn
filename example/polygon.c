  //
  // vdp1:
  //

  // The VBE setting must be set immediately after the V-blank IN interrupt.
  //
  // TVM settings must be performed from the second H-blank IN interrupt after
  // the V-blank IN interrupt to the H-blank IN interrupt immediately after the
  // V-blank OUT interrupt.
  vdp1.reg.TVMR = ( TVMR__TVM__NTSC_PAL
                  | TVMR__TVM__FRAMEBUFFER_NONROTATION
                  | TVMR__TVM__16BPP
                  );

  // make FCM and FCT settings immediately after V-blank OUT
  vdp1.reg.FBCR = 0;

  // "A command table must always be stored at address 00000H to 0001EH."
  // we can't trigger a plot yet because we have no (valid) table.
  //vdp1.reg.PTMR = PTMR__PTM__FRAME_CHANGE;

  vdp1.reg.EWDR = 0; // black

  // upper-left
  vdp1.reg.EWLR = PTMR__EWLR__16BPP_X1(0) | PTMR__EWLR__Y1(0);

  // lower-right
  vdp1.reg.EWRR = PTMR__EWRR__16BPP_X3(319) | PTMR__EWRR__Y3(239);

  vdp1.vram.cmd[0].CTRL = CTRL__JP__JUMP_NEXT | CTRL__COMM__USER_CLIP_COORDINATES;
  vdp1.vram.cmd[0].LINK = 0;
  vdp1.vram.cmd[0].XA = 0;
  vdp1.vram.cmd[0].YA = 0;
  vdp1.vram.cmd[0].XC = 319;
  vdp1.vram.cmd[0].YC = 239;

  vdp1.vram.cmd[1].CTRL = CTRL__JP__JUMP_NEXT | CTRL__COMM__SYSTEM_CLIP_COORDINATES;
  vdp1.vram.cmd[1].LINK = 0;
  vdp1.vram.cmd[1].XC = 319;
  vdp1.vram.cmd[1].YC = 239;

  vdp1.vram.cmd[2].CTRL = CTRL__JP__JUMP_NEXT | CTRL__COMM__LOCAL_COORDINATE;
  vdp1.vram.cmd[2].LINK = 0;
  vdp1.vram.cmd[2].XA = 0;
  vdp1.vram.cmd[2].YA = 0;

  vdp1.vram.cmd[3].CTRL = CTRL__JP__JUMP_NEXT | CTRL__COMM__POLYGON;
  vdp1.vram.cmd[3].LINK = 0;
  vdp1.vram.cmd[3].PMOD = CTRL__PMOD__ECD | CTRL__PMOD__SPD;
  vdp1.vram.cmd[3].COLR = 0x2; // palette color #2
  vdp1.vram.cmd[3].XA = 50;
  vdp1.vram.cmd[3].YA = 50;
  vdp1.vram.cmd[3].XB = 150;
  vdp1.vram.cmd[3].YB = 50;
  vdp1.vram.cmd[3].XC = 150;
  vdp1.vram.cmd[3].YC = 150;
  vdp1.vram.cmd[3].XD = 50;
  vdp1.vram.cmd[3].YD = 150;

  vdp1.vram.cmd[4].CTRL = CTRL__JP__JUMP_NEXT | CTRL__COMM__POLYGON;
  vdp1.vram.cmd[4].LINK = 0;
  vdp1.vram.cmd[4].PMOD = CTRL__PMOD__ECD | CTRL__PMOD__SPD;
  vdp1.vram.cmd[4].COLR = (1 << 15) | (0x31 << 10) | (0x31 << 0); // RGB15 magenta
  vdp1.vram.cmd[4].XA = 100;
  vdp1.vram.cmd[4].YA = 50;
  vdp1.vram.cmd[4].XB = 150;
  vdp1.vram.cmd[4].YB = 100;
  vdp1.vram.cmd[4].XC = 100;
  vdp1.vram.cmd[4].YC = 150;
  vdp1.vram.cmd[4].XD =  50;
  vdp1.vram.cmd[4].YD = 100;

  vdp1.vram.cmd[5].CTRL = CTRL__END;

  // priorities
	vdp2.reg.PRISA = 0x0101;
	vdp2.reg.PRISB = 0x0101;
	vdp2.reg.PRISC = 0x0101;
	vdp2.reg.PRISD = 0x0101;

  // start drawing
  vdp1.reg.PTMR = PTMR__PTM__FRAME_CHANGE;
