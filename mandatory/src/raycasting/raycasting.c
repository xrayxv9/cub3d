#include "../../include/cub3D.h"
#include <mandatory/include/struct.h>

void	raycasting(void *da)
{
	t_data	*data;
	t_halfs	halfs;

	data = (t_data *)da;
	get_angle(&halfs, data->player);
	cast_ray(data->player, data->map, halfs); 
}
