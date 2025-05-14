#include "cub3D_bonus.h"
#include "portal_bonus.h"

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
	render_celling(data, data->color[SKY]);
	render_floor(data, data->color[FLOOR]);
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
	t_double	dou;
	int			dir;
	t_current	current;
	int			type;

	dir = set_dir(ray);
	type = portal_find(data->player.portals, ray->map_x, ray->map_y, dir);
	if (type != -1 && data->player.portals[BLUE].exist && data->player.portals[ORANGE].exist)
		render_wall_portal(data, *ray, x, type);
	current.ray = ray;
	dou.i = ray->line_start;
	dou.x = x;
	calcul_touch(ray, &data->player, dir, 1);
	current.i = 0;
	current.loop = 1;
	show(ray, data, &dou, &current);
}
