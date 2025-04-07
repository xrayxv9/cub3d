#include "../../include/cub3D.h"

void	raycasting(void *da)
{
	t_data	*data;

	data = (t_data *)da;
	cast_ray(data, &data->map);
}
