#include "../../include/cub3D.h"

double	radian(float angle)
{
	return (angle * M_PI / 180);
}

void	wall_distance(t_ray *ray, t_player *player)
{
	double	diff;
	double	angle;

	if (ray->side == VER)
		ray->wall_distance = (ray->map_x - player->x
				+ (1.0 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->wall_distance = (ray->map_y - player->y
				+ (1.0 - ray->step_y) / 2) / ray->dir_y;
	angle = atan2(ray->dir_y, ray->dir_x);
	diff = angle - radian(player->angle);
	while (diff > M_PI)
		diff -= 2 * M_PI;
	while (diff < -M_PI)
		diff += 2 * M_PI;
	ray->wall_distance *= cos(diff);
}
