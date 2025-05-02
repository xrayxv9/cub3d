#include "mlx.h"
#include "render_bonus.h"
#include <cub3D_bonus.h>

int	is_black(mlx_color color)
{
	mlx_color black;

	black.r = 0;
	black.g = 0;
	black.b = 0;
	black.a = 255;
	if (color.rgba == black.rgba)
		return (1);
	return (0);
}


void	render_walls_portal(t_data *data, t_ray *ray, float x)
{
	t_double	dou;
	int			dir;
	mlx_color	color;
	mlx_image	image;
	double		delta;

	dir = set_dir(ray);
	image = data->textures[dir].texture;
	dou.i = ray->line_start;
	dou.x = x;
	delta = (dou.i - ray->line_start_tmp) / (float)ray->line_height * 1000;
	calcul_touch(ray, &data->player, dir, 1);
	color.rgba = mlx_get_image_pixel(data->game, image,
		ray->touch_loc * 1000, delta).rgba;
	while (is_black(color))
	{
		delta = (dou.i - ray->line_start_tmp) / (float)ray->line_height * 1000;
		image = check_portal_coo(ray, data, image, dir);
		color.rgba = mlx_get_image_pixel(data->game, image,
				ray->touch_loc * 1000, delta).rgba;
		mlx_set_image_pixel(data->game, data->textures[4].texture, dou.x, dou.i, color);
		dou.i++;
	}
}

void	render_portal(t_data *data, t_double *dou, mlx_color color, t_ray *ray)
{
	if (is_black(color) && ray->tp < 1 && data->player.portals[BLUE].exist && data->player.portals[ORANGE].exist)
	{
		ray->tp++;
		if (ray->map_x == data->player.portals[ORANGE].x
				&& ray->map_y == data->player.portals[ORANGE].y)
			reset_angle(data->player.portals, ray, ORANGE, &data->map);
		else 
			reset_angle(data->player.portals, ray, BLUE, &data->map);
		printf("coo blue : (%d, %d), coo orange : (%d, %d), ray coo : (%d, %d)\n", data->player.portals[BLUE].x, data->player.portals[BLUE].y, data->player.portals[ORANGE].x, data->player.portals[ORANGE].y, ray->map_x, ray->map_y);
		render_walls_portal(data, ray, ray->angle);
	}
	else
		mlx_set_image_pixel(data->game, data->textures[4].texture, dou->x, dou->i, color);
}
