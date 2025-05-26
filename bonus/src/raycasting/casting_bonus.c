/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:56:51 by mpendilh          #+#    #+#             */
/*   Updated: 2025/05/26 16:56:52 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D_bonus.h>

int	is_wall(t_map *map, int x, int y)
{
	if (y < 0 || y >= map->h)
		return (0);
	else if (x < 0 || x >= ft_strlen(map->map[y]))
		return (0);
	else if (map->map[y][x] == '1')
		return (1);
	return (0);
}

int	dda(t_ray *ray, t_map *map)
{
	int	i;

	i = 0;
	while ((i <= 50 && !is_wall(map, ray->map_x, ray->map_y)))
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
	if (i == 51)
		return (0);
	return (1);
}

void	line_handle(t_ray *ray, t_player *player, float x)
{
	(void)player;
	(void)x;
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

void	cast_ray(t_data *data)
{
	t_ray			ray;
	int				i;
	double			angle;
	static double	delta_angle;
	double			end_angle;

	i = 0;
	mlx_clear_window(data->game, data->window, (mlx_color){.rgba = 0x0000FFFF});
	handle_angle(&data->player);
	angle = data->player.angle - 30;
	end_angle = data->player.angle + 30;
	if (!delta_angle)
		delta_angle = 60.0 / WIN_W;
	render_bg(data);
	while (angle <= end_angle)
	{
		init_dda(&ray, data->player.x, data->player.y, angle);
		if (dda(&ray, &data->map))
		{
			line_handle(&ray, &(data->player), angle);
			render_walls(data, &ray, i++);
		}
		angle += delta_angle;
	}
	put_images_to_window(data);
}
