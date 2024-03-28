OUTPUT_FORMAT("elf32-sh", "elf32-sh", "elf32-sh")
OUTPUT_ARCH(sh)

MEMORY
{
  cs0        (arx ) : ORIGIN = 0x22000000, LENGTH = 32M
  work_ram_h (arwx) : ORIGIN = 0x26000000, LENGTH = 1M
}

__ip_bin_offset = 0x2000;

SECTIONS
{
  . = ORIGIN(work_ram_h) + __ip_bin_offset;

  .text.start ALIGN(4) : SUBALIGN(4)
  {
    KEEP(*(.text.id))
    KEEP(*(.text.sec))

    KEEP(*(.text.arej))
    KEEP(*(.text.area))
    KEEP(*(.text.areb))
    KEEP(*(.text.aree))
    KEEP(*(.text.arek))
    KEEP(*(.text.arel))
    KEEP(*(.text.aret))
    KEEP(*(.text.areu))

    KEEP(*(.text.init))
    KEEP(*(.text.start))
    KEEP(*(.text.startup.*))

    . = ALIGN (4096);
  } > work_ram_h AT> cs0

  .text ALIGN(4) : SUBALIGN(4)
  {
    *(.text.*)
    *(.text)
    . = ALIGN (4);
  } > work_ram_h AT> cs0

  .data ALIGN(4) : SUBALIGN(4)
  {
    *(.data)
    *(.data.*)
    . = ALIGN (4);
  } > work_ram_h AT> cs0

  .rodata ALIGN(4) : SUBALIGN(4)
  {
    *(.rodata)
    *(.rodata.*)
    . = ALIGN (4);
  } > work_ram_h AT> cs0

  .bss ALIGN(4) (NOLOAD) : SUBALIGN(4)
  {
    *(.bss)
    *(.bss.*)
    *(COMMON)
    . = ALIGN (4);
  } > work_ram_h

  . = ORIGIN(cs0) + (. - (ORIGIN(work_ram_h) + __ip_bin_offset));

  .ctors ALIGN(4) : SUBALIGN(4)
  {
    KEEP(*(.ctors))
    KEEP(*(.ctors.*))
    . = ALIGN (4);
  } > cs0

  .rom ALIGN(4) : SUBALIGN(4)
  {
    *(.rom)
    *(.rom.*)
  } > cs0

  INCLUDE "debug.lds"
}

_text_size = SIZEOF(.text.start);
_load_addr = 0x00000000; /* not used; there is no 1ST_READ.BIN */

INCLUDE "symbols.lds"
INCLUDE "addresses.lds"
