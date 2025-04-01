#include "../../include/cub3D.h"
#include <MacroLibX/includes/mlx.h>

void	parsing_error(t_parse *parse, int i)
{
	close(parse->fd);
	if (!i)
		printf(ERROR FILENAME_ERROR);
	exit(EXIT_FAILURE);
}

void	destroy_textures(t_data *data)
{
	int	i;

	i = 0;
	while (data->textures[i])
	{
		mlx_destroy_image(data->game, data->textures[i]);
		i++;
	}
}
