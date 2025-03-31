/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 06:53:13 by mpendilh          #+#    #+#             */
/*   Updated: 2024/11/11 13:39:38 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_hexa_len(unsigned long int nb)
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

static void	ft_puthexa(char *base, unsigned long int nb)
{
	if (nb >= 16)
	{
		ft_puthexa(base, nb / 16);
		ft_puthexa(base, nb % 16);
	}
	else
		ft_putchar(base[nb]);
}

int	ft_hexa(char *base, unsigned long int nb)
{
	if (!nb)
		return (ft_putchar('0'));
	ft_puthexa(base, nb);
	return (ft_hexa_len(nb));
}
