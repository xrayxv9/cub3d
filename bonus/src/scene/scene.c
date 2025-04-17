#include "cub3D.h"

void	display_third_scene_buttons(mlx_window window, mlx_context game,
		t_sc *scene)
{
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[BACK].texture, 10, 865, 0.7, 0.7, 0);
	mlx_put_image_to_window(game, window,
		scene->scene[CONTROL_LEFT].texture, 440, 500);
}

void	handle_scene(t_data *data)
{
	if (!load_background(data->game, &data->scene))
		error_scene(data, 0);
	if (!load_buttons_first_menu(data->game, &data->scene))
		error_scene(data, 1);
	if (!load_buttons_second_menu(data->game, &data->scene))
		error_scene(data, 1);
	if (!load_buttons_third_menu(data->game, &data->scene))
		error_scene(data, 1);
	if (!load_background(data->game, &data->scene))
		error_scene(data, 1);
	mlx_put_image_to_window(data->game,
		data->window, data->scene.background, 0, 0);
	if (data->scene.menu == FIRST)
		display_first_scene_buttons(data->window, data->game, &data->scene);
	if (data->scene.menu == SECOND)
		display_second_scene_buttons(data->window, data->game, &data->scene);
	if (data->scene.menu == THIRD)
		display_third_scene_buttons(data->window, data->game, &data->scene);
}
