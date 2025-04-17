#include "cub3D.h"
#include "scene.h"
#include "struct.h"

static void	init_window(t_data *data)
{
	data->game = mlx_init();
	data->info.height = 1080;
	data->info.width = 1920;
	data->info.title = "test";
}

static void	update(t_data *data)
{
	if (data->is_game == MENU)
		handle_scene(data);
	if (data->is_game == GAME)
	{
		if (data->player.a_move || data->player.d_move
			|| data->player.s_move || data->player.w_move)
			calculate_speed(&data->player,
				data->player.save_angle, &data->player.save_angle);
		data->player.angle += data->player.move_angle;
		data->player.x += data->player.speed_x;
		data->player.y += data->player.speed_y;
		if (data->player.move_angle != 0
			|| data->player.speed_x != 0 || data->player.speed_y != 0)
			cast_ray(data);
	}
}

static void	init_all(t_data *data, int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error\n"ARGS_ERROR, 2);
		exit (0);
	}
	init_window(data);
	data->textures[4].texture = mlx_new_image(data->game, WIN_W, WIN_H);
	if (!parsing(data, av[1]))
		exit (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero((char *)&data, sizeof(t_data));
	init_all(&data, ac, av);
	data.is_game = MENU;
	data.scene.menu = FIRST;
	data.keyboard_input = WASD;
	mlx_set_fps_goal(data.game, 60);
	data.window = mlx_new_window(data.game, &data.info);
	mlx_add_loop_hook(data.game, (void *)update, &data);
	event(&data);
	mlx_loop(data.game);
	destroy_textures_free_tab(data.textures, data.map.map, data.game);
	destroy_scene(&data.scene, data.game);
	return (0);
}
