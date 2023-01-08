AFLAGS = -g -gdwarf-4 --isa=sh2 --big
CFLAGS += -ffunction-sections -fshort-enums -ffreestanding -nostdlib
CFLAGS += -Wall -Werror -g -gdwarf-4 -Og
CARCH = -m2 -mb

TARGET = sh2-none-elf-
CC = $(TARGET)gcc
AS = $(TARGET)as
LD = $(TARGET)ld
OBJCOPY = $(TARGET)objcopy
OBJDUMP = $(TARGET)objdump

all: main.iso

sys_%.o: segasmp/lib/sys_%.o
	$(OBJCOPY) -I coff-sh -O elf32-sh -g \
		--rename-section .text=.text.$* \
		$< $@

SYS_IP_OBJ += sys_id.o
SYS_IP_OBJ += sys_sec.o
SYS_IP_OBJ += sys_arej.o sys_aret.o sys_areu.o sys_aree.o
SYS_IP_OBJ += sys_init.o
SYS_IP_OBJ += smpsys.o

%.o: %.s
	$(AS) $(AFLAGS) $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

sys_ip.elf: $(SYS_IP_OBJ)
	$(LD) --print-memory-usage -T sys_ip.lds $^ -o $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

MAIN_OBJ = main.o

main.elf: $(MAIN_OBJ)
	$(LD) --print-memory-usage -T sh2.lds $^ -o $@

main.iso: main.bin sys_ip.bin
	mkisofs \
		-sysid "SEGA SEGASATURN" \
		-volid "SAMPLE_GAME_TITLE" \
		-volset "SAMPLE_GAME_TITLE" \
		-publisher "SEGA ENTERPRISES, LTD." \
		-preparer "SEGA ENTERPRISES, LTD." \
		-G sys_ip.bin \
		-o $@ \
		main.bin \
		main.bin

clean:
	rm -f *.iso *.o *.bin *.elf

.SUFFIXES:
.INTERMEDIATE:
.SECONDARY:
.PHONY: all clean dump
