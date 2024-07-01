/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:45:50 by mrazanad          #+#    #+#             */
/*   Updated: 2024/02/27 10:45:52 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		srch;

	src = s;
	srch = c;
	while (n > 0)
	{
		if (*src == srch)
		{
			return ((void *)(src));
		}
		src++;
		n--;
	}
	return (NULL);
}
