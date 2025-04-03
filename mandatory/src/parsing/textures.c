#include "cub3D.h"
#include "gnl.h"

static int	check_textures(char **textures)
{
	if (!textures)
		return (0);
	if (!ft_strcmp(textures[0], "\n"))
		return (1);
	if (tab_len(textures) != 2)
		return (0);
	return (1);
}

static int	load_floor_and_sky(mlx_image image, char *rgba,
		mlx_context game, int *counter)
{
	int			y;
	int			x;
	char		**split_rgba;
	mlx_color	color;

	y = 0;
	split_rgba = ft_split(rgba, ',');
	if (!split_rgba)
		return (0);
	if (tab_len(split_rgba) != 3)
		return (0);
	color = set_colors(split_rgba);
	image = mlx_new_image(game, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			mlx_set_image_pixel(game, image, x, y, color);
			x++;
		}
		y++;
	}
	(*counter)++;
	return (1);
}

static int	load_image(mlx_image image, char *filename,
		mlx_context game, int *counter)
{
	int		fd;
	int		w;
	int		h;

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

static int	fill_with_textures(char *line, mlx_image image[6],
		mlx_context game, int *counter)
{
	char	**textures;

	textures = ft_split(line, ' ');
	if (!check_textures(textures))
		return (destroy_textures_free_tab(image, textures, game));
	if (!ft_strcmp(textures[0], "NO"))
		if (!load_image(image[NORTH], textures[1], game, counter))
			return (destroy_textures_free_tab(image, textures, game));
	if (!ft_strcmp(textures[0], "SO"))
		if (!load_image(image[SOUTH], textures[1], game, counter))
			return (destroy_textures_free_tab(image, textures, game));
	if (!ft_strcmp(textures[0], "WE"))
		if (!load_image(image[WEST], textures[1], game, counter))
			return (destroy_textures_free_tab(image, textures, game));
	if (!ft_strcmp(textures[0], "EA"))
		if (!load_image(image[EAST], textures[1], game, counter))
			return (destroy_textures_free_tab(image, textures, game));
	if (!ft_strcmp(textures[0], "F"))
		if (!load_floor_and_sky(image[FLOOR], textures[1], game, counter))
			return (destroy_textures_free_tab(image, textures, game));
	if (!ft_strcmp(textures[0], "C"))
		if (!load_floor_and_sky(image[SKY], textures[1], game, counter))
			return (destroy_textures_free_tab(image, textures, game));
	free_tab(textures);
	return (1);
}

int	create_textures(t_parse *parse, mlx_image image[6],
		mlx_context game)
{
	char	*line;

	line = get_next_line(parse->fd);
	while (line && !map_is_start(line))
	{
		if (!fill_with_textures(line, image, game, &parse->counter))
			return (free_gnl(parse->fd, line));
		free(line);
		line = get_next_line(parse->fd);
	}
	parse->map_to_split = line;
	return (1);
}
