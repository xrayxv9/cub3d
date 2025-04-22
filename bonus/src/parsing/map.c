#include "cub3D.h"

static int	check_line_character(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_map_character(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_line(char *line)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (line[i])
	{
		if (line[i] == '0')
			return (0);
		if (line[i] == '1')
			counter++;
		i++;
	}
	if (!counter)
		return (0);
	return (1);
}

int	is_second_map_character(int c)
{
	return (c != '1' && c != '0' && c != 'W' && c != 'E' && c != 'N'
		&& c != 'S');
}

int	check_around(char **map, int i, int j)
{
	if (is_second_map_character(map[i][j + 1])
		|| is_second_map_character(map[i][j - 1])
		|| is_second_map_character(map[i + 1][j])
		|| is_second_map_character(map[i - 1][j]))
		return (0);
	return (1);
}

int	create_map(char **map_to_split, int fd)
{
	char	*line;
	char	*tmp;

	check_line_character(*map_to_split);
	line = get_next_line(fd);
	while (line)
	{
		if (!check_line_character(line))
			return (free_gnl(fd, line));
		tmp = ft_strjoin((*map_to_split), line);
		free(line);
		free(*map_to_split);
		*map_to_split = tmp;
		line = get_next_line(fd);
	}
	return (1);
}
