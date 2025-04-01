#include "../../include/cub3D.h"
#include <libft/libft.h>

int	check_line_character(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		i++;
	}
	return (1);
}

int	fill_with_textures(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		i++;
	}
	return (1);
}

int	parse_map(t_parse *parse)
{
	char	*line;
	char	*tmp;

	line = get_next_line(parse->fd);
	while (line)
	{
		tmp = parse->map_to_split;
		parse->map_to_split = ft_strjoin(parse->map_to_split, line);
		free(tmp);
		free(line);
		line = get_next_line(parse->fd);
	}
	return (1);
}

int	parsing(t_data *data, char *filename)
{
	t_parse	parse;

	filename = "maps/map.cub";
	ft_bzero((char *)&parse, sizeof(t_parse));
	if (!check_file(filename, &parse))
		parsing_error(&parse, 0);
	printf("%lu\n", sizeof(mlx_image));
	(void)data;
	return (1);
}
