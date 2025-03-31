/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:02:01 by mpendilh          #+#    #+#             */
/*   Updated: 2024/11/14 14:22:48 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_hexa(char *base, unsigned long int nb);
int		ft_hexaptr(char *base, unsigned long nb);
int		ft_putnbr(int nb);
int		ft_put_un_int(unsigned int nb);

#endif
