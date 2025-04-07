#include "cub3D.h"

int	check_all_map(char *map_to_split, t_map *map)
{
	int	i;
	int	j;

	map->map = ft_split(map_to_split, '\n');
	free(map_to_split);
	if (!check_line(map->map[0])
		|| !check_line(map->map[tab_len(map->map) - 1]))
		return (free_tab(map->map));
	i = 1;
	while (i < tab_len(map->map) - 1)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0')
				if (!check_around(map->map, i, j))
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

void	set_position(int c, double *dir_x, double *dir_y, double *plane_x)
{
	(*plane_x) = 0.66f;
	if (c == 'W')
	{
		(*dir_x) = -1;
		(*dir_y) = 0;
	}
	if (c == 'E')
	{
		(*dir_x) = 1;
		(*dir_y) = 0;
	}
	if (c == 'N')
	{
		(*dir_x) = 0;
		(*dir_y) = -1;
	}
	if (c == 'S')
	{
		(*dir_x) = 0;
		(*dir_y) = 1;
	}
}

int	set_angle_height(t_map *map, t_player *player)
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
				if (player->dir_x != -1 && player->dir_y != -1)
					set_position(map->map[i][j], &player->dir_x,
						&player->dir_y, &player->plane_x);
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

	data->player.dir_x = -1;
	data->player.dir_y = -1;
	ft_bzero((char *)&parse, sizeof(t_parse));
	if (!check_file(filename, &parse))
		parsing_error(&parse, 0);
	if (!create_textures(&parse, data->textures, data->game)
		&& parse.counter == 6)
		parsing_error(&parse, 1);
	if (parse.counter == -1)
		parsing_error(&parse, 8);
	if (parse.counter > 6)
		parsing_error(&parse, 2);
	if (parse.counter < 6)
		parsing_error(&parse, 3);
	if (!parse.map_to_split)
		parsing_error(&parse, 6);
	if (!create_map(&parse.map_to_split, parse.fd))
		parsing_error(&parse, 4);
	if (!check_all_map(parse.map_to_split, &data->map))
		parsing_error(&parse, 5);
	if (!set_angle_height(&data->map, &data->player))
		parsing_error(&parse, 7);
	return (1);
}
