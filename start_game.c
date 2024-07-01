/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:24:19 by mrazanad          #+#    #+#             */
/*   Updated: 2024/07/01 17:24:21 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	draw_map(game);
	mlx_key_hook(game->win_ptr, handle_keypress, game);
	mlx_hook(game->win_ptr, 17, 0, handle_destroy, game);
	mlx_loop(game->mlx_ptr);
}
