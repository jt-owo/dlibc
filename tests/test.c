#include "../build/include/tiles.h"
#include "../build/include/renderer.h"

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        tilemap_t *tiles = tilemap_initf(argv[1]);

        screen_t *screen = screen_init(tiles);

        render_screen(screen);

        screen_free(screen);

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}