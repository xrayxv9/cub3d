#include <cub3D_bonus.h>

void	render_portal(t_data *data, t_double dou, mlx_color color, t_ray *ray)
{
	mlx_color black;

	black.r = 0;
	black.g = 0;
	black.b = 0;
	black.a = 255;
	(void)ray;
	if (black.rgba == color.rgba && data->player.portals[BLUE].exist
		&& data->player.portals[ORANGE].exist)
	{
		if (ray->map_x == data->player.portals[ORANGE].x
			&& ray->map_y == data->player.portals[ORANGE].y)
			reset_angle(data->player.portals, ray, ORANGE);
		else 
			reset_angle(data->player.portals, ray, BLUE);
	}
	else 
		mlx_set_image_pixel(data->game, data->textures[4].texture, dou.x, dou.i, color);
}
