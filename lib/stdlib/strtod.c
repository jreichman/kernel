#include <stdlib.h>

double strtod(const char *string, char ** endptr, int base)
{
	return strtold(string, endptr, base);
}
