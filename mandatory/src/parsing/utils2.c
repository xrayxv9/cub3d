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

int	check_color(char **split_rgba)
{
	int	i;
	int	j;

	i = 0;
	while (split_rgba[i])
	{
		j = 0;
		if (ft_strlen(split_rgba[i]) > 3)
			return (0);
		while (split_rgba[i][j])
		{
			if (!ft_isdigit(split_rgba[i][j]) && split_rgba[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
