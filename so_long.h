#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line/get_next_line.h"
#include "minilibx-linux/mlx.h"

#define TILE_SIZE 32

typedef struct s_game
{
    char **map;
    int width;
    int height;
    int player_x;
    int player_y;
    int collectibles;
    int exits;
    int moves;

    void *mlx_ptr;
    void *win_ptr;

    void *img_wall;
    void *img_wall_alt;
    void *img_tree;
    void *img_floor;
    void *img_player_up;
    void *img_player_down;
    void *img_player_left;
    void *img_player_right;
    void *img_exit;
    void *img_collectible;

    int player_direction;
} t_game;

void load_map(t_game *game, char *map_file);
void error_exit(const char *message);
char *get_next_line(int fd);
void cleanup(t_game *game);

void flood_fill(char **map, int x, int y, t_game *game);

void validate_rectangle(t_game *game);
void validate_borders(t_game *game);
void validate_path(t_game *game);
void validate_map(t_game *game);
void print_map(t_game *game);

void draw_tile(t_game *game, void *img, int x, int y);
void draw_map(t_game *game);

void init_window(t_game *game);
void load_textures(t_game *game);

int handle_keypress(int keycode, t_game *game);
void start_game(t_game *game);
void exit_game(t_game *game);
int handle_destroy(t_game *game);
int close_window(t_game *game);
void free_image(t_game *game);

void move_player(t_game *game, int dx, int dy);
void draw_player(t_game *game);
#endif
