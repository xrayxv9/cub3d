/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:32:19 by mpendilh          #+#    #+#             */
/*   Updated: 2024/11/13 11:19:48 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_words(char *s, char c)
{
	int	i;
	int	count_word;
	int	is_in_word;

	i = 0;
	count_word = 0;
	is_in_word = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c && is_in_word == 0)
		{
			count_word++;
			is_in_word = 1;
		}
		if (s[i] == c && is_in_word == 1)
			is_in_word = 0;
		i++;
	}
	return (count_word);
}

static char	*ft_parsing(char *s, char c, int j)
{
	char			*res;
	unsigned int	i;
	int				size_of;

	i = 0;
	size_of = 0;
	while (s[j + size_of] != c && s[j + size_of])
		size_of++;
	res = malloc(sizeof(char) * size_of + 1);
	if (!res)
		return (NULL);
	while (s[i + j] != c && s[i + j] != '\0')
	{
		res[i] = s[i + j];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	**ft_free(char **res, int i)
{
	while (i >= 0)
		free(res[i--]);
	free(res);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		i;
	int		j;

	if (!s && !c)
		return (NULL);
	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		result[i] = ft_parsing(s, c, j);
		if (!result[i])
			return (ft_free(result, i));
		while (s[j] != c && s[j] != '\0')
			j++;
		i++;
	}
	result[i] = 0;
	return (result);
}
