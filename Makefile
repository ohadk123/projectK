BUILD_DIR=build
BOOTLOADER=$(BUILD_DIR)/boot/bootloader.o
KERNEL=$(BUILD_DIR)/kernel/kernel
DISK_IMG=disk.img

all: build bootdisk

.PHONY: bootdisk kernel bootloader

build:
	mkdir -p $(BUILD_DIR)

bootloader:
	make -C boot

kernel:
	make -C kernel

bootdisk: kernel bootloader
	dd if=/dev/zero of=$(DISK_IMG) bs=512 count=2880
	dd conv=notrunc if=$(BOOTLOADER) of=$(DISK_IMG) bs=512 count=1 seek=0
	# dd conv=notrunc if=$(KERNEL) of=$(DISK_IMG) bs=512 count=1 seek=1
	dd conv=notrunc if=$(KERNEL) of=$(DISK_IMG) bs=512 count=$$(($(shell stat --printf="%s" $(KERNEL))/512+1)) seek=1
	

gdb:
	qemu-system-i386 -machine q35 -fda $(DISK_IMG) -gdb tcp::26000 -S &
	gdb
run:
	qemu-system-i386 -machine q35 -fda $(DISK_IMG)

clean:
	rm -frd build $(DISK_IMG) System.map
