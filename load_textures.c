/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:22:47 by mrazanad          #+#    #+#             */
/*   Updated: 2024/07/01 17:22:49 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_wall_textures(t_game *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/xpm/32/rock.xpm", &width, &height);
	if (!game->img_wall)
		error_exit("Failed to load wall texture.\n");
	game->img_wall_alt = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/xpm/32/bush.xpm", &width, &height);
	if (!game->img_wall_alt)
		error_exit("Failed to load wall texture.\n");
}

void	load_tree_texture(t_game *game)
{
	int	width;
	int	height;

	game->img_tree = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/xpm/32/tree.xpm", &width, &height);
	if (!game->img_tree)
		error_exit("Failed to load wall texture.\n");
}

void	load_floor_texture(t_game *game)
{
	int	width;
	int	height;

	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/xpm/32/ground.xpm", &width, &height);
	if (!game->img_floor)
		error_exit("Failed to load floor texture.\n");
}

void	load_player_textures(t_game *game)
{
	int	width;
	int	height;

	game->img_player_up = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/xpm/32/up.xpm", &width, &height);
	if (!game->img_player_up)
		error_exit("Failed to load up texture.\n");
	game->img_player_down = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/xpm/32/down.xpm", &width, &height);
	if (!game->img_player_down)
		error_exit("Failed to load down texture.\n");
	game->img_player_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/xpm/32/left.xpm", &width, &height);
	if (!game->img_player_left)
		error_exit("Failed to load left texture.\n");
	game->img_player_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/xpm/32/right.xpm", &width, &height);
	if (!game->img_player_right)
		error_exit("Failed to load right texture.\n");
}

void	load_collectible_texture(t_game *game)
{
	int	width;
	int	height;

	game->img_collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/xpm/32/collectible.xpm", &width, &height);
	if (!game->img_collectible)
		error_exit("Failed to load collectible texture.\n");
}
