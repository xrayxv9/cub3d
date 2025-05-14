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

double	get_angle_tp(float angle, int dir_portal, int dir_tp)
{
	int	i;
	int	j;
	
	i = dir_portal;
	j = 0;
	while (i != dir_tp)
	{
		if (i == 3)
			i = -1;
		i++;
		j++;
	}
	if (j == 0)
		return (180 + angle);
	else if (j == 1)
		return (90 - angle);
	else if (j == 2)
		return (angle);
	else
		return (90 + angle);
}

t_ray	init_ray_portal(t_ray *ray, t_portal *portal, float angle, int type)
{
	int	anti;

	anti = type == 0;
	ray->dir_x = cos(radian(angle));
	ray->dir_y = sin(radian(angle));
	if (ray->dir_x == 0)
		ray->delta_x = exp(30);
	else
		ray->delta_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_y = exp(30);
	else
		ray->delta_y = fabs(1 / ray->dir_y);
	init_step(ray);
	init_side_portal(ray, portal, type, anti);
	return (*ray);
}

void	reset_angle(t_portal *portals, t_ray *ray, int type, t_map *map)
{
	int		anti;
	double	ra;

	ra = ray->wall_distance;
	anti = type == 0;
	ray->map_x = portals[anti].x;
	ray->map_y = portals[anti].y;
	if (portals[anti].dir == SOUTH)
		ray->map_y++;
	if (portals[anti].dir == WEST)
		ray->map_x++;
	ray->angle = get_angle_tp(ray->angle, portals[type].dir, portals[anti].dir);
	init_ray_portal(ray, portals, ray->angle, type);
	main_while(ray, map);
	line_handle_portal(ray, portals[type], ray->angle, ra);
}

void	init_coo(t_portal *portal, t_ray *ray, int type)
{
	portal[type].dir = set_dir(ray);
	portal[type].x = ray->map_x;
	portal[type].y = ray->map_y;
	portal[type].exist = 1;
}
