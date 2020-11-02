#ifndef _CONSOLE_H
#define _CONSOLE_H

#include <stddef.h>
#include <types.h>


int console_init(void);

int console_write(char c);

int console_read(void);

#endif /*_CONSOLE_H*/
