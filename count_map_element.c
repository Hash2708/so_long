/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:32:29 by mrazanad          #+#    #+#             */
/*   Updated: 2024/07/15 14:37:42 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_map_element(t_game *game, char elem, t_coords *coords,
		int *player_count)
{
	if (elem == 'P')
	{
		(*player_count)++;
		game->player_x = coords->x;
		game->player_y = coords->y;
	}
	else if (elem == 'C')
		game->collectibles++;
	else if (elem == 'E')
		game->exits++;
	else if (elem != '0' && elem != '1')
	{
		free_map(game);
		error_exit("Invalid character in map.\n");
	}
}

void	count_map_elements(t_game *game, int *player_count)
{
	int			y;
	int			x;
	t_coords	coords;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			coords.x = x;
			coords.y = y;
			process_map_element(game, game->map[y][x], &coords, player_count);
			x++;
		}
		y++;
	}
}
