#ifndef __IO_H
#define __IO_H

#include <types.h>

extern inline void outb(uint16 port, uchar data)
{
	asm("outb %%al, %%dx\n\t"
		: : "d" (port), "a" (data));
}

extern inline void outw(uint16 port, uint16 data)
{
	asm("outw %%ax, %%dx\n\t"
		: : "d" (port), "a" (data));
}

extern inline void outd(uint16 port, uint32 data)
{
	asm("outd %%eax, %%dx\n\t"
		: : "d" (port), "a" (data));
}

extern inline uchar inb(uint16 port)
{
	uchar ret;

	asm("inb %%dx, %%al\n\t"
		: "=a" (ret)
		: "d" (port));
	return ret;
}

extern inline uint16 inw(uint16 port)
{
	uint16 ret;

	asm("inw %%dx, %%ax\n\t"
		: "=a" (ret)
		: "d" (port));
	return ret;
}
extern inline uint32 ind(uint16 port)
{
	uint32 ret;

	asm("in %%dx, %%eax\n\t"
		: "=a" (ret)
		: "d" (port));
	return ret;
}

#endif /* __IO_H */
