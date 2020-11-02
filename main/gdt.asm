[BITS 32]

section .data

global _gdt_init

; Descriptor format
; byte	1: Limit, bits 0-7
;			2: Limit, bits 8-15
;			3: Base, bits 0-7
;			4: Base, bits 8-15
;			5: Base, bits 16-23
;			6: Access
;			7: Flags - high nybble, Limit, bits 16-19 - low nybble
;			8: Base, bits 24-31
;			Access:
;			bit	8		Present bit (1 is present)
;					7-6	Privilege
;					5		Type of descriptor (1 - code/data, 0 - System segment)
;					4		Executable bit (1 for executable)
;					3		(data segment) Expansion direction (0 for upward)
;							(code segment) Conforming
;					2		(data segment) Writable
;							(code segment) Readable
;					1		Accessed bit
;			Flags:
;			bit	4		Granularity (1 for 4K granularity,
;							 0 for byte granularity)
;					3		Default size (1 for 32bit, 0 for 16bit)
;					2		?
;					1		?
;				
gdt_addr:
	dd gdt_start

	align 8
gdt_desc:
gdt_start:
	dw (gdt_end - gdt_start)
	dd gdt_start
	dw 0
	db 0xFF, 0xFF, 0, 0, 0, 0x92, 0xCF, 0 ; data segment
	db 0xFF, 0xFF, 0, 0, 0, 0x9A, 0xCF, 0 ; code segment
gdt_end:

_gdt_init:
	lgdt [gdt_desc]
	mov eax, 0x08
	mov ss, eax
	mov ds, eax
	mov es, eax
	mov fs, eax
	mov gs, eax

	jmp 0x10:_gdt_init_1

_gdt_init_1:
	nop

	mov eax, 0
	ret

