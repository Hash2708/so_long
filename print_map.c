#include "so_long.h"

void print_map(t_game *game)
{
    int y = 0;
    while (y < game->height)
    {
        printf("%s\n", game->map[y]);
        y++;
    }
}
