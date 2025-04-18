#include "cub3D.h"

static void	key_up_zqsd(int key, t_data *data)
{
	if (key == SDL_SCANCODE_Z || key == SDL_SCANCODE_S
		|| key == SDL_SCANCODE_Q || key == SDL_SCANCODE_D)
	{
		data->player.speed_y = 0.0f;
		data->player.speed_x = 0.0f;
	}
	if (data->keyboard_input == ZQSD)
	{
		if (key == SDL_SCANCODE_Z)
			data->player.w_move = false;
		if (key == SDL_SCANCODE_Q)
			data->player.a_move = false;
		if (key == SDL_SCANCODE_S)
			data->player.s_move = false;
		if (key == SDL_SCANCODE_D)
			data->player.d_move = false;
	}
}

static void	key_up_arrow(int key, t_data *data)
{
	if (key == SDL_SCANCODE_UP || key == SDL_SCANCODE_DOWN
		|| key == SDL_SCANCODE_LEFT || key == SDL_SCANCODE_RIGHT)
	{
		data->player.speed_y = 0.0f;
		data->player.speed_x = 0.0f;
	}
	if (key == SDL_SCANCODE_UP)
		data->player.w_move = false;
	if (key == SDL_SCANCODE_LEFT)
		data->player.a_move = false;
	if (key == SDL_SCANCODE_DOWN)
		data->player.s_move = false;
	if (key == SDL_SCANCODE_RIGHT)
		data->player.d_move = false;
}

static void	key_up(int key, t_data *data)
{
	if (data->keyboard_input == WASD)
		key_up_wasd(key, data);
	if (data->keyboard_input == ZQSD)
		key_up_zqsd(key, data);
	if (data->keyboard_input == DIRARROW)
		key_up_arrow(key, data);
}

static void	key_down(int key, t_data *data)
{
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(data->game);
	if (data->keyboard_input == WASD)
		player_move_wasd(key, data);
	if (data->keyboard_input == ZQSD)
		player_move_zqsd(key, data);
	if (data->keyboard_input == DIRARROW)
		player_move_arrow(key, data);
	if (data->player.w_move && data->player.d_move)
		calculate_second_speed(&data->player,
			360, 270, &data->player.save_angle);
	if (data->player.w_move && data->player.a_move)
		calculate_second_speed(&data->player,
			0, 90, &data->player.save_angle);
	if (data->player.s_move && data->player.a_move)
		calculate_second_speed(&data->player,
			180, 90, &data->player.save_angle);
	if (data->player.s_move && data->player.d_move)
		calculate_second_speed(&data->player,
			180, 270, &data->player.save_angle);
}

void	event(t_data *data)
{
	mlx_on_event(data->game, data->window, MLX_KEYDOWN,
		(void *)key_down, data);
	mlx_on_event(data->game, data->window, MLX_WINDOW_EVENT,
		(void *)window_hook, data);
	mlx_on_event(data->game, data->window, MLX_KEYUP, (void *)key_up, data);
	mlx_on_event(data->game, data->window, MLX_MOUSEDOWN,
		(void *)mouse_hook, data);
}
