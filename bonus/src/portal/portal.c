#include "../../include/cub3D.h"

void	portal_send(t_data *data, int type)
{
	t_ray		ray;
	t_portal	*portals;

	(void)type;
	portals = data->player.portals;
	init_portal(portals);
	init(&ray, &data->player, data->player.angle);
	line_handle(&ray, &data->player, data->player.angle);
	init_coo(portals, &ray, &data->player, &data->map);
}
