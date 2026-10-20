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

S_FILES    := $(shell find asm -name '*.s' -not -path 'asm/nonmatchings/*' -not -path 'asm/matchings/*' -not -path 'asm/ovl/*' 2>/dev/null)
C_FILES    := $(shell find src -name '*.c' -not -path 'src/ovl/*' 2>/dev/null)
O_FILES    := $(S_FILES:%.s=$(BUILD_DIR)/%.o) $(C_FILES:%.c=$(BUILD_DIR)/%.o)
OVLS       := $(notdir $(basename $(wildcard ovl/*.yaml)))
OVL_BINS   := $(OVLS:%=$(BUILD_DIR)/ovl/%.bin)

.PHONY: all check clean split split-ovl
all: check

$(BUILD_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(AS_FLAGS) -o $@ $<
	$(OBJCOPY) --set-section-alignment .text=4 --set-section-alignment .data=4 --set-section-alignment .rodata=4 $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CPP) $(CPP_FLAGS) $< | $(CC1) $(CC1_FLAGS) | $(MASPSX) | $(AS) $(AS_FLAGS) -o $@

# overlay C files: sections laid out as the split found them (text padding stays in the text)
$(BUILD_DIR)/src/ovl/%.o: src/ovl/%.c
	@mkdir -p $(dir $@)
	$(CPP) $(CPP_FLAGS) $< | $(CC1) $(CC1_FLAGS) | $(MASPSX) | $(AS) $(AS_FLAGS) -o $@
	$(OBJCOPY) --set-section-alignment .rodata=4 --set-section-alignment .data=4 $@

$(BUILD_DIR)/%.o: %.bin
	@mkdir -p $(dir $@)
	$(OBJCOPY) -I binary -O elf32-tradlittlemips -B mips $< $@

$(ELF): $(O_FILES) $(LD_SCRIPT)
	$(LD) -EL -nostdlib --no-check-sections -T $(LD_SCRIPT) -T undefined_syms_auto.txt -T undefined_funcs_auto.txt -Map $(BUILD_DIR)/$(BASENAME).map -o $@

$(EXE): $(ELF)
	$(OBJCOPY) -O binary $< $@

check: $(EXE) $(OVL_BINS)
	@sha1sum -c $(BASENAME).sha1
	@sha1sum -c ovl/overlays.sha1

# Overlays (ovl/<file>.yaml, KKIIDDZZ file numbers): each links on its own at its load address, with
# its calls into SCUS resolved by the split's undefined-symbol lists. iso/ovl/ comes from
# tools/extract_ovl.py, build/scus_syms.txt from tools/scus_syms.py.
define OVL_RULES
$(BUILD_DIR)/ovl/$(1).elf: $$(shell grep -o 'build/[^ ;]*[.]o' ovl/$(1).ld 2>/dev/null | sort -u) ovl/$(1).ld
	@mkdir -p $$(dir $$@)
	$$(LD) -EL -nostdlib --no-check-sections -T ovl/$(1).ld -T ovl/$(1).undef_syms.txt -T ovl/$(1).undef_funcs.txt -Map $$(BUILD_DIR)/ovl/$(1).map -o $$@
endef
$(foreach o,$(OVLS),$(eval $(call OVL_RULES,$(o))))

$(BUILD_DIR)/ovl/%.bin: $(BUILD_DIR)/ovl/%.elf
	$(OBJCOPY) -O binary $< $@

split-ovl:
	python3 tools/scus_syms.py
	python3 tools/ovl_syms.py
	for y in ovl/*.yaml; do o=$$(basename $$y .yaml); rm -rf asm/ovl/$$o; python3 -m splat split $$y; done

split:
	rm -rf asm $(LD_SCRIPT)
	python3 -m splat split $(BASENAME).yaml
	python3 tools/post_split.py
	python3 tools/add_jtbl_pads.py

clean:
	rm -rf $(BUILD_DIR)
