#include "so_long.h"

void move_player(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;

    new_x = game->player_x + dx;
    new_y = game->player_y + dy;

    if (new_x >= 0 && new_x < game->width && new_y >= 0 && new_y < game->height &&
        game->map[new_y][new_x] != '1')
    {
        draw_tile(game, game->img_floor, game->player_x, game->player_y);
        game->player_x = new_x;
        game->player_y = new_y;
        draw_player(game);
        game->moves++;
        printf("Moves: %d\n", game->moves);
    }
}
