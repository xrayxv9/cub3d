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
				data->textures[6].texture, j, i, color);
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
				data->textures[6].texture, j, i, color);
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

int	set_color(t_ray *ray)
{
	if (ray->side == VER && ray->dir_x < 0)
		return (NORTH);
	else if (ray->side == VER && ray->dir_x > 0)
		return (SOUTH);
	else if (ray->side == HOR && ray->side_y < 0)
		return (WEST);
	else
		return (EAST);
}

void	render_walls(t_data *data, t_ray *ray, int x)
{
	int			i;
	mlx_color	color;
	int			dir;

	i = ray->line_start;
	dir = set_color(ray);
	printf("%p\n", data->textures[dir].texture);
	while (ray->line_end >= i)
	{
		color.rgba = mlx_get_image_pixel(data->game, data->textures[dir].texture, x, i).rgba;
		mlx_set_image_pixel(data->game, data->textures[6].texture, x, i, color);
		i++;
	}
}
