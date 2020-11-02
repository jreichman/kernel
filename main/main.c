#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <kernel/kernel.h>
#include <kernel/multiboot.h>
#include <kernel/console.h>
#include <kernel/interrupts.h>
#include <asm/register.h>

int errno;
char **environ;

void crap_delay(void)
{
	char crap[100];
	int i,j;

	for(i = 0; i < 150000; ++i) {
		for(j = 0; j < 100; ++j) {
			crap[j] = 0;
		}
	}
}

void kmain(multiboot_t *header)
{
	int i;

	console_init();
	interrupts_init();
	printf("1\n");
	crap_delay();
	printf("2\n");
	crap_delay();
	printf("3\n");
	i = 5/0;
	printf("4 %d\n", i);
	panic("Nothing left to do");
}
