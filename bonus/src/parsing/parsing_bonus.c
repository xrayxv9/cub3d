/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:56:15 by mpendilh          #+#    #+#             */
/*   Updated: 2025/05/30 16:39:02 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	check_all_map(char *map_to_split, t_map *map)
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

static void	set_position(int c, t_player *player, t_vector *vec)
{
	player->x = vec->j + 0.5f;
	player->y = vec->i + 0.5f;
	if (c == 'W')
		player->angle = SPAWN_WEST;
	if (c == 'E')
		player->angle = SPAWN_EAST;
	if (c == 'N')
		player->angle = SPAWN_NORTH;
	if (c == 'S')
		player->angle = SPAWN_SOUTH;
}

static int	set_angle(t_map *map, t_player *player)
{
	t_vector	vec;

	ft_bzero((char *)&vec, sizeof(t_vector));
	map->h = tab_len(map->map);
	while (map->map[vec.i])
	{
		vec.j = 0;
		while (map->map[vec.i][vec.j])
		{
			if (is_position(map->map[vec.i][vec.j]))
			{
				if (player->angle == -1)
					set_position(map->map[vec.i][vec.j],
						player, &vec);
				else
					return (free_tab(map->map));
			}
			(vec.j)++;
		}
		(vec.i)++;
	}
	if (player->angle == -1)
		return (free_tab(map->map));
	return (1);
}

static int	check_player(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (is_position(map.map[i][j]))
				if (!check_around(map.map, i, j))
					return (free_tab(map.map));
			j++;
		}
		i++;
	}
	return (1);
}

int	parsing(t_data *data, char *filename)
{
	t_parse	parse;

	ft_bzero((char *)&parse, sizeof(t_parse));
	if (!check_file(filename, &parse))
		parsing_error(&parse, 0);
	if (!create_textures(&parse, data) && parse.counter == 6)
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
	if (!check_all_map(parse.map_to_split, &data->map)
		|| !check_player(data->map))
		parsing_error(&parse, 5);
	if (!set_angle(&data->map, &data->player))
		parsing_error(&parse, 7);
	return (1);
}
