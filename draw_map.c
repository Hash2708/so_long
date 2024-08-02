/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:20:35 by mrazanad          #+#    #+#             */
/*   Updated: 2024/08/02 08:47:31 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x * TILE_SIZE, y
		* TILE_SIZE);
}

void	draw_wall(t_game *game, int x, int y)
{
	if (y == 0 || y == game->height - 1 || x == 0 || x == game->width - 1)
		draw_tile(game, game->img_wall, x, y);
	else
	{
		if ((x + y) % 3 == 0 || (x + y) % 9 == 0)
			draw_tile(game, game->img_wall, x, y);
		else
			draw_tile(game, game->img_wall, x, y);
	}
}

void	draw_player(t_game *game, int x, int y)
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

void	draw_map_row(t_game *game, int y)
{
	int		x;
	char	tile;

	x = 0;
	while (x < game->width)
	{
		tile = game->map[y][x];
		if (tile == '1')
			draw_wall(game, x, y);
		else if (tile == '0')
			draw_tile(game, game->img_floor, x, y);
		else if (tile == 'P')
			draw_player(game, x, y);
		else if (tile == 'C')
			draw_tile(game, game->img_collectible, x, y);
		else if (tile == 'E')
			draw_tile(game, game->img_exit, x, y);
		x++;
	}
}

void	draw_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->height)
	{
		draw_map_row(game, y);
		y++;
	}
}
