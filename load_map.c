/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:22:34 by mrazanad          #+#    #+#             */
/*   Updated: 2024/08/02 09:56:40 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_lines(int fd)
{
	char	*next_line;
	char	*lines;
	char	*temp;

	next_line = get_next_line(fd);
	lines = NULL;
	if (next_line)
		lines = ft_strdup("");
	while (next_line)
	{
		temp = lines;
		lines = ft_realloc_and_join(lines, next_line);
		free(temp);
		free(next_line);
		next_line = get_next_line(fd);
	}
	return (lines);
}

void	initialize_game_map(t_game *game, char *lines)
{
	game->map = ft_split(lines, '\n');
	free(lines);
	if (!game->map || !game->map[0])
	{
		free_map(game);
		error_exit("Empty map file.\n");
	}
	game->width = ft_strlen(game->map[0]);
	while (game->map[game->height])
		game->height++;
}

void	count_collectibles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->collectibles = 0;
	game->collected = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
				game->collectibles++;
			if (game->map[y][x] == 'E')
			{
				game->exit_pos[0] = x;
				game->exit_pos[1] = y;
			}
			x++;
		}
		y++;
	}
}

void	load_map(t_game *game, char *map_file)
{
	int		fd;
	char	*lines;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_exit("Failed to open map file.\n");
	lines = read_lines(fd);
	close(fd);
	if (!lines)
		error_exit("Empty map file.\n");
	initialize_game_map(game, lines);
	count_collectibles(game);
	validate_map(game);
}
