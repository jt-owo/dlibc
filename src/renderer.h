#ifndef RENDERER_H_
#define RENDERER_H_

#include "./tiles.h"

typedef struct screen
{
    tilemap_t *content;
} screen_t;

/*
 * Function: screen_init
 * ----------------------------
 *   Initializes a new tilemap struct
 *
 *   tilemap: tilemap struct pointer that the screen knows what to display.
 *
 *   returns: screen struct pointer
 */
screen_t *screen_init(tilemap_t *tilemap);

/*
 * Function: screen_free
 * ----------------------------
 *   Frees the memory of a screen struct pointer.
 * 
 *   This functions also clears the screen data.
 *
 *   screen: screen struct pointer
 */
void screen_free(screen_t *screen);

/*
 * Function: render_screen
 * ----------------------------
 *   Renders a screen (Only tilemap data works currently)
 */
void render_screen(screen_t *screen);

#endif
