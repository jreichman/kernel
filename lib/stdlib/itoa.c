#include <stdlib.h>

char *__itoa_buffer(char * buffer, long int num, unsigned int base)
{
	char *begin, *it = buffer;
	unsigned long int opnum;
	int tmp = 0;
	char swapc;

	if(buffer == NULL)
		return NULL;

	if(num == 0 || base == 1 || base > 36) {
		*it++ = '0';
		*it = 0;
		return buffer;
	}

	switch(base) {
		case 0:
			base = 10;
		case 10:
			if(num < 0) {
				num = -num;
				*it++ = '-';
			}
			break;
		case 16:
			*it++ = '0';
			*it++ = 'x';
			break;
		case 8:
			*it = '0';
			break;
	}
	opnum = (unsigned long int)num;

	begin = it;
	while(opnum != 0) {
		tmp = opnum % base;
		if(tmp >= 10) {
			*it++ = 'A' + (tmp - 10);
		} else {
			*it++ = '0' + tmp;
		}
		if(opnum < base)
			opnum = 0;
		else
			opnum /= base;
	}
	*it-- = 0;
	while(it > begin) {
		swapc = *it;
		*it = *begin;
		*begin = swapc;
		--it;
		++begin;
	}
	return buffer;
}

char *itoa(long int num)
{
	return NULL;
}
