AARCH = --isa=sh2 --big
AFLAGS = -g -gdwarf-4
CFLAGS += -ffunction-sections -fshort-enums -ffreestanding -nostdlib
CFLAGS += -Wall -Werror -Wfatal-errors -g -gdwarf-4 -Og
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
SYS_IP_OBJ += sys_area.o sys_areb.o sys_aree.o sys_arej.o
SYS_IP_OBJ += sys_arek.o sys_arel.o sys_aret.o sys_areu.o
SYS_IP_OBJ += sys_init.o
SYS_IP_OBJ += smpsys.o

%.o: %.s
	$(AS) $(AFLAGS) $(AARCH) $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) $(CARCH) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CARCH) -c $< -o $@

%.elf:
	$(LD) --print-memory-usage -T sys_ip.lds $^ -o $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

%.bin.o: %.bin
	$(OBJCOPY) \
		-I binary -O elf32-sh -B sh \
		--rename-section .data=.rodata,alloc,load,readonly,data,contents \
		$< $@

sys_ip.elf: $(SYS_IP_OBJ)

MAIN_OBJ = main.o
#m68k/main.bin.o

main.elf: $(MAIN_OBJ)
	$(LD) --print-memory-usage -T sh2.lds $^ -o $@

# mkisofs sorts file names alphabetically, it does not place the files in the
# generated directory descriptors the order given on the command-line.
#
# The "1st read file" must be physically placed at index [2] (after the "self"
# and "parent" entries) of the root directory, and so must be alphabetically
# lowest in the list of files.
#
# Additionally, the sega bios appears to reject disks that have a single
# file. This is presumably incomplete enforcement of the "required" smp_cpy.txt,
# smp_abs.txt, and smp_bib.txt files. A disk with a single file is presumed
# invalid (but >=2 files appears to be ok). The content of these files does not
# appear to be checked.
#
# Rather than insert a dummy file to "trick" the bios, I decided to include
# these files as specified in the manual (perhaps there are some bios versions
# that do check this).
#
# `-graft-points` is used to enable the "path grafting" pathspec syntax.
main.iso: main.bin sys_ip.bin
	mkisofs \
		-sysid "SEGA SEGASATURN" \
		-volid "SAMPLE_GAME_TITLE" \
		-volset "SAMPLE_GAME_TITLE" \
		-publisher "SEGA ENTERPRISES, LTD." \
		-preparer "SEGA ENTERPRISES, LTD." \
		-copyright "smp_cpy.txt" \
		-abstract "smp_abs.txt" \
		-biblio "smp_bib.txt" \
		-sectype data \
		-G sys_ip.bin \
		-o $@ \
		-graft-points \
		/0main.bin=./main.bin \
		/=./segasmp/smp_cpy.txt \
		/=./segasmp/smp_abs.txt \
		/=./segasmp/smp_bib.txt

clean:
	rm -f *.iso *.o *.bin *.elf

.SUFFIXES:
.INTERMEDIATE:
.SECONDARY:
.PHONY: all clean
