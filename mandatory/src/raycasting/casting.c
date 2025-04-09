#include "cub3D.h"
#include "mlx.h"

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

int	main_while(t_ray *ray, t_map *map)
{
	while (!is_wall(map, ray))
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
	}
	return (1);
}

void	line_handle(t_ray *ray, t_player *player)
{
	if (ray->side == VER)
		ray->wall_distance = (ray->side_x - ray->delta_x);
	else
		ray->wall_distance = (ray->side_y - ray->delta_y);
	ray->line_height = (int)(WIN_H / ray->wall_distance);
	ray->line_start = WIN_H * 0.5 - ray->line_height * 0.5;
	if (ray->line_start < 0)
		ray->line_start = 0;
	ray->line_end = ray->line_height * 0.5 + WIN_H * 0.5;
	if (ray->line_end >= WIN_H)
		ray->line_end = WIN_H - 1;
	if (ray->side == 0)
		ray->wall_x = player->y + ray->wall_distance * ray->dir_y;
	else
		ray->wall_x = player->x + ray->wall_distance * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
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
	t_ray	ray;
	int		i;
	double	angle;
	double	delta_angle;
	double	end_angle;

	i = 0;
	mlx_clear_window(data->game, data->window, (mlx_color){.rgba = 0x0000FFFF});
	handle_angle(&data->player);
	end_angle = data->player.angle + 45;
	angle = data->player.angle - 45;
	delta_angle = 90.0 / 1920;
	render_bg(data);
	while (angle <= end_angle)
	{
		ray = init(&ray, &data->player, angle);
		if (main_while(&ray, &data->map))
		{
			line_handle(&ray, &(data->player));
			render_walls(data, &ray, i++);
		}
		angle += delta_angle;
	}
	mlx_put_image_to_window(data->game, data->window,
		data->textures[6].texture, 0, 0);
}
