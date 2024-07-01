/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:08:53 by mrazanad          #+#    #+#             */
/*   Updated: 2024/03/11 11:08:55 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	print_string(char *s)
{
	int	length;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
	{
		length = (int)ft_strlen(s);
		ft_putstr_fd(s, 1);
		return (length);
	}
}
