#include "../../include/cub3D.h"
#include <MacroLibX/includes/mlx.h>

void	destroy_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->textures[i].texture)
			mlx_destroy_image(data->game, data->textures[i].texture);
		i++;
	}
}
