#include "renderer.h"

screen_t *screen_init(tilemap_t *tilemap)
{
    if (tilemap == NULL)
        LIB_ERR("tilemap is null", ERR_PARAM_NULL);

    screen_t *screen = (screen_t *)malloc(sizeof(screen_t));

    if (screen == NULL)
        LIB_ERR("Error allocating memory for screen", ERR_MEM_ALLOC);

    screen->content = tilemap;

    return screen;
}

void screen_free(screen_t *screen)
{
    if (screen == NULL)
        return;

    if (screen->content != NULL)
    {
        tilemap_free(screen->content);
    }

    free(screen);
}

entity_t *generate_mob(size_t x, size_t y)
{
    entity_t *mob = entity_new('E', x, y);
    return mob;
}

void render(screen_t *screen, entity_t *player)
{
    if (screen == NULL)
        LIB_ERR("screen is null", ERR_PARAM_NULL);

    if (screen->content == NULL)
        LIB_ERR("screen data is null", ERR_OBJECT_NULL);

    if (screen->content->rows <= 0 || screen->content->cols <= 0)
        printf("\nrows: %d, cols: %d", screen->content->rows, screen->content->cols), exit(-1);

    if (player != NULL)
    {
        screen->content->data[3][5].sym = player->symbol;
    }

    int16_t maxMobCount = 5;
    int16_t mobCount = 0;

    for (size_t i = 0; i < screen->content->rows; i++)
    {
        for (size_t j = 0; j < screen->content->cols; j++)
        {
            char symbol = screen->content->data[i][j].sym;
            if (maxMobCount >= mobCount && symbol != '#' && 10 > rand_between(1, 100))
            {
                printf("%c", generate_mob(i, j)->symbol);
                mobCount++;
            }
            else
            {
                printf("%c", symbol);
            }
        }
    }
}