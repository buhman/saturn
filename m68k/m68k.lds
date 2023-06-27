OUTPUT_FORMAT("elf32-m68k", "elf32-m68k", "elf32-m68k")
OUTPUT_ARCH(m68k)
MEMORY
{
  sound_ram : ORIGIN = 0x000000, LENGTH = 512K
}
SECTIONS
{
  . = 0x00000000;

  .text ALIGN(4) : SUBALIGN(4)
  {
    KEEP(*(.vectors*))
    KEEP(*(.text.start))
    *(.text)
    *(.text.*)
  } > sound_ram

  .data ALIGN(4) : SUBALIGN(4)
  {
    *(.data)
    *(.data.*)
  } > sound_ram

  .rodata ALIGN(4) : SUBALIGN(4)
  {
    *(.rodata)
    *(.rodata.*)
  } > sound_ram

  .ctors ALIGN(4) : SUBALIGN(4)
  {
    KEEP(*(.ctors))
    KEEP(*(.ctors.*))
  } > sound_ram

  .bss ALIGN(4) (NOLOAD) : SUBALIGN(4)
  {
    *(.bss)
    *(.bss.*)
  } > sound_ram

  /DISCARD/ :
  {
    *(.debug*)
    *(.comment*)
    *(.rela*)
  }

  __bss_link_start = ADDR(.bss);
  __bss_link_end = ADDR(.bss) + SIZEOF(.bss);

  __ctors_link_start = ADDR(.ctors);
  __ctors_link_end = ADDR(.ctors) + SIZEOF(.ctors);
}

scsp = 0x000000;
