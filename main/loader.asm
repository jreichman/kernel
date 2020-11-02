[BITS 32]

%define HEADER_MAGIC	0x1BADB002
%define LOADER_MAGIC	0x2BADB002
%define FLAGS			0x00000007
%define STACKLEN		0x00004000
%define EFLAGSMASK	0xFFC0802A

global _start

extern kmain
extern halt

extern _gdt_init
extern _idt_init

section .text
begin:
	jmp _start

align 4
multiboot:
	dd HEADER_MAGIC				; magic
	dd FLAGS							; flags
	dd -(HEADER_MAGIC + FLAGS)	; checksum

_start:
	mov esp, stack + STACKLEN

	cmp eax, LOADER_MAGIC
	je _start_1
	jmp fail

_start_1:

	pushfd
	pop eax
	and eax, EFLAGSMASK
	push eax
	popfd

	call _gdt_init

	call _idt_init

	push ebx
	call kmain
	add esp, 4

fail:
	call halt
	jmp fail

section .data
stack:
	times STACKLEN db 0
