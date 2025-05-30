/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:57:50 by mpendilh          #+#    #+#             */
/*   Updated: 2025/05/30 16:47:58 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	render_celling(t_data *data, mlx_color color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WIN_H >> 1)
	{
		j = 0;
		while (WIN_W > j)
		{
			mlx_set_image_pixel(data->game,
				data->textures[4].texture, j, i, color);
			j++;
		}
		i++;
	}
}

void	render_floor(t_data *data, mlx_color color)
{
	int	i;
	int	j;

	i = WIN_H >> 1;
	while (i < WIN_H)
	{
		j = 0;
		while (WIN_W > j)
		{
			mlx_set_image_pixel(data->game,
				data->textures[4].texture, j, i, color);
			j++;
		}
		i++;
	}
}

void	render_bg(t_data *data)
{
	render_celling(data, data->color[SKY]);
	render_floor(data, data->color[FLOOR]);
}

int	set_dir(t_ray *ray)
{
	if (ray->side == VER && ray->dir_x > 0)
		return (EAST);
	else if (ray->side == VER && ray->dir_x < 0)
		return (WEST);
	else if (ray->side == HOR && ray->dir_y > 0)
		return (NORTH);
	else
		return (SOUTH);
}

void	render_walls(t_data *data, t_ray *ray, int x_image)
{
	t_save_info	save;
	int			dir;
	t_current	current;
	int			type;
	t_portal	*portals;

	portals = data->player.portals;
	dir = set_dir(ray);
	type = portal_find(data->player.portals, ray->map_x, ray->map_y, dir);
	if (type != -1 && both(portals) && ray->touch_loc > 0.31
		&& ray->touch_loc < 0.75)
		render_wall_portal(data, *ray, x_image, type);
	current.ray = ray;
	save.y_image = ray->line_start;
	save.x_image = x_image;
	calcul_touch(ray, &data->player, dir, 1);
	current.i = 0;
	current.loop = 1;
	show(ray, data, &save, &current);
}
