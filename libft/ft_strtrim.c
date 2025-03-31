/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:00:24 by mpendilh          #+#    #+#             */
/*   Updated: 2024/11/13 11:33:43 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*res;
	char	*prefix;
	char	*suffix;
	int		i;

	i = 0;
	prefix = s1;
	suffix = s1 + ft_strlen(s1) - 1;
	while (ft_is_in_set(*prefix, set) && !*prefix)
		prefix++;
	if (suffix - prefix < 0)
		return (ft_strdup(""));
	while (ft_is_in_set(*suffix, set) && suffix >= s1)
		suffix--;
	res = malloc(suffix - prefix + 2);
	if (!res)
		return (NULL);
	while (i <= suffix - prefix)
	{
		res[i] = prefix[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
