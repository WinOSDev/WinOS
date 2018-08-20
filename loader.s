global loader

extern kernel_main

MAGIC			equ 0x1BADB002
FLAGS			equ 0x0
CHECKSUM		equ -MAGIC
KERNEL_STACK_SIZE	equ 4096

section .bss
align 4
kernel_stack:
	resb KERNEL_STACK_SIZE

; grows downward towards lower addresses
; Stack


; ------------ <----- end of space, ends at 102000 (1056768) // esp points here, grows downward
;
;
; kernel_stack <----- reserves space (4096), starts at 101000 (1052672)
; -------------
; End of bootloader ; 

; although values may seem like they refer to bit, each bit maps to a byte of actual memory size
; so +4 bit is actually +4 bytes
; each cell block is 32bits in that case

; registers only hold things, can be a value, or a memory address ( use [] to access value at address)
; EXAMPLE: mov eax, [esp]

section .text
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

loader:
	mov esp, kernel_stack + KERNEL_STACK_SIZE
	mov ebp, esp
	call kernel_main

.loop:
	jmp .loop

