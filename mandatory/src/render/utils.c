#include "cub3D.h"

void	calcul_touch(t_ray *ray, t_player *player, int dir)
{
	if (ray->side == VER)
		ray->touch_loc = player->y + ray->wall_distance * ray->dir_y;
	else
		ray->touch_loc = player->x + ray->wall_distance * ray->dir_x;
	if (dir == NORTH)
		ray->touch_loc = 3060 - ray->touch_loc;
	if (dir == EAST)
		ray->touch_loc = 3060 - ray->touch_loc;
	ray->touch_loc -= (int)ray->touch_loc;
}
