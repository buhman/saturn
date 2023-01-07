AFLAGS = -g -gdwarf-4 --isa=sh2 --big
CFLAGS += -ffunction-sections -fshort-enums -ffreestanding -nostdlib
CFLAGS += -Wall -Werror -Wno-error=unused-but-set-variable -g -gdwarf-4 -Og
CARCH = -m2 -mb

TARGET = sh2-none-elf-
CC = $(TARGET)gcc
AS = $(TARGET)as
LD = $(TARGET)ld
OBJCOPY = $(TARGET)objcopy
OBJDUMP = $(TARGET)objdump

all: main.iso

define COPYELF
	$(OBJCOPY) -I coff-sh -O elf32-sh -g \
		--rename-section .text=.text.$1 \
		$< $@
endef

sys_sec.o: dts/sys_sec.o
	$(call COPYELF,sec)

sys_are%.o: dts/sys_are%.o
	$(call COPYELF,are)

sys_init.o: dts/sys_init.o
	$(call COPYELF,init)

ID_OBJ += sys_id.o
ID_OBJ += sys_sec.o
ID_OBJ += sys_arej.o sys_aret.o sys_areu.o sys_aree.o
ID_OBJ += sys_init.o
ID_OBJ += dts/smpsys.o

%.o: %.s
	$(AS) $(AFLAGS) $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

ip.elf: $(ID_OBJ)
	$(LD) --print-memory-usage -T ip.lds $^ -o $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

MAIN_OBJ = main.o

main.elf: $(MAIN_OBJ)
	$(LD) --print-memory-usage -T sh2.lds $^ -o $@

main.iso: main.bin ip.bin
	mkisofs \
		-sysid "SEGA SEGASATURN" \
		-volid "SAMPLE_GAME_TITLE" \
		-volset "SAMPLE_GAME_TITLE" \
		-publisher "SEGA ENTERPRISES, LTD." \
		-preparer "SEGA ENTERPRISES, LTD." \
		-G ip.bin \
		-o $@ \
		main.bin

clean:
	rm -f *.iso *.o *.bin *.elf dts/smpsys.o

.SUFFIXES:
.INTERMEDIATE:
.SECONDARY:
.PHONY: all clean dump
