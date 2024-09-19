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
    *(.rodata.*)
  } > work_ram_h

  .ctors ALIGN(4) : SUBALIGN(4)
  {
    KEEP(*(.ctors))
    KEEP(*(.ctors.*))
  } > work_ram_h

  .bss ALIGN(4) (NOLOAD) : SUBALIGN(4)
  {
    *(.bss)
    *(.bss.*)
  } > work_ram_h

  .bss.work_ram_l ALIGN(4) (NOLOAD) : SUBALIGN(4)
  {
    *(.bss.work_ram_l)
  } > work_ram_l

  INCLUDE "saturn/debug.lds"
}

INCLUDE "saturn/symbols.lds"
INCLUDE "saturn/addresses.lds"
