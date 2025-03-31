/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:21:19 by mpendilh          #+#    #+#             */
/*   Updated: 2024/11/13 11:56:50 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strlcat(char *dst, char *src, int size)
{
	int	len_dst;
	int	len_src;
	int	i;

	if (dst == NULL && size == 0)
		return (ft_strlen(src) + size);
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && len_dst + i + 1 < size && size != 0)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	if (len_dst > size)
		return (len_src + size);
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
