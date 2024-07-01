/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:08:12 by mrazanad          #+#    #+#             */
/*   Updated: 2024/03/11 11:08:14 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_int_len(int num)
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

void	ft_put_int(int num)
{
	if (num >= 10)
	{
		ft_put_int(num / 10);
		ft_put_int(num % 10);
	}
	else
	{
		ft_putchar_fd((num + '0'), 1);
	}
}

int	print_int(int num)
{
	int	print_len;

	print_len = 0;
	if (num == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
	}
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
		print_len++;
	}
	print_len = print_len + ft_int_len(num);
	ft_put_int(num);
	return (print_len);
}
