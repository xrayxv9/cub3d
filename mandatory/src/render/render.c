#include "cub3D.h"

void	render_walls(t_data *data, t_ray *ray, int x)
{
	int	i;
	mlx_color color;

	color.r = 255;
	color.g = 255;
	color.b = 0;
	i = ray->line_start;
	while (ray->line_end >= i)
	{
		mlx_pixel_put(data->game, data->window, x, i, color);
		i++;
	}
}
