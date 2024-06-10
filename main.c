#include "so_long.h"

void count_c(char **map, t_game *game)
{
    game->collectibles = 0;
    for (int i = 0; map[i]; i++)
    {
        for (int j = 0; map[i][j]; j++)
        {
            if (map[i][j] == 'C')
                game->collectibles++;
        }
    }
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        error_exit("Usage: ./so_long <map_file>\n");
    load_map(&game, argv[1]);
    validate_map(&game);
    count_c(game.map, &game);
    game.mlx_ptr = mlx_init();
    if (!game.mlx_ptr)
        error_exit("Failed to initialize mlx.\n");

    game.win_ptr = mlx_new_window(game.mlx_ptr, game.width * TILE_SIZE, game.height * TILE_SIZE, "so_long");
    if (!game.win_ptr)
        error_exit("Failed to create window.\n");

    load_textures(&game);
    game.moves = 0;
    game.player_direction = 0;

    draw_map(&game);
    draw_player(&game);
    mlx_key_hook(game.win_ptr, handle_keypress, &game);
    mlx_hook(game.win_ptr, 17, 0, close_window, &game);
    mlx_loop(game.mlx_ptr);
    return 0;
}
