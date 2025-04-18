#include "cub3D.h"

static void	mouse_hook4(int button, t_data *data, int x, int y)
{
	if (data->scene.menu == THIRD && button == 1 && x >= 1380 && x <= 1583
		&& y >= 475 && y <= 679)
	{
		if (data->scene.sensi + 0.1 >= 10.00)
			return ;
		data->scene.sensi += 0.10;
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
	if (data->scene.menu == THIRD && button == 1 && x >= 1190 && x <= 1330
		&& y >= 500 && y <= 640)
	{
		if (data->scene.sensi + 0.01 >= 10.00)
			return ;
		data->scene.sensi += 0.01;
	}
	if (data->scene.menu == THIRD && button == 1 && x >= 350 && x <= 553
		&& y >= 475 && y <= 679)
	{
		if (data->scene.sensi - 0.1 <= 0.01)
			return ;
		data->scene.sensi -= 0.10;
	}
	mouse_hook4(button, data, x, y);
}
