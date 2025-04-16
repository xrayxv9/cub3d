#include "cub3D.h"

void	mouse_hook(int button, t_data *data)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	mlx_mouse_get_pos(data->game, &x, &y);
	if (data->scene.menu == FIRST && button == 1 && x >= 660 && x <= 1260
		&& y >= 300 && y <= 500)
		data->scene.menu = SECOND;
	else if (data->scene.menu == FIRST && button == 1 && x >= 660 && x <= 1260
		&& y >= 750 && y <= 950)
		mlx_loop_end(data->game);
	else if (data->scene.menu == SECOND && button == 1 && x >= 510 && x <= 1410
		&& y >= 300 && y <= 600)
	{
		data->is_game = GAME;
		cast_ray(data);
	}
	else if (data->scene.menu == SECOND && button == 1 && x >= 10 && x <= 430
		&& y >= 865 && y <= 1005)
		data->scene.menu = FIRST;
}
