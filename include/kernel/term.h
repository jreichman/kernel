#ifndef _TERM_H
#define _TERM_H

#include <stddef.h>
#include <types.h>


#define COLUMN_NUM	80
#define ROW_NUM		25

int term_init(void);

int term_write(char c);

int term_read(void);

void term_clear(void);

uint32 term_write_buffer(const char* buffer, size_t len);

uint32 term_read_buffer(char *buffer, size_t len);

#endif /*_TERM_H*/
