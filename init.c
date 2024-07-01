/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:22:25 by mrazanad          #+#    #+#             */
/*   Updated: 2024/07/01 17:22:27 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
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
