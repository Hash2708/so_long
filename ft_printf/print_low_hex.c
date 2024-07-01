/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_low_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:08:25 by mrazanad          #+#    #+#             */
/*   Updated: 2024/03/11 11:08:27 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_low_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_low(unsigned int num)
{
	if (num >= 16)
	{
		ft_put_low(num / 16);
		ft_put_low(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd(num + '0', 1);
		else
			ft_putchar_fd((num - 10) + 'a', 1);
	}
}

int	print_low_hex(unsigned int num)
{
	int	print_len;

	print_len = ft_low_len(num);
	ft_put_low(num);
	return (print_len);
}
