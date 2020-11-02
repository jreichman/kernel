#include <stdio.h>
#include <stdarg.h>

int sprintf(char *buf, const char *format, ...)
{
	int ret;
	va_list list;

	va_start(list, format);
	ret = vsprintf(buf, format, list);
	va_end(list);
	return ret;
}
