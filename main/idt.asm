[BITS 32]

section .data

global _idt_init
global interrupt_table
extern _upanic
extern printf
extern halt

; Gate descriptor format
; byte	1: Offset, bits 0-7
;			2: Offset, bits 8-15
;			3: Selector, bits 0-7
;			4: Selector, bits 8-15
;			5: Word count - low nybble
;			6: Access
;			7: Offset, bits 16-23
;			8: Offset, bits 24-31
;
idt_addr:
	dd idt_start

	align 8
idt_desc:
	dw (idt_end - idt_start)
	dd idt_start
	dw 0
idt_start:
	times 4096 db 0
idt_end:

; table of function pointers for interrupts
interrupt_table:
	times 256 dd 0

section .code

%macro _interrupt_stub 1
align 4
_intr%1:
	push DWORD %1
	jmp _intr_handler
%endmacro

%assign i 0
%rep 256 
	_interrupt_stub i
%assign i i+1
%endrep

interrupt_stub_size:
	dd (_intr1 - _intr0)


;----------------
_intr_handler:
	; determine address for interrupt handler
	; stack state at entry:
	; - EFLAGS
	; - CS
	; - EIP
	; - Error Code (for certain interrupts)
	; - Interrupt number

	; stack state just before call to handler:
	; - EFLAGS
	; - CS
	; - EIP
	; - Interrupt number
	; - EAX
	; - ECX
	; - EDX
	; - EBX
	; - ESP
	; - EBP
	; - ESI
	; - EDI
	; - ES
	; - FS
	; - GS
	; - DS
	; - Error code ( zero if unused )

	pusha
	push es
	push fs
	push gs
	push ds
	lea ebp, [esp+13*4]

	mov ebx, interrupt_table
	lea eax, [esp+12*4]
	mov eax, [eax]
	lea ebx, [ebx+eax*4]
	mov ebx, [ebx]
	mov ecx, eax
	; eax and ecx contain interrupt number
	; ebx contains function address

	call _has_error_code
	cmp eax, 1
	je _intr_handler_1
	push DWORD 0
	jmp _intr_handler_3

_intr_handler_1:	; error code present
	; ecx contains interrupt number
	; ebx contains function address
	; ebp contains location of error code
	
	mov edx, [ebp]
	push edx
	sub ebp, 12
	mov edx, 0
_intr_handler_2:
	lea eax, [ebp+edx]
	dec eax
	mov eax, [eax]
	mov [ebp+edx], eax
	inc edx
	cmp edx, 13
	jl _intr_handler_2
	
	pop edx
	mov [ebp-13], edx

_intr_handler_3:
	mov eax, ebx

	cmp eax, 0
	je _intr_handler_end

	mov ebx, esp		; address of beginning of interrupt data
	push ebx
	call eax
	add esp, 4

_intr_handler_end:
	pop ds
	pop gs
	pop fs
	pop es
	popa
	add esp, 4
	iret

;----------------
; interrupt number passed in eax
; Interrupts that have an error code are: 8(DF), 10(TS), 11(NP), 12(SS),
;  13(GP), 14(PF) and 17(AC)
_has_error_code:
	
	cmp eax, 8
	je _has_error_code_1
	cmp eax, 10
	je _has_error_code_1
	cmp eax, 11
	je _has_error_code_1
	cmp eax, 12
	je _has_error_code_1
	cmp eax, 13
	je _has_error_code_1
	cmp eax, 14
	je _has_error_code_1
	cmp eax, 17
	je _has_error_code_1
	jmp _has_error_code_2

_has_error_code_1:
	mov eax, 1
	ret
_has_error_code_2:
	mov eax, 0
	ret



;----------------
_idt_init:
	push ebp
	mov ebp, esp
	sub esp, 0x0C
	; ebp-0x04 -> entry in the IDT to modify
	; ebp-0x08 -> Address of interrupt handler stub
	; ebp-0x0C -> loop index

	; print out debug stuff
	;mov eax, [interrupt_stub_size]
	;push eax
	;mov eax, _intr0
	;push eax
	;mov eax, idt_start
	;push eax
	;mov eax, _idt_info_fmt
	;push eax
	;call printf
	;add esp, 0x10

	; initialise loop index
	mov ecx, 0
	mov [ebp-0x0C], ecx			; loop index
_idt_init_1:

	; determine the IDT descriptor to modify
	mov ecx, [ebp-0x0C]
	mov eax, idt_start
	lea eax, [eax+ecx*8]			; IDT entry to modify
	mov [ebp-0x04], eax			; entry in the IDT to modify

	; determine address of interrupt handler
	mov ecx, [ebp-0x0C]			; loop index
	mov eax, [interrupt_stub_size]	; length of interrupt stub
	mul cl
	add eax, _intr0				; Interrupt stub address
	mov [ebp-0x08], eax			; Address of interrupt handler stub

	; Calculate first part of descriptor
	mov eax, [ebp-0x08]
	and eax, 0xFFFF
	mov edx, eax
	mov eax, 0x10
	shl eax, 16
	or edx, eax
	mov eax, [ebp-0x04]				; entry in the IDT to modify
	mov [eax], edx

	; calculate the second part of descriptor
	mov eax, [ebp-0x08]			; Address of interrupt handler stub
	and eax, 0xFFFF0000
	mov edx, eax
	mov eax, 0x8E00
	or edx, eax
	mov eax, [ebp-0x04]				; entry in the IDT to modify
	add eax, 4
	mov [eax], edx

	; print out 1. Entry to modify, 2. Address of intr handler, 3. loop indx
	;mov eax, [ebp-0x0C]
	;push eax
	;mov eax, [ebp-0x08]
	;push eax
	;mov eax, [ebp-0x04]
	;push eax
	;mov eax, _loop_info_fmt
	;push eax
	;call printf
	;add esp, 0x10
	
	; increment loop index
	mov ecx, [ebp-0x0C]			; loop index
	add ecx, 1
	mov [ebp-0x0C], ecx			; loop index

	cmp ecx, 256
	jl NEAR _idt_init_1

	lidt [idt_desc]

	mov eax, 0
	mov esp, ebp
	pop ebp
	ret

