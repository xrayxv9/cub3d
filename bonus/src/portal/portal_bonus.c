#include <cub3D_bonus.h>

void	portal_send(t_data *data, int type)
{
	t_ray		ray;
	t_portal	*portals;

	(void)type;
	portals = data->player.portals;
	init(&ray, &data->player, data->player.angle);
	line_handle(&ray, &data->player, data->player.angle);
	init_coo(portals, &ray, type, &data->player);
	printf("player co : (%f, %f)\n", data->player.x, data->player.y);
	printf("here is the co after the function: %f\n", portals[type].x);
}
