#include "mlx.h"
#include "portal_bonus.h"
#include "render_bonus.h"
#include <cub3D_bonus.h>

int	is_color(mlx_color color, unsigned int r, unsigned int g, unsigned int b)
{
	mlx_color black;

	black.r = r;
	black.g = g;
	black.b = b;
	black.a = 255;
	if (color.rgba == black.rgba)
		return (1);
	return (0);
}

int	portal_find(t_portal *portal, int x, int y)
{
	if (portal[BLUE].x == x && portal[BLUE].y == y)
		return (BLUE);
	else if (portal[ORANGE].x == x && portal[ORANGE].y == y)
			return (ORANGE);
	else
		return (-1);
}

void	get_color(t_ray *ray, t_data *data, t_portal *portals, mlx_color *colors)
{
	t_ray		ra;
	t_double	dou;
	int			dir;
	mlx_image	image;
	mlx_color	color;

	reset_angle(portals, ray, portal_find(portals, ray->map_x, ray->map_y),
				  &data->map);
	dir = set_dir(ray);
	image = data->textures[dir].texture;
	dou.i = ra.line_start;
	dou.x = ra.angle;
	calcul_touch(&ra, &data->player, dir, 1);
	while (ra.line_end >= dou.i)
	{
		dou.delta = (dou.i - ra.line_start_tmp) / (float)ra.line_height * 1000;
		image = check_portal_coo(&ra, data, image, dir);
		color.rgba = mlx_get_image_pixel(data->game, image,
				ra.touch_loc * 1000, dou.delta).rgba;
		colors[(int)dou.delta] = color;
		dou.i++;
	}
}

mlx_color	render_portal(t_portal *portals, mlx_color *colors, t_current *current, t_data *data)
{
	if (portals[BLUE].exist && portals[ORANGE].exist)
	{
		if (!current->i)
		{
			get_color(current->ray, data, portals, colors);
			current->i = 1;
		}
		return (colors[current->i++]);
	}
	return(current->color);
}
