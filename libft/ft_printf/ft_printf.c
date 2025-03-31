/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:48:59 by mpendilh          #+#    #+#             */
/*   Updated: 2024/11/14 13:45:30 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_flags(const char *format, va_list ptr, int i)
{
	int	res;

	res = 0;
	if (format[i + 1] == 'c')
		res += ft_putchar(va_arg(ptr, int));
	else if (format[i + 1] == 's')
		res += ft_putstr(va_arg(ptr, char *));
	else if (format[i + 1] == 'x')
		res += ft_hexa("0123456789abcdef", va_arg(ptr, unsigned int));
	else if (format[i + 1] == 'X')
		res += ft_hexa("0123456789ABCDEF", va_arg(ptr, unsigned int));
	else if (format[i + 1] == 'p')
		res += ft_hexaptr("0123456789abcdef", va_arg(ptr, unsigned long int));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		res += ft_putnbr(va_arg(ptr, int));
	else if (format[i + 1] == 'u')
		res += ft_put_un_int(va_arg(ptr, unsigned int));
	else if (format[i + 1] == '%')
		res += ft_putchar('%');
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		res;
	int		i;

	res = 0;
	i = 0;
	va_start(ptr, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			res += ft_flags(format, ptr, i);
			i++;
		}
		else
			res += ft_putchar(format[i]);
		i++;
	}
	va_end(ptr);
	return (res);
}
