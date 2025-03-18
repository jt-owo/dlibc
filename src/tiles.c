#include "tiles.h"

static void get_file_data(tilemap_t *tilemap, FILE *file)
{
    if (tilemap == NULL)
        LIB_ERR("tilemap is null", ERR_PARAM_NULL);

    if (file == NULL)
        LIB_ERR("file is null", ERR_PARAM_NULL);

    char **map = calloc(tilemap->rows, sizeof(char *));
    if (map == NULL)
        LIB_ERR("Error allocating memory for rows.", ERR_MEM_ALLOC);

    for (size_t i = 0; i < tilemap->rows; i++)
    {
        // allocate file data memory
        map[i] = calloc(tilemap->cols, sizeof(char));
        if (map[i] == NULL)
            LIB_ERR("Error allocating memory for row", ERR_MEM_ALLOC);

        // Get file data
        for (size_t j = 0; j < tilemap->cols; ++j)
            fscanf(file, "%c", &map[i][j]);
    }

    // Fill tilemap with file data
    for (size_t i = 0; i < tilemap->rows; i++)
    {
        for (size_t j = 0; j < tilemap->cols; j++)
            tilemap->data[i][j] = tile_init(map[i][j]);
    }
}

static void get_rows_and_cols(size_t *rows, size_t *cols, FILE *file)
{
    char ch = 0;
    (*rows) = 1;
    (*cols) = 1;

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
            (*rows)++;
        else if ((*rows) == 1)
            (*cols)++;
    }
}

tilemap_t *tilemap_init(size_t rows, size_t cols)
{
    tilemap_t *tilemap = (tilemap_t *)malloc(sizeof(tilemap_t));

    if (tilemap == NULL)
        LIB_ERR("Error allocating memory for tilemap", ERR_MEM_ALLOC);

    tilemap->rows = rows;
    tilemap->cols = cols;

    tilemap->data = calloc(rows, sizeof(tile_t *));
    if (tilemap->data == NULL)
        LIB_ERR("Error allocating memory for tilemap rows", ERR_MEM_ALLOC);

    for (size_t i = 0; i < rows; i++)
    {
        tilemap->data[i] = calloc(cols, sizeof(tile_t));
        if (tilemap->data[i] == NULL)
            LIB_ERR("Error allocating memory for tilemap row", ERR_MEM_ALLOC);
    }

    return tilemap;
}

tilemap_t *tilemap_initf(char *filePath)
{
    if (filePath == NULL)
        LIB_ERR("File path is null", ERR_PARAM_NULL);

    tilemap_t *tm = (tilemap_t *)malloc(sizeof(tilemap_t));

    if (tm == NULL)
        LIB_ERR("Error allocating memory for tilemap", ERR_MEM_ALLOC);

    FILE *fp = fopen(filePath, "r");

    if (fp == NULL)
        LIB_ERR("Error opening file", ERR_FILE_OPEN);

    size_t rows, cols;
    get_rows_and_cols(&rows, &cols, fp);

    tm->rows = rows;
    tm->cols = cols;

    fclose(fp);

    tm->data = calloc(rows, sizeof(tile_t *));
    if (tm->data == NULL)
        LIB_ERR("Error allocating memory for tilemap rows", ERR_MEM_ALLOC);

    for (size_t i = 0; i < rows; i++)
    {
        tm->data[i] = calloc(cols, sizeof(tile_t));
        if (tm->data[i] == NULL)
            LIB_ERR("Error allocating memory for tilemap row", ERR_MEM_ALLOC);
    }

    fp = fopen(filePath, "r");

    if (fp == NULL)
        LIB_ERR("Error opening file", ERR_FILE_OPEN);

    get_file_data(tm, fp);

    fclose(fp);

    return tm;
}

void tilemap_free(tilemap_t *tilemap)
{
    if (tilemap == NULL)
        return;

    if (tilemap->data != NULL)
    {
        for (size_t i = 0; i < tilemap->rows; i++)
            free(tilemap->data[i]);

        free(tilemap->data);
    }

    free(tilemap);
}

tile_t tile_init(char symbol)
{
    tile_t t = {0};
    t.symbol = symbol;

    return t;
}