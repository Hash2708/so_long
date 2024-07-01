/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosea-razanadrakoto <marvin@42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:58:24 by hosea-razanad     #+#    #+#             */
/*   Updated: 2024/03/10 21:58:30 by hosea-razanad    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	handle_specifier(const char *input, va_list args, int *i)
{
	int	length;

	length = 0;
	if (input[*i + 1] == 'c')
		length = length + print_char(va_arg(args, int));
	else if (input[*i + 1] == 's')
		length = length + print_string(va_arg(args, char *));
	else if (input[*i + 1] == 'p')
		length = length + print_void(va_arg(args, void *));
	else if (input[*i + 1] == 'd' || input[*i + 1] == 'i')
		length = length + print_dec(va_arg(args, int));
	else if (input[*i + 1] == 'u')
		length = length + print_udec(va_arg(args, unsigned int));
	else if (input[*i + 1] == 'x')
		length = length + print_low_hex(va_arg(args, unsigned int));
	else if (input[*i + 1] == 'X')
		length = length + print_up_hex(va_arg(args, unsigned int));
	else if (input[*i + 1] == '%')
		length = length + print_percent();
	return (length);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		length;
	int		i;

	length = 0;
	i = 0;
	va_start(args, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			length += handle_specifier(input, args, &i);
			i++;
		}
		else
		{
			length++;
			ft_putchar_fd(input[i], 1);
		}
		i++;
	}
	va_end(args);
	return (length);
}
