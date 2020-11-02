#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int printf(const char *format, ...)
{
	int ret;
	va_list list;

	va_start(list, format);
	ret = vprintf(format, list);
	va_end(list);
	return ret;
}
