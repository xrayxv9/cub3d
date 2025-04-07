#include "cub3D.h"

void	key_hook(int key, t_data *data)
{
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(data->game);
}

void	window_hook(int event, t_data *data)
{
	if (event == 0)
		mlx_loop_end(data->game);
}

t_player	player_init(void)
{
	t_player	player;

	player.dir_x = -1.0;
	player.dir_y = 0.0;
	player.x = 2.5f;
	player.y = 2.5f;
	player.plane_x = cos(convert_to_radian(270 - 90)) * 0.66;
	player.plane_y = sin(convert_to_radian(270 - 90)) * 0.66;
	return (player);
}

void	init_window(t_data *data)
{
	data->player = player_init();
	data->game = mlx_init();
	data->info.height = 1080;
	data->info.width = 1920;
	data->info.title = "test";
	data->window = mlx_new_window(data->game, &data->info);
	mlx_on_event(data->game, data->window, MLX_KEYDOWN, (void *)key_hook, data);
	mlx_on_event(data->game, data->window, MLX_WINDOW_EVENT,
		(void *)window_hook, data);
	mlx_add_loop_hook(data->game, (void *)raycasting, data);
	mlx_loop(data->game);
}

int	main(int ac, char **av)
{
	t_data	data;

  if (ac != 2)
  {
    ft_putstr_fd("mange tes morts\n", 2);
    return (0);
  }
	ft_bzero((char *)&data, sizeof(t_data));
	init_window(&data);
	if (!parsing(&data, av[1]))
		return (0);
	return (0);
}
