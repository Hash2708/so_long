/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:23:56 by mrazanad          #+#    #+#             */
/*   Updated: 2024/07/01 17:23:58 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(t_game *game, int new_x, int new_y)
{
	return (new_x >= 0 && new_x < game->width && new_y >= 0
		&& new_y < game->height && game->map[new_y][new_x] != '1');
}

void	handle_collectible(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
}

int	handle_exit(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collected == game->collectibles)
		{
			ft_printf("You win!\n");
			close_window(game);
			return (1);
		}
		else
		{
			ft_printf("You must collect all collectibles before exiting!\n");
			return (1);
		}
	}
	return (0);
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	draw_tile(game, game->img_floor, game->player_x, game->player_y);
	game->player_x = new_x;
	game->player_y = new_y;
	draw_player(game, game->player_x, game->player_y);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (is_valid_move(game, new_x, new_y))
	{
		handle_collectible(game, new_x, new_y);
		if (!handle_exit(game, new_x, new_y))
		{
			update_player_position(game, new_x, new_y);
			game->moves++;
			ft_printf("Moves: %d\n", game->moves);
		}
	}
}
