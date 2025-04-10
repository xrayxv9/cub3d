#include "cub3D.h"

void	calculate_speed(t_player *player, double pos_angle,
		double *save_angle)
{
	player->speed_x = cos(radian(player->angle - pos_angle)) * 0.1;
	player->speed_y = sin(radian(player->angle - pos_angle)) * 0.1;
	*save_angle = pos_angle;
}

void	calculate_second_speed(t_player *player, double first_pos_angle,
		double second_pos_angle, double *save_angle)
{
	player->speed_x = cos(radian(player->angle
				- first_pos_angle - second_pos_angle)) * 0.1;
	player->speed_y = sin(radian(player->angle
				- first_pos_angle - second_pos_angle)) * 0.1;
	*save_angle = (first_pos_angle - second_pos_angle) / 2 + second_pos_angle;
}

void	window_hook(int event, t_data *data)
{
	if (event == 0)
		mlx_loop_end(data->game);
}
