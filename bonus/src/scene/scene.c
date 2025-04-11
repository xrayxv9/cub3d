#include "cub3D.h"

int	handle_scene(t_data *data)
{
	t_menu		menu;
	mlx_image	test;
	int			w;
	int			h;

	menu = FIRST;
	test = mlx_new_image_from_file(data->game, "bonus/textures/background.png", &w, &h);
	mlx_put_image_to_window(data->game, data->window, test, 0, 0);
	return (0);
}
