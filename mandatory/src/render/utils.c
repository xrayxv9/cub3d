#include "cub3D.h"

void	calcul_touch(t_ray *ray, t_player *player, int dir)
{
	if (ray->side == VER)
		ray->touch_loc = player->y + ray->wall_distance * ray->dir_y;
	else
		ray->touch_loc = player->x + ray->wall_distance * ray->dir_x;
	if (dir == NORTH)
		ray->touch_loc = 3060 - ray->touch_loc;
	if (dir == EAST)
		ray->touch_loc = 3060 - ray->touch_loc;
	ray->touch_loc -= (int)ray->touch_loc;
}

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
