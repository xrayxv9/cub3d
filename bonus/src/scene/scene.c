#include "cub3D.h"

void	handle_pause_screen(t_data *data)
{
	mlx_color	color;

	ft_bzero((char *)&color, sizeof(mlx_color));
	mlx_clear_window(data->game, data->window, color);
	mlx_mouse_show(data->game);
	mlx_put_image_to_window(data->game, data->window,
		data->scene.scene[BACKGROUND].texture, 0, 0);
	mlx_put_image_to_window(data->game, data->window,
		data->scene.scene[RESUME].texture, 660, 300);
	mlx_put_image_to_window(data->game, data->window,
		data->scene.scene[SETTINGS].texture, 660, 525);
	mlx_put_image_to_window(data->game, data->window,
		data->scene.scene[GO_TO_MENU].texture, 660, 750);
}

void	handle_scene(t_data *data)
{
	mlx_color	color;

	ft_bzero((char *)&color, sizeof(mlx_color));
	mlx_clear_window(data->game, data->window, color);
	if (!load_background(data->game, &data->scene))
		error_scene(data, 0);
	if (!load_buttons_first_menu(data->game, &data->scene))
		error_scene(data, 1);
	if (!load_buttons_second_menu(data->game, &data->scene))
		error_scene(data, 1);
	if (!load_buttons_third_menu(data->game, &data->scene))
		error_scene(data, 1);
	mlx_put_image_to_window(data->game, data->window,
		data->scene.scene[BACKGROUND].texture, 0, 0);
	if (data->scene.menu == FIRST)
		display_first_scene_buttons(data->window, data->game, &data->scene);
	if (data->scene.menu == SECOND)
		display_second_scene_buttons(data->window, data->game, &data->scene);
	if (data->scene.menu == THIRD)
		display_third_scene_buttons(data->window, data->game, &data->scene,
			data->keyboard_input);
}
