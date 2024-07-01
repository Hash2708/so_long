/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:46:15 by mrazanad          #+#    #+#             */
/*   Updated: 2024/02/29 08:46:17 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*r;

	r = malloc((ft_len(s) + 1) * sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	while (i < ft_len(s))
	{
		r[i] = (*f)(i, s[i]);
		i++;
	}
	r[i] = 0;
	return (r);
}
