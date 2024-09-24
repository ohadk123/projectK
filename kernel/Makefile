BUILD_DIR=../build/kernel

SRCS := $(wildcard *.asm)
OBJS := $(patsubst %.asm, $(BUILD_DIR)/%.o, $(SRCS))

all: build $(OBJS)

build:
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.asm
	nasm -f bin $< -o $@
