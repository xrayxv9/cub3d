/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:27:16 by cmorel            #+#    #+#             */
/*   Updated: 2025/05/30 10:41:13 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "raycast.h"

int	is_wall(t_map *map, t_ray *ray)
{
	if (ray->map_y < 0 || ray->map_y >= map->h)
		return (0);
	else if (ray->map_x < 0 || ray->map_x >= ft_strlen(map->map[ray->map_y]))
		return (0);
	else if (map->map[ray->map_y][ray->map_x] == '1')
		return (1);
	return (0);
}

int	main_while(t_ray *ray, t_map *map, int x, int y)
{
	int	i;

	i = 0;
	while (i <= 50 && !is_wall(map, ray))
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = VER;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = HOR;
		}
		i++;
	}
	if (i == 51 || !simple_len(map->map, x, y))
		return (0);
	return (1);
}

void	line_handle(t_ray *ray)
{
	if (ray->side == VER)
		ray->wall_distance = (ray->side_x - ray->delta_x);
	else
		ray->wall_distance = (ray->side_y - ray->delta_y);
	ray->line_height = (int)(WIN_H / ray->wall_distance) * 1.25;
	ray->line_start_tmp = (WIN_H >> 1) - (ray->line_height >> 1);
	if (ray->line_start_tmp < 0)
		ray->line_start = 0;
	else
		ray->line_start = ray->line_start_tmp;
	ray->line_end = (ray->line_height >> 1) + (WIN_H >> 1);
	if (ray->line_end >= WIN_H)
		ray->line_end = WIN_H - 1;
}

void	handle_angle(t_player *player)
{
	if (player->angle >= 360)
		player->angle -= 360;
	if (player->angle < 0)
		player->angle = 360 + player->angle;
}

void	cast_ray(t_data *d)
{
	t_ray			ray;
	int				i;
	t_ang			angles;
	static double	delta_angle;

	i = 0;
	mlx_clear_window(d->game, d->window, (mlx_color){.rgba = 0x0000FFFF});
	handle_angle(&d->player);
	angles.start_angle = d->player.angle - 30;
	angles.end_angle = d->player.angle + 30;
	if (!delta_angle)
		delta_angle = 60.0 / WIN_W;
	render_bg(d);
	while (angles.start_angle <= angles.end_angle)
	{
		init(&ray, &d->player, angles.start_angle);
		if (main_while(&ray, &d->map, (int)d->player.x, (int)d->player.y))
		{
			line_handle(&ray);
			render_walls(d, &ray, i++);
		}
		angles.start_angle += delta_angle;
	}
	mlx_put_image_to_window(d->game, d->window,
		d->textures[4].texture, 0, 0);
}
