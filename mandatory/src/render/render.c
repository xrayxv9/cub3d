#include "../../include/cub3D.h"
#include <MacroLibX/includes/mlx.h>
#include <mandatory/include/raycast.h>
#include <math.h>

void	render_walls(t_data *data, t_ray *ray)
{
	int	i;
	// int j = 0;
	mlx_color color;

	color.r = 255;
	color.g = 255;
	color.b = 0;
	
	i = ray->line_start;
	printf("here is the line : %d\n", ray->line_height);
	while (ray->line_end >= i)
	{
		mlx_pixel_put(data->game, data->window, ray->line_start, i, color);
		i++;
		// j++;
	}
}
