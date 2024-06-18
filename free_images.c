#include "so_long.h"

void free_image(t_game *game)
{
    mlx_destroy_image(game->mlx_ptr, game->img_wall);
    mlx_destroy_image(game->mlx_ptr, game->img_wall_alt);
    mlx_destroy_image(game->mlx_ptr, game->img_tree);
    mlx_destroy_image(game->mlx_ptr, game->img_floor);

    /* for (int i = 0; i < 4; i++) {
        mlx_destroy_image(game->mlx_ptr, game->img_player_walk_up[i]);
        mlx_destroy_image(game->mlx_ptr, game->img_player_walk_down[i]);
        mlx_destroy_image(game->mlx_ptr, game->img_player_walk_left[i]);
        mlx_destroy_image(game->mlx_ptr, game->img_player_walk_right[i]);
    } */

    mlx_destroy_image(game->mlx_ptr, game->img_collectible);
    mlx_destroy_image(game->mlx_ptr, game->img_exit);
}
