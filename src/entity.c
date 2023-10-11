#include "entity.h"

entity_t *entity_new(char symbol, size_t x, size_t y)
{
    entity_t *entity = (entity_t *)malloc(sizeof(entity_t));
    entity->symbol = symbol;
    entity->x = x;
    entity->y = y;

    return entity;
}