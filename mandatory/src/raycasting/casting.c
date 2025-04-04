#include "../../include/cub3D.h"

int	is_wall(t_map *map, t_ray *ray)
{
	if (ray->mapX < 0 || ray->mapX >= map->x)
		return (0);
	else if (ray->mapY < 0 || ray->mapY >= ft_strlen(map->map[ray->mapX]))
		return (0);
	else if (map->map[ray->mapX][ray->mapY] == '1')
		return (1);
	return (0);
}

void	main_while(t_ray *ray, t_map *map)
{
	// int	i;

	// i = 0;
	while (!is_wall(map, ray))
	{
		if (ray->sideX > ray->sideY)
		{
			ray->sideX += ray->deltaX;
			ray->mapX += ray->stepX;
			ray->side = VER;
		}
		else
		{
			ray->sideY += ray->deltaY;
			ray->mapY += ray->mapY;
			ray->side = HOR;
		}
		// i++;
	}
	printf("here is the map : (%d,%d)\n", ray->mapX, ray->mapY);
}

void	line_handle(t_ray *ray, t_player *player)
{
	if (ray->side == VER)
		ray->wall_distance = (ray->sideX - ray->deltaX);
	else
		ray->wall_distance = (ray->sideY - ray->deltaY);
	ray->line_height = (int)(WIN_H / ray->wall_distance);
	ray->line_start = WIN_H * 0.5 - ray->line_height * 0.5;
	if (ray->line_start < 0)
		ray->line_start = 0;
	ray->line_end = ray->line_height * 0.5 + WIN_H * 0.5;
	if (ray->line_end >= WIN_H)
		ray->line_end = WIN_H - 1;
	if (ray->side == 0)
		ray->wallX = player->y + ray->wall_distance * ray->dirY;
	else
		ray->wallX = player->x + ray->wall_distance * ray->dirX;
	ray->wallX -= floor(ray->wallX);
}

void	cast_ray(t_data *data, t_map map, t_halfs ha)
{
	t_ray	ray;
	int		i;
	(void)ha;
	// 90 - 33

	i = 0; 
	while (i <= 1920)
	{
		ray = init(&ray, &data->player, i);
		main_while(&ray, &map);
		line_handle(&ray, &(data->player));
		render_walls(data, &ray);
		i++;
	}
}
