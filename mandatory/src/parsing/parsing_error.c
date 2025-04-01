#include "cub3D.h"

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
	while (i < 6)
	{
		if (data->textures[i])
			mlx_destroy_image(data->game, data->textures[i]);
		i++;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
