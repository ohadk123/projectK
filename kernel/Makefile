BUILD_DIR=../build/kernel
KERNEL=$(BUILD_DIR)/kernel

CC=i686-elf-gcc
CFLAGS=-ffreestanding -nostdlib -m32 -O -nostdinc -nolibc -Wall -fno-builtin

LD=i686-elf-ld
LDFLAGS=-m elf_i386 -nmagic -M

SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))

all: build $(KERNEL)

build:
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(KERNEL): $(OBJS)
	$(LD) $(LDFLAGS) -Tkernel.lds $< -o $(KERNEL) > ../System.map
