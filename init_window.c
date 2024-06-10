#include "so_long.h"

void init_window(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
        error_exit("Failed to initialize MiniLibX.\n");

    game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILE_SIZE, game->height * TILE_SIZE, "so_long");
    if (!game->win_ptr)
        error_exit("Failed to create window.\n");
}
