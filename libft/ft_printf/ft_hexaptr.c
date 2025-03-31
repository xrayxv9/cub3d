/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:48:19 by mpendilh          #+#    #+#             */
/*   Updated: 2024/11/10 15:39:06 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_hexa_len(unsigned long nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static void	ft_puthexa(char *base, unsigned long nb)
{
	if (nb >= 16)
	{
		ft_puthexa(base, nb / 16);
		ft_puthexa(base, nb % 16);
	}
	else
		ft_putchar(base[nb]);
}

int	ft_hexaptr(char *base, unsigned long nb)
{
	int	res;

	res = 0;
	if (!nb)
		return (ft_putstr("(nil)"));
	res += write (1, "0x", 2);
	ft_puthexa(base, nb);
	return (ft_hexa_len(nb) + res);
}
