#ifndef __LIMITS_H
#define __LIMITS_H

#define CHAR_BIT	8

#define SCHAR_MIN	((char)(-128))
#define SCHAR_MAX	((char)127)

#define UCHAR_MAX	((unsigned char)255)
#define CHAR_MIN	((char)SCHAR_MIN)
#define CHAR_MAX	((char)SCHAR_MAX)

#define SHRT_MIN 	((short int)(-32768))
#define SHRT_MAX	((short int)32767)
#define USHRT_MAX	((unsigned short int)65535)
#define INT_MIN	((int)(-2147483648))
#define INT_MAX	((int)2147483647)
#define UINT_MAX	((unsigned int)4294967295)
#define LONG_MAX	((long int)INT_MAX)
#define LONG_MIN	((long int)INT_MIN)
#define ULONG_MAX	((unsigned long int)UINT_MAX)

#endif /*__LIMITS_H*/
