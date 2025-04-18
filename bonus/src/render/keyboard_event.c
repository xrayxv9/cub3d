#include "cub3D.h"

void	player_move_arrow(int key, t_data *data)
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

void	player_move_zqsd(int key, t_data *data)
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

void	player_move_wasd(int key, t_data *data)
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
