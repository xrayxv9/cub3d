#include "cub3D.h"

int	check_all_map(char **map)
{
	int	i;
	int	j;

	if (!check_line(map[0])
		|| !check_line(map[tab_len(map) - 1]))
		return (free_tab(map));
	i = 1;
	while (i < tab_len(map) - 1)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				if (!check_around(map, i, j))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_position(int c)
{
	return (c == 'W' || c == 'E' || c == 'S' || c == 'N');
}

void	set_position(int c, float *angle)
{
	if (c == 'W')
		(*angle) = SPAWN_WEST;
	if (c == 'E')
		(*angle) = SPAWN_EAST;
	if (c == 'N')
		(*angle) = SPAWN_NORTH;
	if (c == 'S')
		(*angle) = SPAWN_SOUTH;
}

int	set_angle_and_height(t_map *map, float *angle)
{
	int	i;
	int	j;

	i = 0;
	map->h = tab_len(map->map);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_position(map->map[i][j]))
			{
				if (*angle == -1)
					set_position(map->map[i][j], angle);
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	parsing(t_data *data, char *filename)
{
	t_parse	parse;

	filename = "maps/ma.cub";
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
	if (!parse.map_to_split)
		parsing_error(&parse, 6);
	if (!create_map(&parse.map_to_split, parse.fd))
		parsing_error(&parse, 4);
	data->map.map = ft_split(parse.map_to_split, '\n');
	free(parse.map_to_split);
	if (!check_all_map(data->map.map))
		parsing_error(&parse, 5);
	if (!set_angle_and_height(&data->map, &data->player.angle))
		parsing_error(&parse, 7);
	return (1);
}
