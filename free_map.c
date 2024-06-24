#include "so_long.h"

void free_map(t_game *game)
{
    int i;

    i = 0;
    if (game->map)
    {
        while (i <game->height)
        {
            if (game->map[i])
                free(game->map[i]);
            i++;
        }
        free(game->map);
        game->map = NULL;
    }
}