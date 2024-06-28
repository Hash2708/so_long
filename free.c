#include "so_long.h"

void cleanup(t_game *game)
{
    int i;

    i = 0;
    while (i < game->height)
    {
        free(game->map[i]);
        i++;
    }
}