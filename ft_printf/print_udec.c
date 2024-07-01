/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_udec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:09:07 by mrazanad          #+#    #+#             */
/*   Updated: 2024/03/11 11:09:10 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_udec_len(unsigned int num)
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

void	ft_put_udec(unsigned int num)
{
	if (num >= 10)
	{
		ft_put_udec(num / 10);
		ft_put_udec(num % 10);
	}
	else
	{
		ft_putchar_fd((num + '0'), 1);
	}
}

int	print_udec(unsigned int num)
{
	int	print_len;

	print_len = 0;
	print_len = print_len + ft_udec_len(num);
	ft_put_udec(num);
	return (print_len);
}
