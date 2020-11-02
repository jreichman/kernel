#include <stdio.h>
#include <string.h>
#include <kernel/kernel.h>
#include <kernel/interrupts.h>
#include <kernel/debug.h>

static char *intr_desc[] = {
/* 0 */		"Divide error",
/* 1 */		"Debug",
/* 2 */		"NMI Interrupt",
/* 3 */		"Breakpoint",
/* 4 */		"Overflow",
/* 5 */		"BOUND Range Exception",
/* 6 */		"Invalid Opcode",
/* 7 */		"No Math coprocessor",
/* 8 */		"Double fault",
/* 9 */		"Coprocessor segment overrun",
/* 10 */	"Invalid TSS",
/* 11 */	"Segment not present",
/* 12 */	"Stack Segment Fault",
/* 13 */	"General Protection Fault",
/* 14 */	"Page Fault",
/* 15 */	"Intel Reserved",
/* 16 */	"FPU error",
/* 17 */	"Alignment Check",
/* 18 */	"Machine check",
/* 19 */	"SIMD Floating Point Exception"
};


static void default_interrupt_handler(struct interrupt_info *info)
{
	KDEBUGVAR(info->ebx);
	KDEBUGVAR(info->edx);
	KDEBUGVAR(info->ecx);
	KDEBUGVAR(info->eax);
	KDEBUGVAR(info->inum);
/*	KDEBUGVAR(info->ecode);*/
	KDEBUGVAR(info->eip);
	KDEBUGVAR(info->cs);
	KDEBUGVAR(info->eflags);
	if(info->inum >= 0 && info->inum < 20)
		panic(intr_desc[info->inum]);
	else
		panic("Unknown Interrupt occured");
}

int interrupts_init(void)
{
	int i;

	for(i = 0; i < 256; ++i) {
		interrupt_table[i] = default_interrupt_handler;
	}

	return 0;
}
