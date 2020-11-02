#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H

#include <asm/register.h>

struct interrupt_info {
	reg32_t ds, gs, 
		fs, es;
	reg32_t edi, esi,
		ebp, esp,
		ebx, edx,
		ecx, eax;
	uint32 inum;
/*	uint32 ecode;*/
	reg32_t eip;
	reg32_t cs;
	reg32_t eflags;
};

extern void (*interrupt_table[256])(struct interrupt_info *);

int interrupts_init(void);

extern inline void cli(void)
{
	asm("cli\n\t" :: );
}

extern inline void sti(void)
{
	asm("sti\n\t" :: );
}

#endif /* __INTERRUPTS_H */
