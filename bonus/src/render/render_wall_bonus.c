#include "portal_bonus.h"
#include "raycast_bonus.h"
#include "render_bonus.h"
#include <cub3D_bonus.h>

void	show(t_ray *ray, t_data *data, t_double *dou, t_current *current)
{
	mlx_image	image;
	int			dir;

	dir = set_dir(ray);
	image = data->textures[dir].texture;
	while (ray->line_end >= dou->i)
	{
		dou->delta = (dou->i - ray->line_start_tmp) / (float)ray->line_height * 1000;
		image = check_portal_coo(ray, data, image, dir);
		current->color.rgba = mlx_get_image_pixel(data->game, image,
				ray->touch_loc * 1000, dou->delta).rgba;
		if (current->loop)
		{
			if (!(is_color(current->color, 0, 0, 0) && both(data->player.portals)))
				mlx_set_image_pixel(data->game, data->textures[4].texture, dou->x, dou->i, current->color);
		}
		else
			mlx_set_image_pixel(data->game, data->textures[4].texture, dou->x, dou->i, current->color);
		dou->i++;
	}
}

void	calcul_touch_portal(t_ray *ray, t_double *dou, int dir, int use)
{
	if (ray->side == VER)
		ray->touch_loc = dou->dy + ray->wall_distance * ray->dir_y;
	else
		ray->touch_loc = dou->dx + ray->wall_distance * ray->dir_x;
	ray->touch_loc -= (int)ray->touch_loc;
	if (use)
	{
		if (dir == NORTH)
			ray->touch_loc = 1 - ray->touch_loc;
		if (dir == EAST)
			ray->touch_loc = 1 - ray->touch_loc;
	}
}

void	render_wall_portal(t_data *data, t_ray ray, float angle, int type)
{
	t_double	dou;
	int			dir;
	t_current	current;
	t_double	doudou;
	double		dist;

	dist = ray.wall_distance;
	doudou = reset_angle(data->player.portals, &ray, type, &data->map);
	dir = set_dir(&ray);
	current.ray = &ray;
	dou.i = ray.line_start;
	dou.x = angle;
	ray.wall_distance -= dist;
	calcul_touch_portal(&ray, &doudou, dir, 1);
	current.i = 0;
	current.loop = 0;
	show(&ray, data, &dou, &current);
}
