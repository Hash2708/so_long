SRCS = ft_printf.c print_char.c print_string.c print_void.c print_dec.c print_int.c print_udec.c print_low_hex.c print_up_hex.c print_percent.c
SRCS += $(wildcard libft/*.c)

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

.c.o:
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
