/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:36:26 by mpendilh          #+#    #+#             */
/*   Updated: 2024/10/15 16:51:32 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_sizeof(int n)
{
	int				i;
	unsigned int	num;

	i = 0;
	num = n;
	if (n < 0)
	{
		num = n * -1;
		i++;
	}
	while (num >= 10)
	{
		num /= 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	nbr;
	int				i;

	if (n < 0)
		nbr = (unsigned int)n * -1;
	else
		nbr = (unsigned int)n;
	res = malloc(sizeof(char) * (ft_sizeof(n) + 1));
	if (!res)
		return (NULL);
	i = ft_sizeof(n);
	res[i] = '\0';
	while (i > 0)
	{
		res[--i] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (n < 0)
	{
		res[0] = '-';
		return (res);
	}
	return (res);
}
