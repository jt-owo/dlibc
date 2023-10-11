#ifndef _H_LIBUTILS
#define _H_LIBUTILS

#define TRUE 1
#define FALSE 0

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define IS_ARRAY(a) ((void *)&a == (void *)a)

#endif