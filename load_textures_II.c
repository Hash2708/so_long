/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_II.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:23:16 by mrazanad          #+#    #+#             */
/*   Updated: 2024/07/01 17:23:19 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_exit_texture(t_game *game)
{
	int	width;
	int	height;

	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/xpm/32/exit3.xpm", &width, &height);
	if (!game->img_exit)
		error_exit("Failed to load exit texture.\n");
}

void	load_textures(t_game *game)
{
	load_wall_textures(game);
	load_tree_texture(game);
	load_floor_texture(game);
	load_player_textures(game);
	load_collectible_texture(game);
	load_exit_texture(game);
}
