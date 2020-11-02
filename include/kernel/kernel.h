#ifndef __KERNEL_H
#define __KERNEL_H

#include <types.h>

void halt(void);
void pause(void);
#define panic(x)	_panic(x, __FILE__, __LINE__)

void _panic(const char *str, const char *file, uint line);
void _upanic(void);

#endif /*__KERNEL_H*/
