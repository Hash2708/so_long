NAME = so_long

SRCS = draw_map.c init_window.c load_textures.c load_textures_II.c error.c flood_fill.c free.c load_map.c main.c main_utils.c main_utils2.c print_map.c validate.c free_map.c ft_split.c realloc_and_join.c free_images.c init.c validate_map.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c handle_key_press.c start_game.c exit_game.c close_window.c move_player.c

OBJS = $(SRCS:.c=.o)

MLX = ./minilibx-linux/libmlx.a

LIBFTPRINTF = ./ft_printf/libftprintf.a

all: $(NAME)

$(MLX):
	make -C minilibx-linux

%.o: %.c $(MLX)
	cc -Wuninitialized -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	cc -Wuninitialized $(OBJS) $(MLX) $(LIBFTPRINTF) -Lmlx -L/usr/lib/X11 -lXext -lX11 -o $(NAME)

clean:
		rm -f $(OBJS)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re