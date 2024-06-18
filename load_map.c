#include "so_long.h"
#include <stdio.h>

void load_map(t_game *game, char *map_file)
{
    int fd = open(map_file, O_RDONLY);
    if (fd == -1)
        error_exit("Failed to open map file.\n");

    char *line;
    int line_count = 0;

    line = get_next_line(fd);
    if (!line)
        error_exit("Empty map file.\n");

    char *newline = strchr(line, '\n');
    if (newline)
        *newline = '\0';

    game->width = strlen(line);
    game->height = 1;
    game->collectibles = 0;
    game->collected = 0;
    game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
    if (!game->map)
        error_exit("Memory allocation failed.\n");
    game->map[line_count] = strdup(line);
    free(line);
    while ((line = get_next_line(fd)))
    {
        game->height++;
        game->map = (char **)realloc(game->map, sizeof(char *) * (game->height + 1));
        if (!game->map)
            error_exit("Memory allocation failed.\n");
        newline = strchr(line, '\n');
        if (newline)
            *newline = '\0';
        game->map[line_count + 1] = strdup(line);
        free(line);
        line_count++;
    }
    close(fd);
    validate_map(game);
}
