/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_void.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:09:32 by mrazanad          #+#    #+#             */
/*   Updated: 2024/03/11 11:09:34 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_ptr_len(void *ptr)
{
	int				len;
	unsigned long	num;

	len = 0;
	num = (unsigned long)ptr;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(void *ptr)
{
	unsigned long	num;

	num = (unsigned long)ptr;
	if (num >= 16)
	{
		ft_put_ptr((void *)(num / 16));
		ft_put_ptr((void *)(num % 16));
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	print_void(void *ptr)
{
	int	print_len;

	print_len = 0;
	if (ptr == 0)
		print_len = print_len + write(1, "(nil)", 5);
	else
	{
		print_len = print_len + write(1, "0x", 2);
		ft_put_ptr(ptr);
		print_len = print_len + ft_ptr_len(ptr);
	}
	return (print_len);
}
