#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

static int __vsnprintf_write(struct __printf_write_str* handler,
					 const char *data)
{
	size_t len;

	len = strlen(data);
	if(handler->arg == NULL) return -1;
	if(len+1 > handler->len) return -1;
	strcat((char *)(handler->arg), data);
	handler->len -= len;
	return len;
}

int vsnprintf(char * dest, size_t len, const char * format, va_list list)
{
	struct __printf_write_str output = { __vsnprintf_write, dest, len };
	dest[0] = 0;

	return __parse_printf_fmt(&output, format, list);
}
