#ifndef _STDARG_H
#define _STDARG_H

typedef char * va_list;


#define __va_rounded_size(ARG) (((sizeof(ARG) + sizeof(int)-1) \
	/sizeof(int))*sizeof(int))

#define va_start(LIST, FIRST) ((LIST) = (va_list)&(FIRST)\
	+ __va_rounded_size(FIRST))

#define va_arg(LIST, TYPE) ((LIST) += __va_rounded_size(TYPE),\
	*(TYPE *) ((va_list)(LIST) - __va_rounded_size(TYPE)))

#define va_end(LIST)

#endif /*_STDARG_H*/
