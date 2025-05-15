#include "cub3D_bonus.h"

static void	mouse_hook4(int button, t_data *data, int x, int y)
{
	if (data->scene.menu == THIRD && button == 1 && x >= 1380 && x <= 1583
		&& y >= 475 && y <= 679)
	{
		if (data->scene.sensi + 0.1 >= 10.00)
			return ;
		data->scene.sensi += 0.10;
	}
	else if (data->is_game == GAME && data->pause)
	{
		if (button == 1 && x >= 660 && x <= 1260 && y >= 300 && y <= 500)
			data->pause = !data->pause;
		else if (button == 1 && x >= 660 && x <= 1260 && y >= 525 && y <= 725)
		{
			data->is_game = MENU;
			data->scene.menu = THIRD;
		}
		else if (button == 1 && x >= 660 && x <= 1260 && y >= 750 && y <= 950)
		{
			data->is_game = MENU;
			data->scene.menu = FIRST;
		}
	}
}

void	mouse_hook3(int button, t_data *data, int x, int y)
{
	if (data->scene.menu == THIRD && button == 1 && x >= 590 && x <= 730
		&& y >= 500 && y <= 640)
	{
		if (data->scene.sensi - 0.01 <= 0.01)
			return ;
		data->scene.sensi -= 0.01;
	}
	else if (data->scene.menu == THIRD && button == 1 && x >= 1190 && x <= 1330
		&& y >= 500 && y <= 640)
	{
		if (data->scene.sensi + 0.01 >= 10.00)
			return ;
		data->scene.sensi += 0.01;
	}
	else if (data->scene.menu == THIRD && button == 1 && x >= 350 && x <= 553
		&& y >= 475 && y <= 679)
	{
		if (data->scene.sensi - 0.1 <= 0.01)
			return ;
		data->scene.sensi -= 0.10;
	}
	else
		mouse_hook4(button, data, x, y);
}

void	handle_mouse(t_data *data, int i)
{
	if (!i)
	{
		data->player.save_x = data->player.x;
		data->player.save_y = data->player.y;
		mlx_mouse_get_pos(data->game, &data->player.pos_x, &data->player.pos_y);
		if (data->player.pos_x > WIN_W / 2)
			data->player.move_angle = ((data->player.pos_x - WIN_W / 2) / 4)
				* (data->scene.sensi * data->scene.sensi);
		if (data->player.pos_x < WIN_W / 2)
			data->player.move_angle = - ((( WIN_W / 2 - data->player.pos_x) / 4)
					* (data->scene.sensi * data->scene.sensi));
		if (data->player.pos_x == WIN_W / 2)
			data->player.move_angle = 0;
	}
	if (i)
	{
		mlx_mouse_get_pos(data->game, &data->player.new_x, &data->player.pos_y);
		if (data->player.new_x == data->player.pos_x
			&& data->player.new_x != WIN_W / 2)
			mlx_mouse_move(data->game, data->window, WIN_W / 2, WIN_H / 2);
	}
	mlx_mouse_hide(data->game);
}

void	key_down2(int key, t_data *data)
{
	if (key == SDL_SCANCODE_M)
	{
		data->minimap = !data->minimap;
		if (!data->minimap)
			cast_ray(data);
	}
}
