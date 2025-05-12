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

void	test(t_data *data, t_ray ray, float x, int type)
{
	t_double	dou;
	int			dir;
	mlx_image	image;
	t_current	current;

	reset_angle(data->player.portals, &ray, type, &data->map);
	dir = set_dir(&ray);
	current.ray = &ray;
	image = data->textures[dir].texture;
	dou.i = ray.line_start;
	dou.x = x;
	calcul_touch(&ray, &data->player, dir, 1);
	current.i = 0;
	while (ray.line_end >= dou.i)
	{
		dou.delta = (dou.i - ray.line_start_tmp) / (float)ray.line_height * 1000;
		image = check_portal_coo(&ray, data, image, dir);
		current.color.rgba = mlx_get_image_pixel(data->game, image,
				ray.touch_loc * 1000, dou.delta).rgba;
		mlx_set_image_pixel(data->game, data->textures[4].texture, dou.x, dou.i, current.color);
		dou.i++;
	}
}

int both(t_portal *portals)
{
	if (portals[BLUE].exist && portals[ORANGE].exist)
		return (1);
	return (0);
}

void	render_walls(t_data *data, t_ray *ray, float x)
{
	t_double	dou;
	int			dir;
	mlx_image	image;
	t_current	current;
	int			type;

	dir = set_dir(ray);
	printf("type : %d, portal co : (%d, %d)\n", 0, data->player.portals[0].x, data->player.portals[0].y);
	type = portal_find(data->player.portals, ray->map_x, ray->map_y, dir);
	if (type != -1 && data->player.portals[BLUE].exist && data->player.portals[ORANGE].exist)
		test(data, *ray, x, type);
	current.ray = ray;
	image = data->textures[dir].texture;
	dou.i = ray->line_start;
	dou.x = x;
	calcul_touch(ray, &data->player, dir, 1);
	current.i = 0;
	while (ray->line_end >= dou.i)
	{
		dou.delta = (dou.i - ray->line_start_tmp) / (float)ray->line_height * 1000;
		image = check_portal_coo(ray, data, image, dir);
		current.color.rgba = mlx_get_image_pixel(data->game, image,
				ray->touch_loc * 1000, dou.delta).rgba;
		if (!is_color(current.color, 0, 0, 0))
			mlx_set_image_pixel(data->game, data->textures[4].texture, dou.x, dou.i, current.color);
		dou.i++;
	}
}
