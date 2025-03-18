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

void render_screen(screen_t *screen)
{
    if (screen == NULL)
        LIB_ERR("screen is null", ERR_PARAM_NULL);

    if (screen->content == NULL)
        LIB_ERR("screen data is null", ERR_OBJECT_NULL);

    if (screen->content->rows <= 0 || screen->content->cols <= 0)
        printf("\nrows: %ld, cols: %ld", screen->content->rows, screen->content->cols), exit(-1);

    for (size_t i = 0; i < screen->content->rows; i++)
    {
        for (size_t j = 0; j < screen->content->cols; j++)
        {
            printf("%c", screen->content->data[i][j].symbol);
        }
    }
}