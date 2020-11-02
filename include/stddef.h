#ifndef __STDDEF_H
#define __STDDEF_H

#undef NULL
#define NULL ((void *)0)

#ifndef _DEFINE_SIZE_T
# define _DEFINE_SIZE_T
typedef unsigned long int size_t;
#endif

#ifndef _DEFINE_PTRDIFF_T
# define _DEFINE_PTRDIFF_T
typedef unsigned long int ptrdiff_t;
#endif

#undef offsetof
#define offsetof(TYPE, MEMBER)	((size_t)&(((TYPE *)0)->MEMBER))

#endif /*__STDDEF_H*/
