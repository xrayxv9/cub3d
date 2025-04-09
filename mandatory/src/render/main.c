#include "cub3D.h"
#include "mlx.h"
#include "raycast.h"

void	key_down(int key, t_data *data)
{
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(data->game);
	if (key == SDL_SCANCODE_RIGHT)
	{
		data->player.move_angle = 2.5f;
		raycasting(data);
	}
	if (key == SDL_SCANCODE_LEFT)
	{
		data->player.move_angle = -2.5f;
		raycasting(data);
	}
	if (key == SDL_SCANCODE_W)
	{
		data->player.x += cos(convert_to_radian(data->player.angle)) * 0.5;
		data->player.y += sin(convert_to_radian(data->player.angle)) * 0.5;
		raycasting(data);
	}
	if (key == SDL_SCANCODE_S)
	{
		data->player.x += cos(convert_to_radian(data->player.angle - 180));
		data->player.y += sin(convert_to_radian(data->player.angle - 180));
		raycasting(data);
	}
}

void	key_up(int key, t_data *data)
{
	if (key == SDL_SCANCODE_RIGHT || key == SDL_SCANCODE_LEFT)
		data->player.move_angle = 0.0f;
}

void	window_hook(int event, t_data *data)
{
	if (event == 0)
		mlx_loop_end(data->game);
}

void	init_window(t_data *data)
{
	data->game = mlx_init();
	data->info.height = 1080;
	data->info.width = 1920;
	data->info.title = "test";
	data->window = mlx_new_window(data->game, &data->info);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nmange tes morts\n", 2);
		return (0);
	}
	ft_bzero((char *)&data, sizeof(t_data));
	init_window(&data);
	data.textures[6].texture = mlx_new_image(data.game, WIN_W, WIN_H);
	if (!parsing(&data, av[1]))
		return (0);
	mlx_set_fps_goal(data.game, 60);
	mlx_on_event(data.game, data.window, MLX_KEYDOWN, (void *)key_down, &data);
	mlx_on_event(data.game, data.window, MLX_WINDOW_EVENT,
		(void *)window_hook, &data);
	mlx_on_event(data.game, data.window, MLX_KEYUP, (void *)key_up, &data);
	raycasting(&data);
	mlx_loop(data.game);
	destroy_textures_free_tab(data.textures, data.map.map, data.game);
	return (0);
}
