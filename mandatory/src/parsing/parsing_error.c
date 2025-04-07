#include "cub3D.h"

void	parsing_error(t_parse *parse, int i)
{
	close(parse->fd);
	ft_putstr_fd(ERROR, 2);
	if (!i)
		ft_putstr_fd(FILENAME_ERROR, 2);
	if (i == 1)
		ft_putstr_fd(FD_ERROR, 2);
	if (i == 2)
		ft_putstr_fd(MORE_TEXTURES, 2);
	if (i == 3)
		ft_putstr_fd(LESS_TEXTURES, 2);
	if (i == 4)
		ft_putstr_fd(MAP_CHAR_ERROR, 2);
	if (i == 5)
		ft_putstr_fd(CLOSE_MAP_ERROR, 2);
	if (i == 6)
		ft_putstr_fd(NO_MAP_ERROR, 2);
	if (i == 7)
		ft_putstr_fd(MULTI_SPAWN_ERROR, 2);
	if (i == 8)
		ft_putstr_fd(PERM_ERROR, 2);
	exit(EXIT_FAILURE);
}

int	destroy_textures_free_tab(mlx_image textures[6],
		char **tab, mlx_context game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (textures[i])
			mlx_destroy_image(game, textures[i]);
		i++;
	}
	return (free_tab(tab));
}

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	free_gnl(int fd, char *line)
{
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
