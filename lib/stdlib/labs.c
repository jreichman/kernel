#include <stdlib.h>

long int labs(long int val)
{
	return val < 0 ? -val : val;
}
