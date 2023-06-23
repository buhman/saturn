LIB ?= .
OPT ?= -Og

AARCH = --isa=sh2 --big
AFLAGS = -g -gdwarf-4

CARCH = -m2 -mb
CFLAGS += -falign-functions=4 -ffunction-sections -fdata-sections -fshort-enums -ffreestanding -nostdlib
CFLAGS += -Wall -Werror -Wfatal-errors -Wno-error=unused-variable -g -gdwarf-4 $(OPT)
LDFLAGS = --gc-sections --no-warn-rwx-segment --print-memory-usage --entry=_start
CXXFLAGS = -std=c++17 -fno-exceptions -fno-non-call-exceptions -fno-rtti -fno-threadsafe-statics

TARGET = sh2-none-elf-
CC = $(TARGET)gcc
CXX = $(TARGET)g++
AS = $(TARGET)as
LD = $(TARGET)ld
OBJCOPY = $(TARGET)objcopy
OBJDUMP = $(TARGET)objdump

define BUILD_BINARY_O
	$(OBJCOPY) \
		-I binary -O elf32-sh -B sh2 \
		--rename-section .data=.data.$(basename $@) \
		$< $@
endef

$(LIB)/sys_%.o: $(LIB)/segasmp/lib/sys_%.o
	$(OBJCOPY) -I coff-sh -O elf32-sh -g \
		--rename-section .text=.text.$* \
		$< $@

SYS_IP_OBJ += $(LIB)/sys_id.o
SYS_IP_OBJ += $(LIB)/sys_sec.o
SYS_IP_OBJ += $(LIB)/sys_area.o $(LIB)/sys_areb.o $(LIB)/sys_aree.o $(LIB)/sys_arej.o
SYS_IP_OBJ += $(LIB)/sys_arek.o $(LIB)/sys_arel.o $(LIB)/sys_aret.o $(LIB)/sys_areu.o
SYS_IP_OBJ += $(LIB)/sys_init.o
SYS_IP_OBJ += $(LIB)/smpsys.o

%.o: %.s
	$(AS) $(AFLAGS) $(AARCH) $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) $(CARCH) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CARCH) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(CARCH) -c $< -o $@

%.elf:
	$(LD) $(LDFLAGS) -T $(LIB)/sh2.lds $^ -o $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

%.bin.o: %.bin
	$(OBJCOPY) \
		-I binary -O elf32-sh -B sh \
		--rename-section .data=.rodata,alloc,load,readonly,data,contents \
		$< $@

sys_ip.elf: $(SYS_IP_OBJ)
	$(LD) --print-memory-usage -T $(LIB)/sys_ip.lds $^ -o $@

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
%.iso: %.bin sys_ip.bin
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
		/0$(notdir ${<})=./${<} \
		/=$(LIB)/segasmp/smp_cpy.txt \
		/=$(LIB)/segasmp/smp_abs.txt \
		/=$(LIB)/segasmp/smp_bib.txt

%.cue: %.iso
	@echo "FILE \"$(notdir ${<})\" BINARY" > $@
	@echo "  TRACK 01 MODE1/2048" >> $@
	@echo "    INDEX 01 00:00:00" >> $@

clean:
	rm -f *.iso *.o *.bin *.elf *.cue

.SUFFIXES:
.INTERMEDIATE:
.SECONDARY:
.PHONY: all clean
