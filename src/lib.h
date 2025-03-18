#ifndef LIB_H_
#define LIB_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define LIB_NAME "owolib"
#define LIB_VERSION "0.1"

#define ERR_MEM_ALLOC 0x01
#define ERR_PARAM_NULL 0x02
#define ERR_FILE_OPEN 0x04
#define ERR_OBJECT_NULL 0x08

#define LIB_ERR(msg, err) lib_error(__FILE__, __LINE__, msg, err)

#define LEN(arr) ((int)(sizeof(arr) / sizeof(arr)[0]))

/*
 * Function: lib_error
 * ----------------------------
 *   Error handler method for the library.
 *   Do not use this function use the LIB_ERR macro.
 *
 *   file: __FILE__
 *   line: __LINE__
 *   msg: Error message
 *   err: Error code
 */
void lib_error(const char *file, size_t line, const char *msg, int8_t err);

#endif
