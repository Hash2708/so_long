/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:33:09 by mrazanad          #+#    #+#             */
/*   Updated: 2024/07/15 14:27:41 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE_SIZE 32

typedef struct s_coords
{
	int		x;
	int		y;
}			t_coords;

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collected;
	int		exits;
	int		moves;
	int		player_direction;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_wall;
	void	*img_wall_alt;
	void	*img_tree;
	void	*img_floor;
	void	*img_player_up;
	void	*img_player_down;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_exit;
	void	*img_collectible;

}			t_game;

// load_map
char		*get_next_line(int fd);
char		*read_lines(int fd);
int			count_lines(char *lines);
void		initialize_game_map(t_game *game, char *lines, int line_count);
void		count_collectibles(t_game *game);
void		load_map(t_game *game, char *map_file);

// validate_map
void		validate_rectangle(t_game *game);
void		validate_borders(t_game *game);
void		validate_path(t_game *game);
void		process_map_element(t_game *game, char elem, t_coords *coords,
				int *player_count);
void		count_map_elements(t_game *game, int *player_count);
void		check_map_conditions(t_game *game, int player_count);
void		validate_map(t_game *game);

// draw_map
void		draw_tile(t_game *game, void *img, int x, int y);
void		draw_wall(t_game *game, int x, int y);
void		draw_player(t_game *game, int x, int y);
void		draw_map_row(t_game *game, int y);
void		draw_map(t_game *game);
void		print_map(t_game *game);

// load_textures
void		load_wall_textures(t_game *game);
void		load_tree_texture(t_game *game);
void		load_floor_texture(t_game *game);
void		load_exit_texture(t_game *game);
void		load_collectible_texture(t_game *game);
void		load_player_textures(t_game *game);
void		load_textures(t_game *game);

// move_player
int			is_valid_move(t_game *game, int new_x, int new_y);
void		handle_collectible(t_game *game, int new_x, int new_y);
int			handle_exit(t_game *game, int new_x, int new_y);
void		update_player_position(t_game *game, int new_x, int new_y);
void		move_player(t_game *game, int dx, int dy);

// main utils
void		parse_arguments(int argc);
void		load_and_validate_map(t_game *game, char *map_file);
void		init_graphics(t_game *game);
void		setup_initial_state(t_game *game);
void		setup_event_hooks(t_game *game);
void		start_game_loop(t_game *game);
void		cleanup_resources(t_game *game);
void		count_c(char **map, t_game *game);

void		init_window(t_game *game);
void		error_exit(const char *message);
void		cleanup(t_game *game);
int			handle_keypress(int keycode, t_game *game);
void		start_game(t_game *game);
void		exit_game(t_game *game);
int			handle_destroy(t_game *game);
int			close_window(t_game *game);

void		free_image(t_game *game);
void		free_map(t_game *game);

void		init_game(t_game *game);

char		**ft_split(char const *s, char c);
char		*ft_realloc_and_join(char *s1, char *s2);
void		flood_fill(char **map, int x, int y, t_game *game);

#endif
