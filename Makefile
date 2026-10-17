SHELL      := /bin/bash
.SHELLFLAGS := -o pipefail -c
.DELETE_ON_ERROR:

COMPILER   ?= 2.8.1-psx
BASENAME   := scus_944.23
TARGET     := iso/SCUS_944.23
BUILD_DIR  := build
EXE        := $(BUILD_DIR)/SCUS_944.23
ELF        := $(BUILD_DIR)/$(BASENAME).elf
LD_SCRIPT  := $(BASENAME).ld

CROSS      := mips-linux-gnu-
AS         := $(CROSS)as
LD         := $(CROSS)ld
OBJCOPY    := $(CROSS)objcopy
CPP        := $(CROSS)cpp
CC1        := /opt/cc/$(COMPILER)/cc1
MASPSX     := python3 tools/maspsx/maspsx.py --aspsx-version=2.79 --expand-div --use-comm-section

OPT_FLAGS  ?= -O2 -G0
CC1_FLAGS  := -quiet -mcpu=3000 -mhard-float -fgnu-linker -mgas -gcoff -w $(OPT_FLAGS)
CPP_FLAGS  := -Iinclude -Isrc -undef -Wall -lang-c -fno-builtin -D__GNUC__=2 -Dmips -D__mips__ -D__mips -Dpsx -D__psx__ -D__psx -D_PSYQ -D__EXTENSIONS__ -D_MIPSEL -D_LANGUAGE_C -DLANGUAGE_C -DUSE_INCLUDE_ASM
AS_FLAGS   := -Iinclude -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0 -EL

S_FILES    := $(shell find asm -name '*.s' -not -path 'asm/nonmatchings/*' -not -path 'asm/matchings/*' 2>/dev/null)
C_FILES    := $(shell find src -name '*.c' 2>/dev/null)
O_FILES    := $(S_FILES:%.s=$(BUILD_DIR)/%.o) $(C_FILES:%.c=$(BUILD_DIR)/%.o)

.PHONY: all check clean split
all: check

$(BUILD_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(AS_FLAGS) -o $@ $<
	$(OBJCOPY) --set-section-alignment .text=4 --set-section-alignment .data=4 --set-section-alignment .rodata=4 $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CPP) $(CPP_FLAGS) $< | $(CC1) $(CC1_FLAGS) | $(MASPSX) | $(AS) $(AS_FLAGS) -o $@

$(ELF): $(O_FILES) $(LD_SCRIPT)
	$(LD) -EL -nostdlib --no-check-sections -T $(LD_SCRIPT) -T undefined_syms_auto.txt -T undefined_funcs_auto.txt -Map $(BUILD_DIR)/$(BASENAME).map -o $@

$(EXE): $(ELF)
	$(OBJCOPY) -O binary $< $@

check: $(EXE)
	@sha1sum -c $(BASENAME).sha1

split:
	rm -rf asm $(LD_SCRIPT)
	python3 -m splat split $(BASENAME).yaml
	python3 tools/post_split.py
	python3 tools/add_jtbl_pads.py

clean:
	rm -rf $(BUILD_DIR)
