#include "portal_bonus.h"
#include "raycast_bonus.h"
#include "render_bonus.h"
#include <cub3D_bonus.h>

void	show(t_ray *ray, t_data *data, t_double *dou, t_current *current)
{
	mlx_image	image;
	int			dir;

	dir = set_dir(ray);
	image = data->textures[dir].texture;
	while (ray->line_end >= dou->i)
	{
		dou->delta = (dou->i - ray->line_start_tmp) / (float)ray->line_height * 1000;
		image = check_portal_coo(ray, data, image, dir);
		current->color.rgba = mlx_get_image_pixel(data->game, image,
				ray->touch_loc * 1000, dou->delta).rgba;
		if (current->loop)
		{
			if (!(is_color(current->color, 0, 0, 0) && both(data->player.portals)))
				mlx_set_image_pixel(data->game, data->textures[4].texture, dou->x, dou->i, current->color);
		}
		else
			mlx_set_image_pixel(data->game, data->textures[4].texture, dou->x, dou->i, current->color);
		dou->i++;
	}
}

// void	get_exit_coo(double *x_exit, double *y_exit, t_portal *portals, int entry, double touch_loc)
// {
// 	int	exit;
//
// 	exit = entry == 0;
// 	*x_exit = portals[exit].x;
// 	*y_exit = portals[exit].y;
// 	if (portals[exit].dir == SOUTH)
// 		(*y_exit)++;
// 	if (portals[exit].dir == WEST)
// 		(*x_exit)++;
//
// }

void	render_wall_portal(t_data *data, t_ray ray, float angle, int type)
{
	t_double	dou;
	int			dir;
	t_current	current;
	// t_ray		ray_exit;
	// double		x_exit;
	// double		y_exit;
	// double		angle_exit;
	//
	// angle_exit = get_angle_tp(angle, data->player.portals[type].dir, data->player.portals[type == 0].dir);
	// get_exit_coo(&x_exit, &y_exit, data->player.portals, type);
	// init_dda(&ray_exit, x_exit, y_exit, angle_exit);
	// dda(&ray_exit, &data->map);
	reset_angle(data->player.portals, &ray, type, &data->map);
	dir = set_dir(&ray);
	current.ray = &ray;
	dou.i = ray.line_start;
	dou.x = angle;
	calcul_touch(&ray, &data->player, dir, 1);
	current.i = 0;
	current.loop = 0;
	show(&ray, data, &dou, &current);
}
