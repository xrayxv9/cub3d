#include "cub3D.h"
#include "mlx.h"
#include "mlx_extended.h"

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
			mlx_pixel_put(data->game, data->window, j, i, color);
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
			mlx_pixel_put(data->game, data->window, j, i, color);
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
	render_floor(data, color);
	color.r = 0;
	color.g = 255;
	render_celling(data, color);
}

void	render_walls(t_data *data, t_ray *ray, int x)
{
	int	i;

	i = ray->line_start;
	while (ray->line_end >= i)
	{
		mlx_pixel_put(data->game, data->window, x, i,
			(mlx_color){.rgba = 0x0000FFFF});
		i++;
	}
}
