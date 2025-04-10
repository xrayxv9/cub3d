#include "cub3D.h"
#include "raycast.h"

void	init_window(t_data *data)
{
	data->game = mlx_init();
	data->info.height = 1080;
	data->info.width = 1920;
	data->info.title = "test";
}

void	update(t_data *data)
{
	if (data->player.a_move || data->player.d_move
		|| data->player.s_move || data->player.w_move)
		calculate_speed(&data->player,
			data->player.save_angle, &data->player.save_angle);
	data->player.angle += data->player.move_angle;
	data->player.x += data->player.speed_x;
	data->player.y += data->player.speed_y;
	if (data->player.move_angle != 0)
		cast_ray(data);
	if (data->player.speed_x != 0 || data->player.speed_y != 0)
		cast_ray(data);
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
	data.window = mlx_new_window(data.game, &data.info);
	mlx_set_fps_goal(data.game, 60);
	mlx_add_loop_hook(data.game, (void *)update, &data);
	cast_ray(&data);
	event(&data);
	mlx_loop(data.game);
	destroy_textures_free_tab(data.textures, data.map.map, data.game);
	return (0);
}
