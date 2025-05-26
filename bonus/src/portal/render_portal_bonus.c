/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_portal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:55:52 by mpendilh          #+#    #+#             */
/*   Updated: 2025/05/26 16:55:52 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	is_black(mlx_color *color)
{
	mlx_color	black;

	black.r = 0;
	black.g = 0;
	black.b = 0;
	black.a = 255;
	if (color->rgba == black.rgba)
		return (1);
	return (0);
}

int	portal_find(t_portal *portal, int x, int y, int dir)
{
	if (portal[BLUE].x == x && portal[BLUE].y == y && dir == portal[BLUE].dir)
		return (BLUE);
	else if (portal[ORANGE].x == x && portal[ORANGE].y == y
		&& dir == portal[ORANGE].dir)
		return (ORANGE);
	return (-1);
}
