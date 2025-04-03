#include "cub3D.h"

int	check_line(char **map_to_split, char *line)
{
	int	i;

	i = 0;
	if (*map_to_split)
	{
		while ((*map_to_split)[i])
		{
			if ((*map_to_split)[i] != '1')
			i++;
		}
	}
	else if (line)
	{
		while (line[i])
		{
			i++;
		}
	}
	return (1);
}

int	create_map(t_map *map, float *angle, char **map_to_split, int fd)
{
	char	*line;

	check_line(map_to_split, NULL);
	line = get_next_line(fd);
	while (line)
	{
	}
	return (1);
}

int	parsing(t_data *data, char *filename)
{
	t_parse	parse;

	filename = "maps/map.cub";
	data->player.angle = -1;
	ft_bzero((char *)&parse, sizeof(t_parse));
	if (!check_file(filename, &parse))
		parsing_error(&parse, 0);
	if (!create_textures(&parse, data->textures, data->game)
		&& parse.counter == 6)
		parsing_error(&parse, 1);
	if (parse.counter > 6)
		parsing_error(&parse, 2);
	if (parse.counter < 6)
		parsing_error(&parse, 3);
	create_map(&data->map, &data->player.angle, &parse.map_to_split, parse.fd);
	return (1);
}
