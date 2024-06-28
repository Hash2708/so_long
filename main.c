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
void init_game(t_game *game)
{
    game->map = NULL;
    game->width = 0;
    game->height = 0;
    game->player_x = 0;
    game->player_y = 0;
    game->collectibles = 0;
    game->collected = 0;
    game->exits = 0;
    game->moves = 0;
    game->player_direction = 0;
    
    game->mlx_ptr = NULL;
    game->win_ptr = NULL;
    game->img_wall = NULL;
    game->img_wall_alt = NULL;
    game->img_tree = NULL;
    game->img_floor = NULL;
    game->img_player_up = NULL;
    game->img_player_down = NULL;
    game->img_player_left = NULL;
    game->img_player_right = NULL;
    game->img_exit = NULL;
    game->img_collectible = NULL;
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        error_exit("Usage: ./so_long <map_file>\n");
    init_game(&game);
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
    // free
    free_map(&game);
    free_image(&game);
    mlx_destroy_window(game.mlx_ptr, game.win_ptr);
    mlx_destroy_display(game.mlx_ptr);
    free(game.mlx_ptr);
    return 0;
}
