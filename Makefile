AFLAGS = -g

TARGET = sh2be-none-elf-
CC = $(TARGET)gcc
AS = $(TARGET)as
LD = $(TARGET)ld
OBJCOPY = $(TARGET)objcopy
OBJDUMP = $(TARGET)objdump

all: main.iso

sys_are%.o: dts/sys_are%.o
	$(OBJCOPY) -O elf32-sh \
		--rename-section .text=.text.are \
		$< $@

sys_init.o: dts/sys_init.o
	$(OBJCOPY) -O elf32-sh \
		--rename-section .text=.text.init \
		$< $@

sys_sec.o: dts/sys_sec.o
	$(OBJCOPY) -O elf32-sh \
		--rename-section .text=.text.sec \
		$< $@

smpsys.o: dts/smpsys.o
	$(OBJCOPY) -O elf32-sh \
		--rename-section .text=.text.smp \
		$< $@

ID_OBJ += sys_id.o
ID_OBJ += sys_sec.o
ID_OBJ += sys_arej.o sys_aret.o sys_areu.o sys_aree.o
ID_OBJ += sys_init.o
ID_OBJ += smpsys.o

%.o: %.s
	$(AS) $(AFLAGS) $< -o $@

%.o: %.S
	$(CC) $(AFLAGS) -c $< -o $@

ip.elf: $(ID_OBJ)
	$(LD) --print-memory-usage -T ip.lds $^ -o $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

MAIN_OBJ = main.o

main.elf: $(MAIN_OBJ)
	$(LD) --print-memory-usage -T main.lds $^ -o $@

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
	rm -f *.iso *.o *.bin *.elf

.SUFFIXES:
.INTERMEDIATE:
.SECONDARY:
.PHONY: all clean dump
