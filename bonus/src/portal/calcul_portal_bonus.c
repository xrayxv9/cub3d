#include <cub3D_bonus.h>

void	line_handle_portal(t_ray *ray, double wall)
{
	if (ray->side == VER)
		ray->wall_distance = (ray->side_x - ray->delta_x);
	else
		ray->wall_distance = (ray->side_y - ray->delta_y);
	ray->wall_distance += wall;
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
