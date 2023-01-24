OUTPUT_FORMAT("elf32-m68k", "elf32-m68k", "elf32-m68k")
OUTPUT_ARCH(m68k)
MEMORY
{
  sound_ram : ORIGIN = 0x000000, LENGTH = 512K
}
SECTIONS
{
  .text :
  {
    . = 0x000000;
    KEEP(*(.vectors))
    *(.text)
  } > sound_ram

  .data ALIGN(4) : SUBALIGN(4)
  {
    *(.data)
  } > sound_ram

  .rodata ALIGN(4) : SUBALIGN(4)
  {
    *(.rodata)
  } > sound_ram

  .bss ALIGN(4) (NOLOAD) : SUBALIGN(4)
  {
    *(.bss)
  } > sound_ram

  __bss_link_start = ADDR(.bss);
  __bss_link_end = ADDR(.bss) + SIZEOF(.bss);
}

scsp = 0x000000;
