LIB ?= .
OPT ?= -Og

ARCH = -march=68000 -mcpu=68000

AARCH = $(ARCH)
AFLAGS = -g -gdwarf-4 --fatal-warnings

CARCH = $(ARCH) -mtune=68000
CFLAGS += -falign-functions=4 -ffunction-sections -fdata-sections -fshort-enums -ffreestanding -nostdlib
CFLAGS += -Wall -Werror -Wfatal-errors -Wno-error=unused-variable -g -gdwarf-4 $(OPT)
LDFLAGS = --gc-sections --print-gc-sections --no-warn-rwx-segment --print-memory-usage --entry=start --orphan-handling=error
CXXFLAGS = -std=c++20 -fno-exceptions -fno-non-call-exceptions -fno-rtti -fno-threadsafe-statics

TARGET = m68k-none-elf-
CC = $(TARGET)gcc
CXX = $(TARGET)g++
AS = $(TARGET)as
LD = $(TARGET)ld
OBJCOPY = $(TARGET)objcopy
OBJDUMP = $(TARGET)objdump

define BUILD_BINARY_O
	$(OBJCOPY) \
		-I binary -O elf32-m68k -B m68k \
		--rename-section .data=.data.$(basename $@) \
		$< $@
endef

as_obj_binary = _binary_$(subst /,_,$(subst .,_,$(basename $(1))))

define BUILD_BINARY_H
	@echo $@
	@echo '#pragma once' > $@
	@echo '#include <stdint.h>' >> $@
	@echo 'extern uint32_t $(call as_obj_binary,$@)_start __asm("$(call as_obj_binary,$@)_start");' >> $@
	@echo 'extern uint32_t $(call as_obj_binary,$@)_end __asm("$(call as_obj_binary,$@)_end");' >> $@
	@echo 'extern uint32_t $(call as_obj_binary,$@)_size __asm("$(call as_obj_binary,$@)_size");' >> $@
endef

all: main.bin

%.o: %.s
	$(AS) $(AARCH) $(AFLAGS) $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) $(CARCH) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CARCH) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(CARCH) -c $< -o $@

%.elf: $(LIB)/m68k/vectors.o $(LIB)/m68k/start.o $(LIB)/m68k/handlers.o
	$(LD) $(LDFLAGS) -T $(LIB)/m68k/m68k.lds $^ -o $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

#OBJ = vectors.o main.o

clean:
	rm -f *.iso *.o *.bin *.elf *.cue

.SUFFIXES:
.INTERMEDIATE:
.SECONDARY:
.PHONY: all clean
