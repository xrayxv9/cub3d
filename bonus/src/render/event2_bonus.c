#include "cub3D_bonus.h"
#include "scene_bonus.h"

static void	mouse_hook2(int button, t_data *data, int x, int y)
{
	if (data->scene.menu == THIRD && button == 1 && x >= 590 && x <= 730
		&& y >= 300 && y <= 440)
	{
		if (data->keyboard_input == WASD)
			data->keyboard_input = DIRARROW;
		else if (data->keyboard_input == ZQSD)
			data->keyboard_input = WASD;
		else if (data->keyboard_input == DIRARROW)
			data->keyboard_input = ZQSD;
	}
	if (data->scene.menu == THIRD && button == 1 && x >= 1190 && x <= 1330
		&& y >= 300 && y <= 440)
	{
		if (data->keyboard_input == WASD)
			data->keyboard_input = ZQSD;
		else if (data->keyboard_input == ZQSD)
			data->keyboard_input = DIRARROW;
		else if (data->keyboard_input == DIRARROW)
			data->keyboard_input = WASD;
	}
	mouse_hook3(button, data, x, y);
}

static void	handle_back_button(t_data *data)
{
	if (data->pause)
		data->is_game = GAME;
	else
		data->scene.menu = FIRST;
}

void	mouse_hook(int button, t_data *data)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	get_mous_and_portal(data, button, &x, &y);
	if (data->scene.menu == FIRST && button == 1 && x >= 660 && x <= 1260
		&& y >= 300 && y <= 500)
		data->scene.menu = SECOND;
	else if (data->scene.menu == FIRST && button == 1 && x >= 660 && x <= 1260
		&& y >= 525 && y <= 725)
		data->scene.menu = THIRD;
	else if (data->scene.menu == FIRST && button == 1 && x >= 660 && x <= 1260
		&& y >= 750 && y <= 950)
		mlx_loop_end(data->game);
	else if (data->scene.menu == SECOND && button == 1 && x >= 510 && x <= 1410
		&& y >= 300 && y <= 600)
	{
		data->is_game = GAME;
		cast_ray(data);
	}
	else if ((data->scene.menu == SECOND || data->scene.menu == THIRD)
		&& button == 1 && x >= 10 && x <= 430 && y >= 865 && y <= 1005)
		handle_back_button(data);
	mouse_hook2(button, data, x, y);
}

void	key_up_wasd(int key, t_data *data)
{
	if (key == SDL_SCANCODE_W || key == SDL_SCANCODE_S
		|| key == SDL_SCANCODE_A || key == SDL_SCANCODE_D)
	{
		data->player.speed_y = 0.0f;
		data->player.speed_x = 0.0f;
	}
	if (data->keyboard_input == WASD)
	{
		if (key == SDL_SCANCODE_W)
			data->player.w_move = false;
		if (key == SDL_SCANCODE_A)
			data->player.a_move = false;
		if (key == SDL_SCANCODE_S)
			data->player.s_move = false;
		if (key == SDL_SCANCODE_D)
			data->player.d_move = false;
	}
}

void	handle_player_move(t_player *player)
{
	if (player->w_move && !player->a_move && !player->d_move)
		calculate_speed(player, 0, &player->save_angle);
	else if (player->s_move && !player->a_move && !player->d_move)
		calculate_speed(player, 180, &player->save_angle);
	else if (player->a_move && !player->s_move && !player->w_move)
		calculate_speed(player, 90, &player->save_angle);
	else if (player->d_move && !player->s_move && !player->w_move)
		calculate_speed(player, 270, &player->save_angle);
}
