#include "raycast_bonus.h"
#include <cub3D_bonus.h>

void	east_portal(int type, int anti, t_double *dou)
{
	if (type == EAST)
	{
		if (anti == NORTH)
			dou->dx += 1 - dou->touch;
		else if (anti == SOUTH)
			dou->dx = dou->touch;
		else if (anti == WEST)
			dou->dy += 1 - dou->touch;
		else if (anti == EAST)
			dou->dy += dou->touch;
	}
}

void	south_portal(int type, int anti, t_double *dou)
{
	if (type == SOUTH)
	{
		if (anti == NORTH)
			dou->dx += 1 - dou->touch;
		else if (anti == SOUTH)
			dou->dx = dou->touch;
		else if (anti == WEST)
			dou->dy += dou->touch;
		else if (anti == EAST)
			dou->dy += 1 - dou->touch;
	}
	else if (type == WEST)
	{
		if (anti == NORTH)
			dou->dx += 1 - dou->touch;
		else if (anti == SOUTH)
			dou->dx = dou->touch;
		else if (anti == WEST)
			dou->dy += 1 - dou->touch;
		else if (anti == EAST)
			dou->dy += dou->touch;
	}
	else
		east_portal(type, anti, dou);
}

void	init_side_portal(t_ray *ray, t_portal *portal, int type, int anti)
{
	t_double	dou;

	dou.dx = portal[anti].x;
	dou.dy = portal[anti].y;
	dou.touch = ray->touch_loc;
	if (type == NORTH)
	{
		if (anti == NORTH)
			dou.dx += 1 - dou.touch;
		else if (anti == SOUTH)
			dou.dx += dou.touch;
		else if (anti == WEST)
			dou.dy += dou.touch;
		else
			dou.dy += 1 - dou.touch;
	}
	else
		south_portal(type, anti, &dou);
	init_side(ray, dou.dx, dou.dy);
}
