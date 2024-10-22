BUILD_DIR=../build/boot

SRCS := $(wildcard *.asm)
OBJS := $(patsubst %.asm, $(BUILD_DIR)/%.o, $(SRCS))

all: build $(OBJS)

build:
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.asm
	nasm -f elf $< -F dwarf -g -o $@
	ld -m elf_i386 -T bootloader.lds $@ -o $@.elf
	objcopy -O binary  $(BUILD_DIR)/bootloader.o.elf $@
