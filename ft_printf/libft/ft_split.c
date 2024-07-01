/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:01:40 by mrazanad          #+#    #+#             */
/*   Updated: 2024/02/28 13:01:43 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	count_word(const char *str, char c)
{
	int	i;
	int	ending;

	i = 0;
	ending = 0;
	while (*str)
	{
		if (*str != c && ending == 0)
		{
			ending = 1;
			i++;
		}
		else if (*str == c)
			ending = 0;
		str++;
	}
	return (i);
}

char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	size_t			j;
	int				index;
	char			**split;

	i = 0;
	j = 0;
	index = -1;
	split = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!s || !(split))
		return (0);
	while (i <= ft_strlen((char *)s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen((char *)s)) && index >= 0)
		{
			split[j] = fill_word(s, index, i);
			index = -1;
			j++;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
