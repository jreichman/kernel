#ifndef __CTYPE_H
#define __CTYPE_H


int isgraph(int c)
{
	return 0;
}

int isprint(int c)
{
	return 0;
}

int ispunct(int c)
{
	return 0;
}

int iscntrl(int c)
{
	return 0;
}

int isdigit(int c)
{
	return (c >= 0x30 && c <= 0x39);
}

int isspace(int c)
{
	return (c >= 0x9 && c <= 0xD);
}

int islower(int c)
{
	return (c >= 0x61 && c <= 0x7A);
}

int isupper(int c)
{
	return (c >= 0x41 && c <= 0x5A);
}

int isalnum(int c)
{
	return (isalpha(c) || isdigit(c));
}

int isalpha(int c)
{
	return (islower(c) || isupper(c));
}

int isxdigit(int c)
{
	return isdigit(c) ||
		(c >= 0x41 && c <= 0x46) ||
		(c >= 0x61 && c <= 0x66);
}

int tolower(int c)
{
	if(isupper(c)) c |= (1 << 5);
	return c;
}

int toupper(int c)
{
	if(islower(c)) c &= ~(1 << 5);
	return c;
}

#endif /*__CTYPE_H*/

