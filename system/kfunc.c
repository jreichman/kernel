#include <stdio.h>
#include <kernel/kernel.h>
#include <asm/register.h>

void halt(void)
{
	asm("1: cli\n\t"
	    "hlt\n\t"
	    "jmp 1\n\t");
}

void pause(void)
{
	asm("hlt\n\t" :: );
}

void _upanic(void)
{
	_panic(NULL, NULL, 0);
}

void _panic(const char *expr, const char *file, uint line)
{
	struct registers regs;

	__get_registers(&regs);

	if(expr != NULL)
		printf("Kernel Panic: %s\n", expr);
	else
		printf("Kernel Panic!\n");
	
	if(file != NULL)
		printf("\tLocation: %s:%d\n", file, line);
	printf("\tEAX: %x\tEBX: %x\n", regs.eax, regs.ebx);
	printf("\tECX: %x\tEDX: %x\n", regs.ecx, regs.edx);
	printf("\tEDI: %x\tEDI: %x\n", regs.edi, regs.edi);
	printf("\tESP: %x\tEBP: %x\n", regs.esp, regs.ebp);
	printf("\tEFLAGS: %x\n", regs.eflags);
	printf("\tCR0: %x\tCR1: %x\n", regs.cr0, regs.cr1);
	printf("\tCR2: %x\tCR3: %x\n", regs.cr2, regs.cr3);
	printf("\tCR4: %x\n", regs.cr4);
	printf("\tCS: %x\tSS: %x\n", regs.cs, regs.ss);
	printf("\tDS: %x\tES: %x\n", regs.ds, regs.es);
	printf("\tFS: %x\tGS: %x\n", regs.fs, regs.gs);
	halt();
}
