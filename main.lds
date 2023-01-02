OUTPUT_FORMAT("elf32-sh", "elf32-sh", "elf32-sh")
OUTPUT_ARCH(sh)

MEMORY
{
  /* origin after ip.bin */
  rom (arx) : ORIGIN = 0x06002200, LENGTH = 4M
}

SECTIONS
{
  .text : ALIGN(4)
  {
    *(.text)
  } > rom
}
