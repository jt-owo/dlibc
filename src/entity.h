#ifndef ENTITY_H_
#define ENTITY_H_

#include "lib.h"

typedef struct entity {
    char symbol;
    size_t x;
    size_t y;
} entity_t;

entity_t *entity_new(char symbol, size_t x, size_t y);

#endif
