#include "cub3D.h"
#include <fcntl.h>

static int	load_floor_sky(mlx_color *color, char *rgba,
		int *counter)
{
	char		**split_rgba;

	split_rgba = ft_split(rgba, ',');
	if (!split_rgba)
		return (0);
	if (tab_len(split_rgba) != 3)
		return (free_tab(split_rgba));
	(*color) = set_colors(split_rgba);
	(*counter)++;
	free_tab(split_rgba);
	return (1);
}

static int	load_image(mlx_image *image, char *filename,
		mlx_context game, int *counter)
{
	int		fd;
	int		w;
	int		h;

	filename[ft_strlen(filename) - 1] = '\0';
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		(*counter) = -1;
		return (0);
	}
	close(fd);
	(*image) = mlx_new_image_from_file(game, filename, &w, &h);
	if (!image)
		return (0);
	(*counter)++;
	return (1);
}

static int	fill_with_textures2(t_data *data, int *counter, char **textures)
{
	if (!ft_strcmp(textures[0], "EA"))
		if (!load_image(&data->textures[EAST].texture,
				textures[1], data->game, counter))
			return (destroy_textures_free_tab(data->textures,
					textures, data->game));
	if (!ft_strcmp(textures[0], "F"))
		if (!load_floor_sky(&data->color[FLOOR],
				textures[1], counter))
			return (destroy_textures_free_tab(data->textures,
					textures, data->game));
	if (!ft_strcmp(textures[0], "C"))
		if (!load_floor_sky(&data->color[SKY],
				textures[1], counter))
			return (destroy_textures_free_tab(data->textures,
					textures, data->game));
	return (1);
}

static int	fill_with_textures(char *line, t_data *data, int *counter)
{
	char	**textures;

	textures = ft_split(line, ' ');
	if (!check_textures(textures))
		return (destroy_textures_free_tab(data->textures,
				textures, data->game));
	if (!ft_strcmp(textures[0], "NO"))
		if (!load_image(&data->textures[NORTH].texture,
				textures[1], data->game, counter))
			return (destroy_textures_free_tab(data->textures,
					textures, data->game));
	if (!ft_strcmp(textures[0], "SO"))
		if (!load_image(&data->textures[SOUTH].texture,
				textures[1], data->game, counter))
			return (destroy_textures_free_tab(data->textures,
					textures, data->game));
	if (!ft_strcmp(textures[0], "WE"))
		if (!load_image(&data->textures[WEST].texture,
				textures[1], data->game, counter))
			return (destroy_textures_free_tab(data->textures,
					textures, data->game));
	if (!fill_with_textures2(data, counter, textures))
		return (0);
	free_tab(textures);
	return (1);
}

int	create_textures(t_parse *parse, t_data *data)
{
	char	*line;
	int		fd;

	fd = open("bonus/textures/font/font.ttf", O_RDONLY);
	if (fd == -1)
	{
		parse->counter = 6;
		return (0);
	}
	close(fd);
	line = get_next_line(parse->fd);
	while (line && !map_is_start(line))
	{
		if (!fill_with_textures(line, data, &parse->counter))
			return (free_gnl(parse->fd, line));
		free(line);
		line = get_next_line(parse->fd);
	}
	parse->map_to_split = line;
	return (1);
}
