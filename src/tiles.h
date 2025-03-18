#ifndef TILES_H_
#define TILES_H_

#include "lib.h"

typedef struct tile
{
    char symbol;
} tile_t;

typedef struct tilemap
{
    tile_t **data;
    size_t rows;
    size_t cols;
} tilemap_t;

/*
 * Function: tilemap_init
 * ----------------------------
 *   Initializes a new tilemap struct
 *
 *   rows: number of tile rows
 *   cols: number of tile columns
 *
 *   returns: tilemap struct pointer
 */
tilemap_t *tilemap_init(size_t rows, size_t cols);

/*
 * Function: tilemap_initf
 * ----------------------------
 *   Initializes a new tilemap struct and fills it with data from a file
 *
 *   filePath: path of the file
 *
 *   returns: tilemap struct pointer
 */
tilemap_t *tilemap_initf(char *filePath);

/*
 * Function: tilemap_free
 * ----------------------------
 *   Frees the memory of a tilemap struct pointer
 *
 *   tilemap: tilemap
 */
void tilemap_free(tilemap_t *tilemap);

/*
 * Function: tile_init
 * ----------------------------
 *   Initializes a new tile struct
 *
 *   symbol: A char which the tile should represent
 *
 *   returns: tile struct
 */
tile_t tile_init(char symbol);

#endif
