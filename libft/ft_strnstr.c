/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:28:21 by mpendilh          #+#    #+#             */
/*   Updated: 2024/11/15 10:21:09 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(char *big, char *little, int len)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (little[size])
		size++;
	if (size == 0)
		return (big);
	while (*big && ft_strncmp(big, little, size) != 0 && i < len)
	{
		big++;
		i++;
	}
	if (*big && i + size <= len)
		return (big);
	return (NULL);
}
