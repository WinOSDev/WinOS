#include "framebuffer.h"
#include "serial.h"
#include "gdt.h"

int kernel_main()
{
	char output[] = "Hello! Angel\n";
	fb_print(output);

	serial_init(COM1_BASE_PORT);
	serial_write_byte(COM1_BASE_PORT, 'a');
	serial_write_byte(COM1_BASE_PORT, 'b');
	serial_write_byte(COM1_BASE_PORT, 'c');

	return 0xDEADBEEF;
}