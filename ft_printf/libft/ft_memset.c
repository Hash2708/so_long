/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:12:00 by mrazanad          #+#    #+#             */
/*   Updated: 2024/02/19 18:12:07 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *pointer, int c, size_t n)
{
	char	*p;

	p = pointer;
	while (n > 0)
	{
		*p++ = c;
		n--;
	}
	return (pointer);
}
