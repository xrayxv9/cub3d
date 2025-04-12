#include "cub3D.h"

static int	load_background(mlx_window window, mlx_context game, t_sc *scene)
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
	mlx_put_image_to_window(game, window, scene->background, 0, 0);
	return (1);
}

static void	load_buttons_first_menu(mlx_window window, mlx_context game, t_sc *scene)
{
	int	i;

	i = 0;
}

void	error_scene(t_data *data)
{

}

int	handle_scene(t_data *data)
{
	t_menu		menu;

	menu = FIRST;
	if (!load_background(data->window, data->game, &data->scene))
		error_scene(data);
	if (menu == FIRST)
		load_buttons_first_menu(data->window, data->game, &data->scene);
	return (0);
}
