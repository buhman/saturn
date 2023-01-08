OUTPUT_FORMAT("elf32-sh", "elf32-sh", "elf32-sh")
OUTPUT_ARCH(sh)
MEMORY
{
  work_ram_l : ORIGIN = 0x00200000, LENGTH = 1M
  work_ram_h : ORIGIN = 0x06000000, LENGTH = 1M
}
SECTIONS
{
  . = 0x06010000;

  .text ALIGN(2) : SUBALIGN(2)
  {
    *(.text.start)
    *(.text*)
  } > work_ram_h

  .data ALIGN(4) : SUBALIGN(4)
  {
    *(.data)
  } > work_ram_h

  .rodata ALIGN(4) : SUBALIGN(4)
  {
    *(.rodata)
  } > work_ram_h

  .bss ALIGN(4) (NOLOAD) : SUBALIGN(4)
  {
    *(.bss)
  } > work_ram_h

}

smpc = 0x00100000;
scsp = 0x05A00000;
vdp1 = 0x05C00000;
vdp2 = 0x05E00000;
scu  = 0x05FE0000;
