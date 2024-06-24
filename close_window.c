#include "so_long.h"

int close_window(t_game *game)
{
    free_map(game);
    mlx_loop_end(game->mlx_ptr);
    return 0;
}
