#include "raycast_bonus.h"
#include <cub3D_bonus.h>

void	east_portal(t_portal *portal, int type, int anti, t_double *dou)
{
	if (portal[type].dir == WEST)
	{
		if (portal[anti].dir == SOUTH)
			dou->dx += 1 - dou->touch;
		else if (portal[anti].dir == NORTH)
			dou->dx = dou->touch;
		else if (portal[anti].dir == EAST)
			dou->dy += 1 - dou->touch;
		else if (portal[anti].dir == WEST)
			dou->dy += dou->touch;
	}
}

void	south_portal(t_portal *portal, int type, int anti, t_double *dou)
{
	if (type == NORTH)
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
	else if (portal[type].dir == EAST)
	{
		if (portal[anti].dir == SOUTH)
			dou->dx += 1 - dou->touch;
		else if (portal[anti].dir == NORTH)
			dou->dx = dou->touch;
		else if (portal[anti].dir == EAST)
			dou->dy += 1 - dou->touch;
		else if (portal[anti].dir == WEST)
			dou->dy += dou->touch;
	}
	else
		east_portal(portal, type, anti, dou);
}

t_double	init_side_portal(double touch_loc, t_portal *portal, int type, int anti)
{
	t_double	dou;

	dou.dx = portal[anti].x;
	dou.dy = portal[anti].y;
	if (portal[anti].dir == SOUTH)
		dou.dy++;
	if (portal[anti].dir == WEST)
		dou.dx++;
	dou.touch = touch_loc;
	if (portal[type].dir == SOUTH)
	{
		if (portal[anti].dir == SOUTH)
			dou.dx += 1 - dou.touch;
		else if (portal[anti].dir == NORTH)
			dou.dx += dou.touch;
		else if (portal[anti].dir == EAST)
			dou.dy += dou.touch;
		else
			dou.dy += 1 - dou.touch;
	}
	else
		south_portal(portal, type, anti, &dou);
	return (dou);
}
