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
        // Collect collectible if present
        if (game->map[new_y][new_x] == 'C')
        {
            game->collected++;
            game->map[new_y][new_x] = '0';
        }

        // Move player
        draw_tile(game, game->img_floor, game->player_x, game->player_y);
        game->player_x = new_x;
        game->player_y = new_y;
        draw_player(game);
        game->moves++;
        printf("Moves: %d\n", game->moves);

        if (game->map[game->player_y][game->player_x] == 'E')
        {
            if (game->collected == game->collectibles)
            {
                printf("You win!\n");
                close_window(game);
            }
            else
            {
                printf("You must collect all collectibles before exiting!\n");
            }
        }
    }
}
