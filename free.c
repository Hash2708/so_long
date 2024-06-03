#include "so_long.h"

void cleanup(t_game *game)
{
    for (int i = 0; i < game->height; i++)
    {
        free(game->map[i]);
    }
    free(game->map);
}