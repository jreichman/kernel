#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static int __vprintf_write(struct __printf_write_str* handler,
					 const char *data)
{
	return puts(data);
}

int vprintf(const char * format, va_list list)
{
	struct __printf_write_str output = { __vprintf_write, NULL, 0};

	return __parse_printf_fmt(&output, format, list);
}

