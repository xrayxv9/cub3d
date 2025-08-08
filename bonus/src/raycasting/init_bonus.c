/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:56:55 by mpendilh          #+#    #+#             */
/*   Updated: 2025/08/08 01:49:52 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D_bonus.h>

void	init_step(t_ray *ray)
{
	if (ray->dir_x > 0)
		ray->step_x = 1;
	else
		ray->step_x = -1;
	if (ray->dir_y > 0)
		ray->step_y = 1;
	else
		ray->step_y = -1;
}

void	init_side(t_ray *ray, double x, double y)
{
	if (ray->step_x < 0)
		ray->side_x = (x - (double)ray->map_x) * ray->delta_x;
	else
		ray->side_x = ((double)ray->map_x + 1 - x) * ray->delta_x;
	if (ray->step_y < 0)
		ray->side_y = (y - (double)ray->map_y) * ray->delta_y;
	else
		ray->side_y = ((double)ray->map_y + 1 - y) * ray->delta_y;
}

t_ray	init_dda(t_ray *ray, double x, double y, float angle)
{
	ray->dir_x = cos(radian(angle));
	ray->dir_y = sin(radian(angle));
	ray->angle = angle;
	ray->tp = 0;
	ray->map_x = (int)x;
	ray->map_y = (int)y;
	if (ray->dir_x == 0)
		ray->delta_x = exp(30);
	else
		ray->delta_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_y = exp(30);
	else
		ray->delta_y = fabs(1 / ray->dir_y);
	init_step(ray);
	init_side(ray, x, y);
	return (*ray);
}
