#include "render_bonus.h"
#include "struct_bonus.h"
#include <cub3D_bonus.h>

void	portal_send(t_data *data, int type)
{
	t_ray		ray;
	t_portal	*portals;

	portals = data->player.portals;
	init(&ray, &data->player, data->player.angle);
	main_while(&ray, &data->map);
	line_handle(&ray, &data->player, data->player.angle);
	init_coo(portals, &ray, type);
}

mlx_image	check_portal_coo(t_ray *ray, t_data *data, mlx_image image, int dir)
{
	t_portal *portals;

	portals = data->player.portals;
	if (ray->map_x == portals[BLUE].x && ray->map_y == portals[BLUE].y
		&& dir == portals[BLUE].dir)
		return (data->portal_images[BLUE_IMAGE]);
	else if (ray->map_x == portals[ORANGE].x && ray->map_y == portals[ORANGE].y
		&& dir == portals[ORANGE].dir)
		return (data->portal_images[ORANGE_IMAGE]);
	return (image);
}
