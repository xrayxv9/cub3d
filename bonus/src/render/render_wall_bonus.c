/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:57:59 by mpendilh          #+#    #+#             */
/*   Updated: 2025/08/08 02:48:16 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	show(t_ray *ray, t_data *data, t_save_info *save, t_current *current)
{
	mlx_image	image;
	int			dir;
	double		delta;
	int			bo;

	dir = set_dir(ray);
	image = check_portal_coo(ray, data, data->textures[dir].texture, dir);
	bo = both(data->player.portals) && current->loop;
	while (ray->line_end >= save->y_image)
	{
		delta = (save->y_image - ray->line_start_tmp)
			/ (float)ray->line_height * 1000;
		current->color.rgba = mlx_get_image_pixel(data->game, image,
				ray->touch_loc * 1000, delta).rgba;
		if (current->loop)
		{
			if (!(bo && is_black(&current->color)))
				mlx_set_image_pixel(data->game, data->textures[4].texture,
					save->x_image, save->y_image, current->color);
		}
		else
			mlx_set_image_pixel(data->game, data->textures[4].texture,
				save->x_image, save->y_image, current->color);
		save->y_image++;
	}
}

void	calcul_touch_portal(t_ray *ray, t_save_info *save, int dir, int use)
{
	if (ray->side == VER)
		ray->touch_loc = save->dy + ray->wall_distance * ray->dir_y;
	else
		ray->touch_loc = save->dx + ray->wall_distance * ray->dir_x;
	ray->touch_loc -= (int)ray->touch_loc;
	if (use)
	{
		if (dir == NORTH)
			ray->touch_loc = 1 - ray->touch_loc;
		if (dir == EAST)
			ray->touch_loc = 1 - ray->touch_loc;
	}
}

void	render_wall_portal(t_data *data, t_ray ray, float angle, int type)
{
	int			dir;
	double		dist;
	t_current	current;
	t_save_info	save;
	t_save_info	save_between_rays;

	dist = ray.wall_distance;
	save_between_rays = reset_angle(data->player.portals,
			&ray, type, &data->map);
	dir = set_dir(&ray);
	current.ray = &ray;
	save.y_image = ray.line_start;
	save.x_image = angle;
	ray.wall_distance -= dist;
	calcul_touch_portal(&ray, &save_between_rays, dir, 1);
	current.i = 0;
	current.loop = 0;
	show(&ray, data, &save, &current);
}
