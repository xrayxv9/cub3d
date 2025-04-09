#include "cub3D.h"

void	raycasting(t_data *data)
{
	data->player.angle += data->player.move_angle;
	cast_ray(data);
}
