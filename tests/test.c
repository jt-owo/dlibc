#include "../build/include/tiles.h"

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        // create tilemap and load content from file
        tilemap_t *tiles = tilemap_initf(argv[1]);

        tilemap_print(tiles);

        tilemap_free(tiles);

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}