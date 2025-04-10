#include "render.h"
#include "cub3D.h"
#include "mlx.h"

void	render_celling(t_data *data, mlx_color color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WIN_H / 2)
	{
		j = 0;
		while (WIN_W > j)
		{
			mlx_set_image_pixel(data->game,
				data->textures[4].texture, j, i, color);
			j++;
		}
		i++;
	}
}

void	render_floor(t_data *data, mlx_color color)
{
	int	i;
	int	j;

	i = WIN_H / 2;
	while (i < WIN_H)
	{
		j = 0;
		while (WIN_W > j)
		{
			mlx_set_image_pixel(data->game,
				data->textures[4].texture, j, i, color);
			j++;
		}
		i++;
	}
}

void	render_bg(t_data *data)
{
	mlx_color	color;

	color.r = 255;
	color.g = 0;
	color.b = 0;
	color.a = 255;
	render_celling(data, color);
	color.r = 0;
	color.g = 255;
	render_floor(data, color);
}

int	set_dir(t_ray *ray)
{
	if (ray->side == VER && ray->dir_x > 0)
		return (WEST);
	else if (ray->side == VER && ray->dir_x < 0)
		return (EAST);
	else if (ray->side == HOR && ray->dir_y > 0)
		return (NORTH);
	else
		return (SOUTH);
}

void	render_walls(t_data *data, t_ray *ray, float x)
{
	int			i;
	int			dir;
	mlx_color	color;
	mlx_image	image;
	double		delta;

	dir = set_dir(ray);
	image = data->textures[dir].texture;
	i = ray->line_start;
	calcul_touch(ray, &data->player, dir);
	while (ray->line_end >= i)
	{
		delta = (i - ray->line_start_tmp) / (float)ray->line_height * 1902;
		color.rgba = mlx_get_image_pixel(data->game, image,
				ray->touch_loc * 3060, delta).rgba;
		mlx_set_image_pixel(data->game, data->textures[4].texture, x, i, color);
		i++;
	}
}
