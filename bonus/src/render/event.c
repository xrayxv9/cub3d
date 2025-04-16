#include "cub3D.h"

static void	player_move2(t_data *data)
{
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

static void	player_move(int key, t_data *data)
{
	if (key == SDL_SCANCODE_W || data->player.w_move)
	{
		data->player.w_move = true;
		calculate_speed(&data->player, 0, &data->player.save_angle);
	}
	if (key == SDL_SCANCODE_S || data->player.s_move)
	{
		data->player.s_move = true;
		calculate_speed(&data->player, 180, &data->player.save_angle);
	}
	if (key == SDL_SCANCODE_A || data->player.a_move)
	{
		data->player.a_move = true;
		calculate_speed(&data->player, 90, &data->player.save_angle);
	}
	if (key == SDL_SCANCODE_D || data->player.d_move)
	{
		data->player.d_move = true;
		calculate_speed(&data->player, 270, &data->player.save_angle);
	}
	player_move2(data);
}

static void	key_down(int key, t_data *data)
{
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(data->game);
	if (key == SDL_SCANCODE_RIGHT)
		data->player.move_angle = 2.5f;
	if (key == SDL_SCANCODE_LEFT)
		data->player.move_angle = -2.5f;
	player_move(key, data);
}

static void	key_up(int key, t_data *data)
{
	if (key == SDL_SCANCODE_RIGHT || key == SDL_SCANCODE_LEFT)
		data->player.move_angle = 0.0f;
	if (key == SDL_SCANCODE_W || key == SDL_SCANCODE_S
		|| key == SDL_SCANCODE_A || key == SDL_SCANCODE_D)
	{
		data->player.speed_y = 0.0f;
		data->player.speed_x = 0.0f;
	}
	if (key == SDL_SCANCODE_W)
		data->player.w_move = false;
	if (key == SDL_SCANCODE_A)
		data->player.a_move = false;
	if (key == SDL_SCANCODE_S)
		data->player.s_move = false;
	if (key == SDL_SCANCODE_D)
		data->player.d_move = false;
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
