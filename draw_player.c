#include "so_long.h"

void draw_player(t_game *game)
{
    void *player_img;

    if (game->player_direction == 0)
        player_img = game->img_player_down;
    else if (game->player_direction == 1)
        player_img = game->img_player_up;
    else if (game->player_direction == 2)
        player_img = game->img_player_left;
    else
        player_img = game->img_player_right;

    draw_tile(game, player_img, game->player_x, game->player_y);
}
