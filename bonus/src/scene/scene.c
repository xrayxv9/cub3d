#include "cub3D.h"

void	handle_scene(t_data *data)
{
	if (!load_background(data->game, &data->scene))
		error_scene(data, 0);
	if (!load_buttons_first_menu(data->game, &data->scene))
		error_scene(data, 1);
	if (!load_buttons_second_menu(data->game, &data->scene))
		error_scene(data, 1);
	mlx_put_image_to_window(data->game,
		data->window, data->scene.background, 0, 0);
	if (data->scene.menu == SECOND)
		display_second_scene_buttons(data->window, data->game, &data->scene);
	if (data->scene.menu == FIRST)
		display_first_scene_buttons(data->window, data->game, &data->scene);
}
