#ifndef __DEBUG_H
#define __DEBUG_H

#include <stdio.h>

#define KDEBUGVAR(x)		(void)(printf(#x " == %x\n", x))

#endif /*__DEBUG_H*/
