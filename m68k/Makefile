ARCH = -march=68000 -mcpu=68ec000
AARCH = $(ARCH)
AFLAGS = -g -gdwarf-4

CFLAGS += -ffunction-sections -fshort-enums -ffreestanding -nostdlib
CFLAGS += -Wall -Werror -Wfatal-errors -g -gdwarf-4 -Og
CARCH = $(ARCH)

TARGET = m68k-none-elf-
CC = $(TARGET)gcc
AS = $(TARGET)as
LD = $(TARGET)ld
OBJCOPY = $(TARGET)objcopy
OBJDUMP = $(TARGET)objdump

all: main.bin

%.o: %.s
	$(AS) $(AARCH) $(AFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.elf:
	$(LD) --print-memory-usage -T m68k.lds $^ -o $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

MAIN_OBJ = vectors.o main.o

main.elf: $(MAIN_OBJ)

clean:
	rm -f *.iso *.o *.bin *.elf

.SUFFIXES:
.INTERMEDIATE:
.SECONDARY:
.PHONY: all clean
