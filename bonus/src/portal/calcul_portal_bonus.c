#include <cub3D_bonus.h>

void	line_handle_portal(t_ray *ray, t_portal portal, float x, double wall)
{
	if (ray->side == VER)
		ray->wall_distance = (ray->side_x - ray->delta_x)
			* cos(radian(ray->angle - x));
	else
		ray->wall_distance = (ray->side_y - ray->delta_y)
			* cos(radian(ray->angle - x));
	ray->wall_distance += wall;
	ray->line_height = (int)(WIN_H / ray->wall_distance);
	ray->line_start_tmp = WIN_H * 0.5 - ray->line_height * 0.5;
	if (ray->line_start_tmp < 0)
		ray->line_start = 0;
	else
		ray->line_start = ray->line_start_tmp;
	ray->line_end = ray->line_height * 0.5 + WIN_H * 0.5;
	if (ray->line_end >= WIN_H)
		ray->line_end = WIN_H - 1;
	if (ray->side == 0)
		ray->wall_x = portal.y + ray->wall_distance * ray->dir_y;
	else
		ray->wall_x = portal.x + ray->wall_distance * ray->dir_x;
	ray->wall_x -= (int)ray->wall_x;
}
