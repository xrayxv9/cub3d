#include "render_bonus.h"
#include <cub3D_bonus.h>

t_portal	*init_portal(void)
{
	t_portal	*portals;

	portals = malloc(2 * sizeof(t_portal));
	portals[BLUE].x = -1;
	portals[BLUE].y = -1;
	portals[BLUE].dir = -1;
	portals[BLUE].exist = false;
	portals[ORANGE].x = -1;
	portals[ORANGE].y = -1;
	portals[ORANGE].exist = false;
	portals[ORANGE].dir = -1;
	return (portals);
}

void	init_coo(t_portal *portal, t_ray *ray, int type)
{
	portal[type].dir = set_dir(ray);
	portal[type].x = ray->map_x;
	portal[type].y = ray->map_y;
}
