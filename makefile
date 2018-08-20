# TIPS:

# Target: Dependency
# [TAB] System Commands

# all: is the default target executed if none other specified

# $< is the first dependency
# $^ is all dependency
# $@ is the output

CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
		 -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T link.ld -melf_i386
ASFLAGS = -f elf

OBJECTS = loader.o kmain.o framebuffer.o io.o serial.o gdt.o

all: iso

kernel: $(OBJECTS)
	ld $(LDFLAGS) *.o -o iso/boot/kernel.elf

iso: kernel
	genisoimage -R											\
				-b boot/grub/stage2_eltorito.binary			\
				-no-emul-boot								\
				-boot-load-size 4							\
				-A os										\
				-input-charset utf8							\
				-quiet										\
				-boot-info-table							\
				-o os.iso									\
				iso											

build: iso
	bochs -f bochsconfig.txt -q

run:
	bochs -f bochsconfig.txt -q

%.o: %.c
	gcc $(CFLAGS) $< -o $@

%.o: %.s
	nasm $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o kernel.elf os.iso
