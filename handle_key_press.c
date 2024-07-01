/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:22:03 by mrazanad          #+#    #+#             */
/*   Updated: 2024/07/01 17:22:06 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 'w' || keycode == 'W')
	{
		game->player_direction = 1;
		move_player(game, 0, -1);
	}
	else if (keycode == 's' || keycode == 'S')
	{
		game->player_direction = 0;
		move_player(game, 0, 1);
	}
	else if (keycode == 'a' || keycode == 'A')
	{
		game->player_direction = 2;
		move_player(game, -1, 0);
	}
	else if (keycode == 'd' || keycode == 'D')
	{
		game->player_direction = 3;
		move_player(game, 1, 0);
	}
	return (0);
}
