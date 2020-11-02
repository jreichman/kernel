#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int vsprintf(char * dest, const char * format, va_list list)
{
	return vsnprintf(dest, -1, format, list); 
}
