#include "raycast_bonus.h"
#include <cub3D_bonus.h>

void	east_portal(t_portal *portal, int entry, int exit, t_double *dou)
{
	if (portal[entry].dir == WEST)
	{
		if (portal[exit].dir == SOUTH)
			dou->dx += 1 - dou->touch;
		else if (portal[exit].dir == NORTH)
			dou->dx += dou->touch;
		else if (portal[exit].dir == EAST)
			dou->dy += 1 - dou->touch;
		else if (portal[exit].dir == WEST)
			dou->dy += dou->touch;
	}
}

void	south_portal(t_portal *portal, int entry, int exit, t_double *dou)
{
	if (entry == NORTH)
	{
		if (portal[entry].dir == NORTH)
			dou->dx += 1 - dou->touch;
		else if (portal[exit].dir == SOUTH)
			dou->dx += dou->touch;
		else if (portal[exit].dir == WEST)
			dou->dy += dou->touch;
		else if (portal[exit].dir == EAST)
			dou->dy += 1 - dou->touch;
	}
	else if (portal[entry].dir == EAST)
	{
		if (portal[exit].dir == SOUTH)
			dou->dx += dou->touch;
		else if (portal[exit].dir == NORTH)
			dou->dx += 1 - dou->touch;
		else if (portal[exit].dir == EAST)
			dou->dy += 1 - dou->touch;
		else if (portal[exit].dir == WEST)
			dou->dy += dou->touch;
	}
	else
		east_portal(portal, entry, exit, dou);
}

t_double	init_side_portal(double touch_loc, t_portal *portal, int entry, int exit)
{
	t_double	dou;

	dou.dx = portal[exit].x;
	dou.dy = portal[exit].y;
	if (portal[exit].dir == SOUTH)
		dou.dy++;
	if (portal[exit].dir == WEST)
		dou.dx++;
	dou.touch = touch_loc;
	if (portal[entry].dir == SOUTH)
	{
		if (portal[exit].dir == SOUTH)
			dou.dx += 1 - dou.touch;
		else if (portal[exit].dir == NORTH)
			dou.dx += dou.touch;
		else if (portal[exit].dir == EAST)
			dou.dy += dou.touch;
		else
			dou.dy += 1 - dou.touch;
	}
	else
		south_portal(portal, entry, exit, &dou);
	return (dou);
}
