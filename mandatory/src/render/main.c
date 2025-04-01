#include "../../include/cub3D.h"
#include <mandatory/include/parsing.h>

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

void	init_window(t_data *data)
{
	data->game = mlx_init();
	data->info.height = 1080;
	data->info.width = 1920;
	data->info.title = "test";
	data->window = mlx_new_window(data->game, &data->info);
	mlx_on_event(data->game, data->window, MLX_KEYDOWN, (void *)key_hook, data);
	mlx_on_event(data->game, data->window, MLX_WINDOW_EVENT,
		(void *)window_hook, data);
	mlx_loop(data->game);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	ft_bzero((char *)&data, sizeof(t_data));
	if (!parsing(&data, av[1]))
		return (0);
	init_window(&data);
	return (0);
}
