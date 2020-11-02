#include <stdlib.h>

unsigned long strtoul(const char *string, char ** endptr, int base)
{
	return strtol(string, endptr, base);
}
