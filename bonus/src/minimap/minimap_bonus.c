#include "portal_bonus.h"
#include "render_bonus.h"
#include <cub3D_bonus.h>

static void	trace_square(int start, int y, mlx_context game, mlx_image image)
{
	mlx_color	color;
	int			i;

	ft_bzero((char *)&color, sizeof(mlx_color));
	color.b = 255;
	color.a = 255;
	i = 0;
	while (i < 10)
	{
		mlx_set_image_pixel(game, image, start + i, y + i, color);
		i++;
	}
}

static void	trace_player(float x, float y, mlx_context game, mlx_image player)
{
	mlx_color	color;
	int			i;
	int			j;

	ft_bzero((char *)&color, sizeof(mlx_color));
	color.g = 255;
	color.a = 255;
	i = -2;
	while (i < 2)
	{
		j = -2;
		while (j < 2)
		{
			mlx_set_image_pixel(game, player, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	display_minimap(t_data *data)
{
	mlx_put_image_to_window(data->game, data->window,
		data->minimap_image, 0, 0);
	if (data->player.save_x != data->player.x
		|| data->player.save_y != data->player.y)
	{
		data->player_pos = mlx_new_image(data->game, WIN_W, WIN_H);
		trace_player(data->player.x * 10, data->player.y * 10,
			data->game, data->player_pos);
	}
	mlx_put_image_to_window(data->game, data->window,
		data->player_pos, 0, 0);
}

void	display_ray(t_data *data)
{
	mlx_color	color;
	t_ray		ray;

	color.r = 0;
	color.g = 255;
	color.b = 0;
	color.a = 255;
	init(&ray, &data->player, data->player.angle);
	main_while(&ray, &data->map);
	// if (portal_find(data->player.portals, ray.map_x, ray.map_y))
	// 	reset_angle(, t_ray *ray, int type, t_map *map)
	trace_square(ray.side_x, ray.side_y, data->game, data->player_pos);
	mlx_set_image_pixel(data->game, data->player_pos, ray.side_x, ray.side_y , color);
}

void	minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->minimap_image = mlx_new_image(data->game, WIN_W, data->map.h * 10);
	data->player_pos = mlx_new_image(data->game, WIN_W, WIN_H);
	trace_player(data->player.x * 10, data->player.y * 10,
		data->game, data->player_pos);
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == '1')
				trace_square(j * 10, i * 10, data->game, data->minimap_image);
			j++;
			display_ray(data);
		}
		i++;
	}
}
