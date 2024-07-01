/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:46:01 by mrazanad          #+#    #+#             */
/*   Updated: 2024/03/04 11:10:02 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*txt1;
	const unsigned char	*txt2;

	txt1 = s1;
	txt2 = s2;
	while (n > 0)
	{
		if (*txt1 != *txt2)
		{
			return (*txt1 - *txt2);
		}
		n--;
		txt1++;
		txt2++;
	}
	return (0);
}
