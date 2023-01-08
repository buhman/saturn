OUTPUT_FORMAT("elf32-sh", "elf32-sh", "elf32-sh")
OUTPUT_ARCH(sh)

MEMORY
{
  ip (arx) : ORIGIN = 0x06002000, LENGTH = 4096
}

SECTIONS
{
  .text :
  {
    KEEP(*(.text.id))
    KEEP(*(.text.sec))

    /*
    SEGA SATURN TECHNICAL BULLETIN #SOA-12:

       Please make sure that the area symbols and area codes
       match in order.

       The final IP.BIN must be 4096 bytes.

       ABEJKLTU
    */
    KEEP(*(.text.arej))
    KEEP(*(.text.area))
    KEEP(*(.text.areb))
    KEEP(*(.text.aree))
    KEEP(*(.text.arek))
    KEEP(*(.text.arel))
    KEEP(*(.text.aret))
    KEEP(*(.text.areu))

    KEEP(*(.text.init))
    KEEP(*(.text.main))
    KEEP(*(.text.*))

    . = 4096;
  } > ip
}

_text_size = SIZEOF(.text);
_load_addr = 0x06010000;
