/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:27:23 by cmorel            #+#    #+#             */
/*   Updated: 2025/05/30 10:43:16 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

double	radian(float angle)
{
	return (angle * M_PI / 180);
}

int	simple_len(char **map, int pos_x, int pos_y)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (map[y])
		y++;
	if (pos_y >= y || pos_y <= 0)
		return (0);
	while (map[pos_y][x])
		x++;
	if (pos_x <= 0 || pos_y <= 0)
		return (0);
	if (x <= pos_x || y <= pos_y)
		return (0);
	return (1);
}
