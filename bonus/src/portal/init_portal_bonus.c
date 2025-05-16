#include "raycast_bonus.h"
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
	int	j;

	j = (dir_tp - dir_portal + 4) % 4;
	if (j == 0)
		return (180 + angle);
	else if (j == 1)
		return (angle + 90);
	else if (j == 2)
		return (angle);
	else
		return (angle - 90);
}

t_save_info	init_ray_portal(t_ray *ray, t_portal *portal, float angle, int type)
{
	int			anti;
	t_save_info	save;

	anti = !type;
	ray->dir_x = cos(radian(angle));
	ray->dir_y = sin(radian(angle));
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
	init_step(ray);
	save = init_side_portal(ray->touch_loc, portal, type, anti);
	init_side(ray, save.dx, save.dy);
	return (save);
}

t_save_info	reset_angle(t_portal *portals, t_ray *ray, int type, t_map *map)
{
	int			anti;
	double		ra;
	t_save_info	save;

	ra = ray->wall_distance;
	anti = type == 0;
	ray->map_x = portals[anti].x;
	ray->map_y = portals[anti].y;
	if (portals[anti].dir == SOUTH)
		ray->map_y++;
	if (portals[anti].dir == NORTH)
		ray->map_y--;
	if (portals[anti].dir == WEST)
		ray->map_x++;
	if (portals[anti].dir == EAST)
		ray->map_x--;
	ray->angle = get_angle_tp(ray->angle, portals[type].dir, portals[anti].dir);
	save = init_ray_portal(ray, portals, ray->angle, type);
	dda(ray, map);
	line_handle_portal(ray, ra);
	return (save);
}

void	init_coo(t_portal *portal, t_ray *ray, int type)
{
	portal[type].dir = set_dir(ray);
	portal[type].x = ray->map_x;
	portal[type].y = ray->map_y;
	portal[type].exist = 1;
}
