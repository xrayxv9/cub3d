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

double	get_angle_tp()
{

}


t_ray	init_ray_portal(t_ray *ray, t_portal portal, float angle)
{
	ray->dir_x = cos(radian(angle));
	ray->dir_y = sin(radian(angle));
	ray->map_x = (int)portal.x;
	ray->map_y = (int)portal.y;
	if (ray->dir_x == 0)
		ray->delta_x = exp(30);
	else
		ray->delta_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_y = exp(30);
	else
		ray->delta_y = fabs(1 / ray->dir_y);
	init_step(ray);
	init_side(ray, portal.x, portal.y);
	return (*ray);
}

void	reset_angle(t_portal *portals, t_ray *ray, int type)
{
	double	angle;

	ray->map_x = portals->x;
	ray->map_y = portals->y;
	get_angle_tp(type, ray->angle);
	init_ray_portal(ray, portals, angle);
}

void	init_coo(t_portal *portal, t_ray *ray, int type)
{
	portal[type].dir = set_dir(ray);
	portal[type].x = ray->map_x;
	portal[type].y = ray->map_y;
	portal[type].exist = 1;
}
