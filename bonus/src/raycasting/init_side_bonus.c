#include "raycast_bonus.h"
#include <cub3D_bonus.h>

void	west_portal(t_portal *portal, int exit, t_double *dou)
{
	if (portal[exit].dir == SOUTH)
		dou->dx += dou->touch;
	else if (portal[exit].dir == NORTH)
		dou->dx += 1 - dou->touch;
	else if (portal[exit].dir == EAST)
		dou->dy += dou->touch;
	else if (portal[exit].dir == WEST)
		dou->dy += 1 - dou->touch;
}

void	east_portal(t_portal *portal, int exit, t_double *dou)
{
	if (portal[exit].dir == SOUTH)
		dou->dx +=  dou->touch;
	else if (portal[exit].dir == NORTH)
		dou->dx += 1 - dou->touch;
	else if (portal[exit].dir == EAST)
		dou->dy += dou->touch;
	else if (portal[exit].dir == WEST)
		dou->dy += 1 - dou->touch;
}

void	north_portal(t_portal *portal, int exit, t_double *dou)
{
	if (portal[exit].dir == NORTH)
		dou->dx += dou->touch;
	else if (portal[exit].dir == SOUTH)
		dou->dx += 1 - dou->touch;
	else if (portal[exit].dir == WEST)
		dou->dy += dou->touch;
	else if (portal[exit].dir == EAST)
		dou->dy += 1 - dou->touch;
}
void	south_portal(t_portal *portal, int exit, t_double *dou)
{
	if (portal[exit].dir == SOUTH)
		dou->dx += 1 - dou->touch;
	else if (portal[exit].dir == NORTH)
		dou->dx +=  dou->touch;
	else if (portal[exit].dir == EAST)
		dou->dy += 1 - dou->touch;
	else
		dou->dy += dou->touch;
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
	printf("entry : %d, exit : %d\n", portal[entry].dir, portal[exit].dir);
	if (portal[entry].dir == NORTH)
		north_portal(portal, exit, &dou);
	else if (portal[entry].dir == SOUTH)
		south_portal(portal, exit, &dou);
	else if (portal[entry].dir == EAST)
		east_portal(portal, exit, &dou);
	else if (portal[entry].dir == WEST)
		west_portal(portal, exit, &dou);
	return (dou);
}
