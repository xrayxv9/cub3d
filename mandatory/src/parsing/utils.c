#include "cub3D.h"

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

mlx_color	set_colors(char **rgba)
{
	mlx_color	color;

	color.r = ft_atoi(rgba[0]);
	color.g = ft_atoi(rgba[1]);
	color.b = ft_atoi(rgba[2]);
	return (color);
}

int	check_file(char *map_name, t_parse *parse)
{
	if (ft_strlen(map_name) <= 4)
		return (0);
	parse->fd = open(map_name, O_RDONLY);
	if (parse->fd == -1)
		return (0);
	while (ft_strlen(map_name) > 4)
		map_name++;
	if (ft_strcmp(map_name, ".cub"))
		return (0);
	return (1);
}

int	map_is_start(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '0' && line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_character(int c)
{
	return (c == '1' || c == '0');
}
