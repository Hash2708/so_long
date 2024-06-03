#include "so_long.h"

void start_game(t_game *game)
{
    draw_map(game);
    mlx_key_hook(game->win_ptr, handle_keypress, game);
    mlx_hook(game->win_ptr, 17, 0, handle_destroy, game);
    mlx_loop(game->mlx_ptr);
}
