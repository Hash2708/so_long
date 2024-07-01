/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:24:32 by mrazanad          #+#    #+#             */
/*   Updated: 2024/07/01 17:24:34 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map(t_game *game)
{
	int	player_count;

	player_count = 0;
	game->collectibles = 0;
	game->exits = 0;
	count_map_elements(game, &player_count);
	check_map_conditions(game, player_count);
	validate_rectangle(game);
	validate_borders(game);
	validate_path(game);
}
