/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:23:30 by mrazanad          #+#    #+#             */
/*   Updated: 2024/07/01 17:23:32 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_arguments(int argc)
{
	if (argc != 2)
		error_exit("Usage: ./so_long <map_file>\n");
}

void	load_and_validate_map(t_game *game, char *map_file)
{
	load_map(game, map_file);
	validate_map(game);
	count_c(game->map, game);
}

void	init_graphics(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_exit("Failed to initialize mlx.\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		error_exit("Failed to create window.\n");
}

void	setup_initial_state(t_game *game)
{
	draw_map(game);
	draw_player(game, game->player_x, game->player_y);
}

void	setup_event_hooks(t_game *game)
{
	mlx_key_hook(game->win_ptr, handle_keypress, game);
	mlx_hook(game->win_ptr, 17, 0, close_window, game);
}
