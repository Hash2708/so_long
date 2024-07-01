/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:08:01 by mrazanad          #+#    #+#             */
/*   Updated: 2024/03/11 11:23:37 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_num_len(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

void	ft_put_num(long num)
{
	if (num >= 10)
	{
		ft_put_num(num / 10);
		ft_put_num(num % 10);
	}
	else
	{
		ft_putchar_fd((num + '0'), 1);
	}
}

int	print_dec(long num)
{
	int	print_len;

	print_len = 0;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
		print_len++;
	}
	print_len = print_len + ft_num_len(num);
	ft_put_num(num);
	return (print_len);
}
