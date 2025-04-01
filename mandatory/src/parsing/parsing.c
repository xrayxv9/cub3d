#include "cub3D.h"
#include "libft.h"
#include "mlx.h"
#include "parsing.h"
#include "struct.h"

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

int	load_image(mlx_image image, char *filename, mlx_context game, int *counter)
{
	int		fd;
	int		w;
	int		h;

	if (filename[0] != '.')
		return (1);
	filename[ft_strlen(filename) - 1] = '\0';
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	image = mlx_new_image_from_file(game, filename, &w, &h);
	if (!image)
		return (0);
	(*counter)++;
	return (1);
}

int	check_textures(char **textures)
{
	if (!textures)
		return (0);
	if (tab_len(textures) != 2)
		return (0);
	return (1);
}

int	fill_with_textures(char *line, mlx_image image[6],
		mlx_context game, int *counter)
{
	char	**textures;

	textures = ft_split(line, ' ');
	if (!check_textures(textures))
		return (0);
	if (!ft_strcmp(textures[0], "NO"))
		if (!load_image(image[NORTH], textures[1], game, counter))
			return (0);
	if (!ft_strcmp(textures[0], "SO"))
		if (!load_image(image[SOUTH], textures[1], game, counter))
			return (0);
	if (!ft_strcmp(textures[0], "WE"))
		if (!load_image(image[WEST], textures[1], game, counter))
			return (0);
	if (!ft_strcmp(textures[0], "EA"))
		if (!load_image(image[EAST], textures[1], game, counter))
			return (0);
	if (!ft_strcmp(textures[0], "F"))
		if (!load_image(image[FLOOR], textures[1], game, counter))
			return (0);
	if (!ft_strcmp(textures[0], "C"))
		if (!load_image(image[SKY], textures[1], game, counter))
			return (0);
	free_tab(textures);
	return (1);
}

int	parse_map(t_parse *parse, mlx_image image[6], mlx_context game)
{
	char	*line;
	char	*tmp;

	line = get_next_line(parse->fd);
	while (line)
	{
		fill_with_textures(line, image, game, &parse->counter);
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
	parse_map(&parse, data->textures, data->game);
	printf("%d\n", parse.counter);
	return (1);
}
