BUILD_DIR=../build/kernel
KERNEL=$(BUILD_DIR)/kernel

CC=i686-elf-gcc
CFLAGS=-ffreestanding -nostdlib -m32 -nostdinc -nolibc -Wall -fno-builtin -I../include
ifeq ($(DEBUG), 1)
CFLAGS+=-gdwarf-4 -ggdb3
endif

LD=i686-elf-ld
LDFLAGS=-m elf_i386 -nmagic -M

C_SRCS := $(wildcard *.c)
C_OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(C_SRCS))

ASM_SRCS := $(wildcard *.asm)
ASM_OBJS := $(patsubst %.asm, $(BUILD_DIR)/%.o, $(ASM_SRCS))

all: build $(KERNEL)

build:
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.asm
	nasm -f elf32 $< -o $@

$(KERNEL): $(C_OBJS) $(ASM_OBJS)
	$(LD) $(LDFLAGS) -Tkernel.lds $(C_OBJS) $(ASM_OBJS) -o $(KERNEL) > ../System.map
