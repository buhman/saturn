OUTPUT_FORMAT("elf32-sh", "elf32-sh", "elf32-sh")
OUTPUT_ARCH(sh)

MEMORY
{
  rom (arx) : ORIGIN = 0x06002000, LENGTH = 4M
}

SECTIONS
{
  .text : ALIGN(4)
  {
    KEEP(*(.text.id))
    KEEP(*(.text.sec))
    KEEP(*(.text.are))
    KEEP(*(.text.init))
    KEEP(*(.text.smp))
  } > rom
}
