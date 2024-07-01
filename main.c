/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:23:48 by mrazanad          #+#    #+#             */
/*   Updated: 2024/07/01 17:23:50 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_c(char **map, t_game *game)
{
	int	i;
	int	j;

	game->collectibles = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	parse_arguments(argc);
	load_and_validate_map(&game, argv[1]);
	init_graphics(&game);
	load_textures(&game);
	setup_initial_state(&game);
	setup_event_hooks(&game);
	start_game_loop(&game);
	cleanup_resources(&game);
	return (0);
}
