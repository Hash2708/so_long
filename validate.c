#include "so_long.h"

void validate_rectangle(t_game *game)
{
    int i = 0;
    while (i < game->height)
    {
        if ((int)strlen(game->map[i]) != game->width)
        {
            error_exit("Map is not rectangular.\n");
        }
        i++;
    }
}

void validate_borders(t_game *game)
{
    int i = 0;
    while (i < game->width)
    {
        if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
        {
            error_exit("Map is not closed by walls.\n");
        }
        i++;
    }

    i = 0;
    while (i < game->height)
    {
        if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
        {
            error_exit("Map is not closed by walls.\n");
        }
        i++;
    }
}

void validate_path(t_game *game)
{
    char **map_copy;

    map_copy = (char **)malloc(sizeof(char *) * game->height);
    if (!map_copy)
        error_exit("Memory allocation failed for map copy.\n");

    int i;

    i = 0;
    while (i < game->height)
    {
        map_copy[i] = strdup(game->map[i]);
        if (!map_copy[i])
            error_exit("Memory allocation failed for map copy.\n");
        i++;
    }
    flood_fill(map_copy, game->player_x, game->player_y, game);
    i = 0;
    while (i < game->height)
    {
        free(map_copy[i]);
        i++;
    }
    free(map_copy);
    if (game->collectibles > 0 || game->exits > 0)
        error_exit("No valid path exists in the map.\n");
}

void validate_map(t_game *game)
{
    int player_count;
    int y;
    int x;

    player_count = 0;
    game->collectibles = 0;
    game->exits = 0;
    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == 'P')
            {
                player_count++;
                game->player_x = x;
                game->player_y = y;
            }
            else if (game->map[y][x] == 'C')
                game->collectibles++;
            else if (game->map[y][x] == 'E')
                game->exits++;
            else if (game->map[y][x] != '0' && game->map[y][x] != '1')
                error_exit("Invalid character in map.\n");
            x++;
        }
        y++;
    }

    if (player_count != 1)
        error_exit("Map must contain exactly one player.\n");
    if (game->collectibles < 1)
        error_exit("Map must contain at least one collectible.\n");
    if (game->exits != 1)
        error_exit("Map must contain exactly one exit.\n");
    validate_rectangle(game);
    validate_borders(game);
    validate_path(game);
}
