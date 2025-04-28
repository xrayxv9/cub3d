#include <cub3D.h>

void	init_portal(t_portal *portals)
{
	portals = malloc(2 * sizeof(t_portal));
	portals[BLUE].x = -1;
	portals[BLUE].y = -1;
	portals[ORANGE].x = -1;
	portals[ORANGE].y = -1;
	portals[BLUE].exist = false;
	portals[ORANGE].exist = false;
}


void	init_coo(t_portal portal, t_ray *ray, t_player *player)
{
	(void)player;

	if (ray->side_x - (int)ray->side_x > 0.2)
		portal.x = ray->side_x + ((ray->line_height / 2)
			* (1 + (ray->side_x - (int)ray->side_x)));
	printf("here is the co : %f\n", portal.x);
}
