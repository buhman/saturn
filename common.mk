LIB ?= .
OPT ?= -Og
DEBUG ?= -g -gdwarf-4
GENERATED ?=

AARCH = --isa=sh2 --big
AFLAGS = --fatal-warnings

CARCH = -m2 -mb
CFLAGS += -falign-functions=4 -ffunction-sections -fdata-sections -fshort-enums -ffreestanding -nostdlib
CFLAGS += -Wall -Werror -Wfatal-errors -Wno-error=unused-variable
DEPFLAGS = -MMD -E
LDFLAGS = --gc-sections --print-gc-sections --no-warn-rwx-segment --print-memory-usage --entry=_start --orphan-handling=error
CXXFLAGS = -std=c++20 -fno-exceptions -fno-non-call-exceptions -fno-rtti -fno-threadsafe-statics

TARGET = sh2-none-elf-
CC = $(TARGET)gcc
CXX = $(TARGET)g++
AS = $(TARGET)as
LD = $(TARGET)ld
OBJCOPY = $(TARGET)objcopy
OBJDUMP = $(TARGET)objdump

LIBGCC = $(shell $(CC) -print-file-name=libgcc.a)

define BUILD_BINARY_O
	$(OBJCOPY) \
		-I binary -O elf32-sh -B sh2 \
		--rename-section .data=.data.$(basename $@) \
		$< $@
endef

as_obj_binary = _binary_$(subst .,_,$(subst /,_,$(basename $(1))))

define BUILD_BINARY_H
	@echo gen $@
	@echo '#pragma once' > $@
	@echo '#include <stdint.h>' >> $@
	@echo 'extern uint32_t $(call as_obj_binary,$@)_start __asm("$(call as_obj_binary,$@)_start");' >> $@
	@echo 'extern uint32_t $(call as_obj_binary,$@)_end __asm("$(call as_obj_binary,$@)_end");' >> $@
	@echo 'extern uint32_t $(call as_obj_binary,$@)_size __asm("$(call as_obj_binary,$@)_size");' >> $@
endef

%.o: %.s
	$(AS) $(AARCH) $(AFLAGS) $(DEBUG) $< -o $@

%.o: %.S
	$(CC) $(CARCH) $(CFLAGS) $(OPT) $(DEBUG) -c $< -o $@

%.c.d: | $(GENERATED)
	$(CC) $(CARCH) $(CFLAGS) $(OPT) $(DEBUG) $(DEPFLAGS) -c $(basename $@) -MF $@ -o /dev/null

%.o: %.c %.c.d
	$(CC) $(CARCH) $(CFLAGS) $(OPT) $(DEBUG) -c $< -o $@

%.cpp.d: | $(GENERATED)
	$(CXX) $(CARCH) $(CFLAGS) $(CXXFLAGS) $(OPT) $(DEBUG) $(DEPFLAGS) -c $(basename $@) -MF $@ -o /dev/null

%.o: %.cpp %.cpp.d
	$(CXX) $(CARCH) $(CFLAGS) $(CXXFLAGS) $(OPT) $(DEBUG) -c $< -o $@

%.elf: $(LIB)/start.o
	$(LD) $(LDFLAGS) -T $(LIB)/sh2.lds $^ -o $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

%.bin.o: %.bin
	$(OBJCOPY) \
		-I binary -O elf32-sh -B sh \
		--rename-section .data=.rodata,alloc,load,readonly,data,contents \
		$< $@

SYS_IP_OBJ += $(LIB)/ip/sys_id.o
SYS_IP_OBJ += $(LIB)/ip/segasmp/sys_sec.o
SYS_IP_OBJ += $(LIB)/ip/sys_area.o
SYS_IP_OBJ += $(LIB)/ip/sys_areb.o
SYS_IP_OBJ += $(LIB)/ip/sys_aree.o
SYS_IP_OBJ += $(LIB)/ip/sys_arej.o
SYS_IP_OBJ += $(LIB)/ip/sys_arek.o
SYS_IP_OBJ += $(LIB)/ip/sys_arel.o
SYS_IP_OBJ += $(LIB)/ip/sys_aret.o
SYS_IP_OBJ += $(LIB)/ip/sys_areu.o
SYS_IP_OBJ += $(LIB)/ip/sys_init.o
SYS_IP_OBJ += $(LIB)/ip/smpsys.o

$(LIB)/ip/segasmp/sys_%.o: $(LIB)/segasmp/lib/sys_%.o
	$(OBJCOPY) -I coff-sh -O elf32-sh -g \
		--rename-section .text=.text.$* \
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
	rm -f *.iso *.o *.d *.bin *.elf *.cue *.gch

.SUFFIXES:
.INTERMEDIATE:
.SECONDARY:
.PHONY: all clean

%: RCS/%,v
%: RCS/%
%: %,v
%: s.%
%: SCCS/s.%
