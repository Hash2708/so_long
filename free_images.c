/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:21:15 by mrazanad          #+#    #+#             */
/*   Updated: 2024/07/01 17:21:17 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_image(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_image(game->mlx_ptr, game->img_wall_alt);
	mlx_destroy_image(game->mlx_ptr, game->img_tree);
	mlx_destroy_image(game->mlx_ptr, game->img_floor);
	mlx_destroy_image(game->mlx_ptr, game->img_player_up);
	mlx_destroy_image(game->mlx_ptr, game->img_player_down);
	mlx_destroy_image(game->mlx_ptr, game->img_player_left);
	mlx_destroy_image(game->mlx_ptr, game->img_player_right);
	mlx_destroy_image(game->mlx_ptr, game->img_collectible);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
}
