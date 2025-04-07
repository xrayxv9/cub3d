#include "../../include/cub3D.h"
#include <mandatory/include/raycast.h>
#include <math.h>
// side = (posY - mapY )* deltaY

void	init_step(t_ray *ray)
{
	if (ray->dir_x > 0)
		ray->step_x = 1;
	else
		ray->step_x = -1;
	if (ray->dir_y > 0)
		ray->step_y = 1;
	else
		ray->step_y = -1;
}

void	init_side(t_ray *ray, t_player *player)
{
	if (ray->step_x < 0)
		ray->side_x = (player->x - (double)ray->map_x) * ray->delta_x;
	else
		ray->side_x = ((double)ray->map_x + 1 - player->x) * ray->delta_x;
	if (ray->step_y < 0)
		ray->side_y = (player->y - (double)ray->map_y) * ray->delta_y;
	else
		ray->side_y = ((double)ray->map_y + 1 - player->y) * ray->delta_y;
}

t_ray	init(t_ray *ray, t_player *player, float angle)
{
	ray->dir_x = cos(convert_to_radian(angle));
	ray->dir_y = sin(convert_to_radian(angle));
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	if (ray->dir_x == 0)
		ray->delta_x = exp(30);
	else
		ray->delta_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_y = exp(30);
	else
		ray->delta_y = fabs(1 / ray->dir_y);
	init_step(ray);
	init_side(ray, player);
	return (*ray);
}
