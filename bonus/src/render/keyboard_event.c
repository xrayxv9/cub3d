#include "cub3D.h"

static void	player_move4(t_data *data)
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

static void	player_move3(int key, t_data *data)
{
	if (data->keyboard_input == DIRARROW)
	{
		if (key == SDL_SCANCODE_UP || data->player.w_move)
		{
			data->player.w_move = true;
			calculate_speed(&data->player, 0, &data->player.save_angle);
		}
		if (key == SDL_SCANCODE_DOWN || data->player.s_move)
		{
			data->player.s_move = true;
			calculate_speed(&data->player, 180, &data->player.save_angle);
		}
		if (key == SDL_SCANCODE_LEFT || data->player.a_move)
		{
			data->player.a_move = true;
			calculate_speed(&data->player, 90, &data->player.save_angle);
		}
		if (key == SDL_SCANCODE_RIGHT || data->player.d_move)
		{
			data->player.d_move = true;
			calculate_speed(&data->player, 270, &data->player.save_angle);
		}
	}
	player_move4(data);
}

static void	player_move2(int key, t_data *data)
{
	if (data->keyboard_input == ZQSD)
	{
		if (key == SDL_SCANCODE_Z || data->player.w_move)
		{
			data->player.w_move = true;
			calculate_speed(&data->player, 0, &data->player.save_angle);
		}
		if (key == SDL_SCANCODE_S || data->player.s_move)
		{
			data->player.s_move = true;
			calculate_speed(&data->player, 180, &data->player.save_angle);
		}
		if (key == SDL_SCANCODE_Q || data->player.a_move)
		{
			data->player.a_move = true;
			calculate_speed(&data->player, 90, &data->player.save_angle);
		}
		if (key == SDL_SCANCODE_D || data->player.d_move)
		{
			data->player.d_move = true;
			calculate_speed(&data->player, 270, &data->player.save_angle);
		}
	}
	player_move3(key, data);
}

void	player_move(int key, t_data *data)
{
	if (data->keyboard_input == WASD)
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
	}
	player_move2(key, data);
}
