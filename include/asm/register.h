#ifndef __REGISTER_H
#define __REGISTER_H

#include <string.h>

typedef unsigned long int reg32_t;
typedef unsigned short int reg16_t;

struct registers
{
	reg32_t edi, esi,
		ebp, esp,
		ebx, edx,
		ecx, eax;
	reg32_t eflags;
	reg32_t cr0, cr1,
		cr2, cr3,
		cr4;
	reg32_t cs, ss,
		ds, es,
		fs, gs;
};

extern inline reg32_t get_flags32(void)
{
	reg32_t ret;
	asm volatile ("pushfl\n\t"
		"popl %0\n\t"
		: "=r" (ret)
		:);
	return ret;
}

extern inline reg16_t get_flags16(void)
{
	reg16_t ret;
	asm volatile ("pushf\n\t"
		"pops %0\n\t"
		: "=r" (ret)
		:);
	return ret;
}

extern inline reg32_t __get_cr0(void)
{
	reg32_t ret;
	asm volatile ("mov %%cr0, %0\n\t"
			: "=r" (ret) :);
	return ret;
}

extern inline reg32_t __get_cr1(void)
{
	return 0;
}

extern inline reg32_t __get_cr2(void)
{
	reg32_t ret;
	asm volatile ("mov %%cr2, %0\n\t"
			: "=r" (ret) :);
	return ret;
}

extern inline reg32_t __get_cr3(void)
{
	reg32_t ret;
	asm volatile ("mov %%cr3, %0\n\t"
			: "=r" (ret) :);
	return ret;
}

extern inline reg32_t __get_cr4(void)
{
	reg32_t ret;
	asm volatile ("mov %%cr4, %0\n\t"
			: "=r" (ret) :);
	return ret;
}

extern inline reg32_t __get_cs(void)
{
	reg32_t ret;
	asm volatile ("mov %%cs, %%eax\n\t"
			: "=a" (ret) :);
	return ret;
}

extern inline reg32_t __get_ss(void)
{
	reg32_t ret;
	asm volatile ("mov %%ss, %%eax\n\t"
			: "=a" (ret) :);
	return ret;
}

extern inline reg32_t __get_ds(void)
{
	reg32_t ret;
	asm volatile ("mov %%ds, %%eax\n\t"
			: "=a" (ret) :);
	return ret;
}

extern inline reg32_t __get_es(void)
{
	reg32_t ret;
	asm volatile ("mov %%es, %%eax\n\t"
			: "=a" (ret) :);
	return ret;
}

extern inline reg32_t __get_fs(void)
{
	reg32_t ret;
	asm volatile ("mov %%fs, %%eax\n\t"
			: "=a" (ret) :);
	return ret;
}

extern inline reg32_t __get_gs(void)
{
	reg32_t ret;
	asm volatile ("mov %%gs, %%eax\n\t"
			: "=a" (ret) :);
	return ret;
}

extern inline void __get_registers(struct registers *regs)
{
	char *tmp;
	asm volatile ("pushal\n\t"
			"movl %%esp, %0\n\t"
			: "=r" (tmp):);
	memcpy(&regs->edi, (void *)tmp, 0x20);
	asm volatile ("addl $0x20, %%esp\n\t" ::);
	regs->eflags = get_flags32();
	regs->cr0 = __get_cr0();
	regs->cr1 = __get_cr1();
	regs->cr2 = __get_cr2();
	regs->cr3 = __get_cr3();
	regs->cr4 = __get_cr4();
	regs->cs = __get_cs();
	regs->ss = __get_ss();
	regs->ds = __get_ds();
	regs->es = __get_es();
	regs->fs = __get_fs();
	regs->gs = __get_gs();
	
}


#endif /* __REGISTER_H */
