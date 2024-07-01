/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:54:19 by mrazanad          #+#    #+#             */
/*   Updated: 2024/02/28 08:54:21 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	size_t	i;
	char	*out;

	first = 0;
	while (s1[first] && in_set(s1[first], set))
		first++;
	last = 0;
	while (s1[last])
		last++;
	while (last > first && in_set(s1[last - 1], set))
		last--;
	out = (char *)malloc(last - first + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (first < last)
	{
		out[i] = s1[first];
		i++;
		first++;
	}
	out[i] = '\0';
	return (out);
}

/*int main()
{
	const char  *txt;
	const char  *set;
	char    *r;

	txt = "loololploloalololl";
	set = "ol";
	r = ft_strtrim(txt, set);
	printf("Resultat : %s\n", r);
	free(r);
	return (0);
}*/
