#include "raycast_bonus.h"
#include <cub3D_bonus.h>

void	east_portal(t_portal *portal, int type, int anti, t_double *dou)
{
	if (portal[type].dir == EAST)
	{
		if (portal[anti].dir == NORTH)
			dou->dx += 1 - dou->touch;
		else if (portal[anti].dir == SOUTH)
			dou->dx = dou->touch;
		else if (portal[anti].dir == WEST)
			dou->dy += 1 - dou->touch;
		else if (portal[anti].dir == EAST)
			dou->dy += dou->touch;
	}
}

void	south_portal(t_portal *portal, int type, int anti, t_double *dou)
{
	if (type == SOUTH)
	{
		if (portal[type].dir == NORTH)
			dou->dx += 1 - dou->touch;
		else if (portal[anti].dir == SOUTH)
			dou->dx = dou->touch;
		else if (portal[anti].dir == WEST)
			dou->dy += dou->touch;
		else if (portal[anti].dir == EAST)
			dou->dy += 1 - dou->touch;
	}
	else if (portal[type].dir == WEST)
	{
		if (portal[anti].dir == NORTH)
			dou->dx += 1 - dou->touch;
		else if (portal[anti].dir == SOUTH)
			dou->dx = dou->touch;
		else if (portal[anti].dir == WEST)
			dou->dy += 1 - dou->touch;
		else if (portal[anti].dir == EAST)
			dou->dy += dou->touch;
	}
	else
		east_portal(portal, type, anti, dou);
}

void	init_side_portal(t_ray *ray, t_portal *portal, int type, int anti)
{
	t_double	dou;

	dou.dx = portal[anti].x;
	dou.dy = portal[anti].y;
	dou.touch = ray->touch_loc;
	if (portal[type].dir == NORTH)
	{
		if (portal[anti].dir == NORTH)
			dou.dx += 1 - dou.touch;
		else if (portal[anti].dir == SOUTH)
			dou.dx += dou.touch;
		else if (portal[anti].dir == WEST)
			dou.dy += dou.touch;
		else
			dou.dy += 1 - dou.touch;
	}
	else
		south_portal(portal, type, anti, &dou);
	init_side(ray, dou.dx, dou.dy);
}
