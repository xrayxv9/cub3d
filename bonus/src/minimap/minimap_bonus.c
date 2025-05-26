#include "cub3D_bonus.h"

static void	trace_square(int start, int y, mlx_context game, mlx_image image)
{
	mlx_color	color;
	int			i;
	int			j;

	ft_bzero((char *)&color, sizeof(mlx_color));
	color.b = 255;
	color.a = 255;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_set_image_pixel(game, image, start + j, y + i, color);
			j++;
		}
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
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
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
	mlx_put_image_to_window(data->game, data->window,
		data->player_pos, data->player.x * 10 - 2, data->player.y * 10 - 2);
}

void	minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->minimap_image = mlx_new_image(data->game, WIN_W, data->map.h * 10);
	data->player_pos = mlx_new_image(data->game, 10, 10);
	trace_player(0, 0, data->game, data->player_pos);
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == '1')
				trace_square(j * 10, i * 10, data->game, data->minimap_image);
			j++;
		}
		i++;
	}
}
