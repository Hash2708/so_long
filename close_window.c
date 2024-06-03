#include "so_long.h"

int close_window(t_game *game)
{
    free_image(game);
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    exit(0);
    return 0;
}
