#include "../../include/cub3D.h"
#include <mandatory/include/raycast.h>
#include <math.h>
// side = (posY - mapY )* deltaY

void	init_step(t_ray *ray)
{
	if (ray->dirX > 0)
		ray->stepX = 1;
	else
		ray->stepX = -1;
	if (ray->dirY > 0)
		ray->stepY = 1;
	else
		ray->stepY = -1;
}

void init_side(t_ray *ray)
{
	if (ray->stepX < 0)
		ray->sideX = (ray->posX - ray->mapX) * ray->deltaX;
	else
		ray->sideX = (ray->mapX + 1 - ray->posX) * ray->deltaX;
	if (ray->stepY < 0)
		ray->sideY = (ray->posY - ray->mapY) * ray->deltaY;
	else
		ray->sideY = (ray->mapY + 1 - ray->posY) * ray->deltaY;
}

void	init(t_ray *ray, t_player player, float angle)
{
	ray->posX = player.x;
	ray->posY = player.y;
	ray->dirX = cos(convert_to_radian(angle));
	ray->dirY = sin(convert_to_radian(angle));
	ray->deltaX = sqrt(1 + pow(ray->dirY, 2) / pow(ray->dirX, 2));
	ray->deltaY = sqrt(1 + pow(ray->dirX, 2) / pow(ray->dirY, 2));
	ray->mapX = floor(ray->posX);
	ray->mapY = floor(ray->posY);
	init_step(ray);
	init_side(ray);
}
