#include <cub3D_bonus.h>

t_portal	*init_portal(void)
{
	t_portal	*portals;

	portals = malloc(2 * sizeof(t_portal));
	portals[BLUE].x = -1;
	portals[BLUE].y = -1;
	portals[ORANGE].x = -1;
	portals[ORANGE].y = -1;
	portals[BLUE].exist = false;
	portals[ORANGE].exist = false;
	return (portals);
}

void	init_coo(t_portal *portal, t_ray *ray, int type, t_player *player)
{
	int	dir;

	dir = set_dir(ray);
	calcul_touch(ray, player, dir, 0);
	printf("here is the co at the verry beginning: %f\n", ray->side_x);
	printf("here is the result : %f\n", ray->side_x - (int)ray->side_x);
	if (ray->side_x - (int)ray->side_x < 0.2)
		portal[type].x = ray->side_x * (1 + ((int)ray->side_x - ray->side_x));
}
