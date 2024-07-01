/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:56:22 by mrazanad          #+#    #+#             */
/*   Updated: 2024/02/23 14:56:24 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d <= s)
	{
		while (count--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d = d + count - 1;
		s = s + count - 1;
		while (count--)
		{
			*d-- = *s--;
		}
	}
	return (dest);
}
