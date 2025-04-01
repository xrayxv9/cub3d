#include "../../include/cub3D.h"
#include <MacroLibX/includes/mlx.h>

void	background(void *da)
{
	t_data	*data;

	data = (t_data *)da;
	mlx_put_image_to_window(data->game, data->window, data->textures[SKY].texture, 0, 0);
	mlx_put_image_to_window(data->game, data->window, data->textures[FLOOR].texture, 0, 540);
}
