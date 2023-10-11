#include "lib.h"

void lib_error(const char *file, size_t line, const char *msg, int8_t err)
{
    switch (err)
    {
    case ERR_MEM_ALLOC:
    case ERR_PARAM_NULL:
    case ERR_FILE_OPEN:
    default:
        // TODO: Add error logs
        printf("\n[ERROR:%d] %s:%d: %s\n", err, file, line, msg);
        exit(err);
    }
}

size_t rand_between(size_t min, size_t max)
{
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}