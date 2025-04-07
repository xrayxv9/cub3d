#include "../../include/cub3D.h"

int	is_wall(t_map *map, t_ray *ray)
{
	if (ray->map_x < 0 || ray->map_x >= map->h)
		return (0);
	else if (ray->map_y < 0 || ray->map_y >= ft_strlen(map->map[ray->map_x]))
		return (0);
	else if (map->map[ray->map_x][ray->map_y] == '1')
		return (1);
	return (0);
}

int	main_while(t_ray *ray, t_map *map)
{
	// int	i;

	// i = 0;
	// printf("start\n");
	while (!is_wall(map, ray))
	{
		// printf("before : co : %d, %d\n", ray->map_x, ray->map_y);
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
		// printf("after : co : %d, %d\n", ray->map_x, ray->map_y);
		// i++;
	}
	// printf("%d.end\n", i);
	// if (i == 31)
	// 	return (0);
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

void	cast_ray(t_data *data, t_map *map)
{
	t_ray	ray;
	int		i;
	double	angle;
	double	delta_angle;
	double	end_angle;

	i = 0;
	end_angle = data->player.angle + 45;
	angle = data->player.angle - 45;
	delta_angle = 90.0 / 1920;
	while (angle <= end_angle)
	{
		ray = init(&ray, &data->player, angle);
		if (main_while(&ray, map))
		{
			line_handle(&ray, &(data->player));
			render_walls(data, &ray, i);
		}
		i++;
		angle += delta_angle;
	}
}
