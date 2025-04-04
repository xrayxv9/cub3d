#include "../../include/cub3D.h"

void	raycasting(void *da)
{
	t_data	*data;
	t_halfs	halfs;

	data = (t_data *)da;
	get_angle(&halfs, data->player);
	cast_ray(data, data->map, halfs); 
}
