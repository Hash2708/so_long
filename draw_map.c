#include "so_long.h"

void draw_tile(t_game *game, void *img, int x, int y)
{
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
}

void draw_map(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == '1')
            {
                if (y == 0 || y == game->height - 1 || x == 0 || x == game->width - 1)
                {
                    draw_tile(game, game->img_wall, x, y);
                }
                else
                {
                    if ((x + y) % 3 == 0)
                        draw_tile(game, game->img_wall, x, y);
                    else if ((x + y) % 9 == 0)
                        draw_tile(game, game->img_wall, x, y);
                    else
                        draw_tile(game, game->img_wall, x, y);
                }
            }
            else if (game->map[y][x] == '0')
                draw_tile(game, game->img_floor, x, y);
            else if (game->map[y][x] == 'P')
            {
                if (game->player_direction == 0)
                    draw_tile(game, game->img_player_down, x, y);
                else if (game->player_direction == 1)
                    draw_tile(game, game->img_player_up, x, y);
                else if (game->player_direction == 2)
                    draw_tile(game, game->img_player_left, x, y);
                else
                    draw_tile(game, game->img_player_right, x, y);
            }
            else if (game->map[y][x] == 'C')
                draw_tile(game, game->img_collectible, x, y);
            else if (game->map[y][x] == 'E')
                draw_tile(game, game->img_exit, x, y);
            x++;
        }
        y++;
    }
}
