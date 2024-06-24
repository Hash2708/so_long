NAME = so_long

SRCS = draw_map.c init_window.c load_textures.c error.c flood_fill.c free.c load_map.c main.c print_map.c validate.c free_map.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c handle_key_press.c start_game.c exit_game.c close_window.c draw_player.c move_player.c

OBJS = $(SRCS:.c=.o)

MLX = ./minilibx-linux/libmlx.a

all: $(NAME)

$(MLX):
	make -C minilibx-linux

%.o: %.c $(MLX)
	cc -Wuninitialized -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	cc -Wuninitialized $(OBJS) $(MLX) -Lmlx -L/usr/lib/X11 -lXext -lX11 -o $(NAME)

clean:
		rm -f $(OBJS)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re