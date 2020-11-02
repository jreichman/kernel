#include <stdio.h>
#include <stdarg.h>

int snprintf(char * dest, size_t len, const char * format, ...)
{
	int ret;
	va_list list;

	va_start(list, format);
	ret = vsnprintf(dest, len, format, list);
	va_end(list);
	return ret;
}
