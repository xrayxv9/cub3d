#include "cub3D.h"

int	load_background(mlx_context game, t_sc *scene)
{
	int			w;
	int			h;
	int			fd;

	fd = open("bonus/textures/background.png", O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	scene->background = mlx_new_image_from_file(game,
			"bonus/textures/background.png", &w, &h);
	return (1);
}

int	load_buttons_first_menu(mlx_context game, t_sc *scene)
{
	int			fd;
	int			i;
	char		*tmp;
	char		*tmp2;

	i = 0;
	while (i < FIRST_MENU_BUTTON)
	{
		tmp = ft_strjoin("bonus/textures/main_menu/button", ft_itoa(i + 1));
		tmp2 = ft_strjoin(tmp, ".bmp");
		free(tmp);
		fd = open(tmp2, O_RDONLY);
		if (fd == -1)
		{
			free(tmp2);
			return (0);
		}
		scene->first_scene[i].texture = mlx_new_image_from_file(game,
				tmp2, &scene->first_scene[i].w, &scene->first_scene[i].h);
		free(tmp2);
		close(fd);
		i++;
	}
	return (1);
}

int	load_buttons_second_menu(mlx_context game, t_sc *scene)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (i < SECOND_MENU_BUTTON)
	{
		tmp = ft_strjoin("bonus/textures/play/button", ft_itoa(i + 1));
		tmp2 = ft_strjoin(tmp, ".bmp");
		free(tmp);
		fd = open (tmp2, O_RDONLY);
		if (fd == -1)
		{
			free(tmp2);
			return (0);
		}
		scene->second_scene[i].texture = mlx_new_image_from_file(game,
				tmp2, &scene->second_scene[i].w, &scene->second_scene[i].h);
		free(tmp2);
		close(fd);
		i++;
	}
	return (1);
}
