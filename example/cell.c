  //
  // vdp2: define and place a single character on NBG0
  //

  vdp2.reg.BGON = BGON__N0ON;

  vdp2.reg.CHCTLA = ( CHCTLA__N0CHCN__16_COLOR     // 4 bits per pixel, palettized
                    | CHCTLA__N0BMEN__CELL_FORMAT
                    | CHCTLA__N0CHSZ__1x1_CELL
                    );

  vdp2.reg.PNCN0 = PNCN0__N0PNB__2WORD;

  vdp2.reg.PLSZ = PLSZ__N0PLSZ__1x1;

  vdp2.vram.u16[16 +  0] = (1 << 12); // top left pixel of character # 1
  vdp2.vram.u16[16 + 15] = (2 << 0 ); // bottom right pixel of character # 1

  vdp2.cram.u16[1] = (0x31 << 5);  // green
  vdp2.cram.u16[2] = (0x31 << 10); // blue

  // given:
  //   Plane Size: 1h X 1v
  //   Pattern Name Data Size: 2 Words
  // only bits 5~0 are used for map address calculation
  // so MPOFN is effectively ignored
  vdp2.reg.MPOFN = MPOFN__N0MP(0); // bits 8~6
  vdp2.reg.MPABN0 = MPABN0__N0MPB(0) | MPABN0__N0MPA(1); // bits 5~0
  vdp2.reg.MPCDN0 = MPABN0__N0MPB(0) | MPABN0__N0MPA(1); // bits 5~0

  // zeroize NBG0 plane; this should be less than 0x8000 above
  s32 plane_size = 64 * 64 * 4; // is this correct ?
  fill_32(&vdp2.vram.u32[(0x4000 / 4)], 0, plane_size);

  // Table 4.8  Address value of map designated register by setting
  // (bit 5~0) * 0x4000
  vdp2.vram.u32[(0x4000 / 4)] = PATTERN_NAME_TABLE_2WORD__CHARACTER(1);
