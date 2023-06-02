OUTPUT_FORMAT("elf32-sh", "elf32-sh", "elf32-sh")
OUTPUT_ARCH(sh)
MEMORY
{
  ipl_rom : ORIGIN = 0x00000000, LENGTH = 512K
  work_ram_l : ORIGIN = 0x00200000, LENGTH = 1M
  work_ram_h : ORIGIN = 0x06000000, LENGTH = 1M
}
SECTIONS
{
  . = 0x06010000;

  .text ALIGN(4) : SUBALIGN(4)
  {
    KEEP(*(.text.start))
    *(.text)
    *(.text.*)
  } > work_ram_h

  .data ALIGN(4) : SUBALIGN(4)
  {
    *(.data)
    *(.data.*)
  } > work_ram_h

  .rodata ALIGN(4) : SUBALIGN(4)
  {
    *(.rodata)
  } > work_ram_h

  .bss ALIGN(4) (NOLOAD) : SUBALIGN(4)
  {
    *(.bss)
  } > work_ram_h

  __bss_link_start = ADDR(.bss);
  __bss_link_end = ADDR(.bss) + SIZEOF(.bss);
}

smpc = 0x20100000;
cdb  = 0x25890000;
scsp = 0x25A00000;
vdp1 = 0x25C00000;
vdp2 = 0x25E00000;
scu  = 0x25FE0000;
sh2_vec = 0x06000000;
sh2  = 0xfffffe00;

work_ram_l = 0x20200000;
work_ram_h = 0x26000000;
