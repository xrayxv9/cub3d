/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_un_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:11:48 by mpendilh          #+#    #+#             */
/*   Updated: 2024/11/11 13:40:03 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_deci_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	ft_put_deci(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_put_deci(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}

int	ft_put_un_int(unsigned int nb)
{
	if (!nb)
		return (ft_putchar('0'));
	ft_put_deci(nb);
	return (ft_deci_len(nb));
}
