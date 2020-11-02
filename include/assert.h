#ifndef __ASSERT_H
#define __ASSERT_H

#define assert(expr) ((void) (expr ? 0 : panic(#expr)))

#endif /*__ASSERT_H*/
