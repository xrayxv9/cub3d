#include "struct_bonus.h"
#include <cub3D_bonus.h>

void	west_portal(t_portal *portal, int exit, t_save_info *save)
{
	if (portal[exit].dir == SOUTH)
		save->dx += save->touch;
	else if (portal[exit].dir == NORTH)
		save->dx += 1 - save->touch;
	else if (portal[exit].dir == EAST)
		save->dy += save->touch;
	else if (portal[exit].dir == WEST)
		save->dy += 1 - save->touch;
}

void	east_portal(t_portal *portal, int exit, t_save_info *save)
{
	if (portal[exit].dir == SOUTH)
		save->dx += save->touch;
	else if (portal[exit].dir == NORTH)
		save->dx += 1 - save->touch;
	else if (portal[exit].dir == EAST)
		save->dy += save->touch;
	else if (portal[exit].dir == WEST)
		save->dy += 1 - save->touch;
}

void	north_portal(t_portal *portal, int exit, t_save_info *save)
{
	if (portal[exit].dir == NORTH)
		save->dx += save->touch;
	else if (portal[exit].dir == SOUTH)
		save->dx += 1 - save->touch;
	else if (portal[exit].dir == WEST)
		save->dy += save->touch;
	else if (portal[exit].dir == EAST)
		save->dy += 1 - save->touch;
}

void	south_portal(t_portal *portal, int exit, t_save_info *save)
{
	if (portal[exit].dir == SOUTH)
		save->dx += 1 - save->touch;
	else if (portal[exit].dir == NORTH)
		save->dx += save->touch;
	else if (portal[exit].dir == EAST)
		save->dy += 1 - save->touch;
	else
		save->dy += save->touch;
}

t_save_info	init_side_portal(double touch_loc, t_portal *portal,
					int entry, int exit)
{
	t_save_info	save;

	save.dx = portal[exit].x;
	save.dy = portal[exit].y;
	if (portal[exit].dir == SOUTH)
		save.dy++;
	if (portal[exit].dir == WEST)
		save.dx++;
	save.touch = touch_loc;
	if (portal[entry].dir == NORTH)
		north_portal(portal, exit, &save);
	else if (portal[entry].dir == SOUTH)
		south_portal(portal, exit, &save);
	else if (portal[entry].dir == EAST)
		east_portal(portal, exit, &save);
	else if (portal[entry].dir == WEST)
		west_portal(portal, exit, &save);
	return (save);
}
