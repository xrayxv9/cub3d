#include "cub3D.h"

int	check_textures(char **textures)
{
	if (!textures)
		return (0);
	if (!ft_strcmp(textures[0], "\n"))
		return (1);
	if (tab_len(textures) != 2)
		return (0);
	return (1);
}
