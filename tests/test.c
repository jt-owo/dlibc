#include "../build/include/tiles.h"
#include "../build/include/renderer.h"

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        // create tilemap and load content from file
        tilemap_t *tiles = tilemap_initf(argv[1]);

        screen_t *screen = screen_init(tiles);

        render(screen);

        screen_free(screen);

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}