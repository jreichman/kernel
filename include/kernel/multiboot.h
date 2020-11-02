#ifndef __MULTIBOOT_H
#define __MULTIBOOT_H

#include <types.h>

typedef struct multiboot {
	uint32 flags,
		mem_lower,
		mem_upper,
		boot_device,
		cmdline,
		mods_count,
		mods_addr;
	uchar syms[12];
	uint32 mmap_length;
	uint32 mmap_addr;
} multiboot_t;

#endif /*__MULTIBOOT_H*/

