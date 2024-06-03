#include "so_long.h"

void exit_game(t_game *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    exit(0);
}
int handle_destroy(t_game *game)
{
    exit_game(game);
    return 0;
}
