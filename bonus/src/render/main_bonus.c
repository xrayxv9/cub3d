#include "cub3D_bonus.h"

static void	init_window(t_data *data)
{
	data->game = mlx_init();
	data->info.height = 1080;
	data->info.width = 1920;
	data->info.title = "portal";
}

static void	update(t_data *data)
{
	if (data->is_game == MENU)
		handle_scene(data);
	else if (data->is_game == GAME)
	{
		handle_frame_limiter(data);
		if (!data->pause)
		{
			handle_mouse(data, 0);
			handle_player_move(&data->player);
			handle_move(data);
			data->player.angle += data->player.move_angle;
			teleport_collision(&data->player, &data->map);
			handle_mouse(data, 1);
			if (data->player.move_angle != 0
				|| data->player.speed_x != 0 || data->player.speed_y != 0)
				cast_ray(data);
			if (data->minimap)
				display_minimap(data);
		}
		if (data->pause)
			handle_pause_screen(data);
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
	data->player.portals = init_portal();
	init_portal_textures(data);
	init_portal_textures2(data);
	init_portal_textures3(data);
	if (!load_pause_screen(data->game, &data->scene))
		return (error_scene(data, 1));
}

int	main(int ac, char **av)
{
	t_data		data;

	ft_bzero((char *)&data, sizeof(t_data));
	init_all(&data, ac, av);
	data.scene.sensi = 0.23f;
	minimap(&data);
	data.blue_portal_frame_ctr = BLUE_IMAGE_1;
	data.orange_portal_frame_ctr = ORANGE_IMAGE_1;
	data.minimap = false;
	data.is_game = MENU;
	data.scene.menu = FIRST;
	data.keyboard_input = WASD;
	mlx_set_fps_goal(data.game, 60);
	data.window = mlx_new_window(data.game, &data.info);
	data.timestamp_last_frame = timestamp();
	mlx_add_loop_hook(data.game, (void *)update, &data);
	event(&data);
	mlx_loop(data.game);
	free(data.player.portals);
	destroy_textures_free_tab(data.textures, data.map.map, data.game);
	destroy_scene(&data.scene, data.game);
	return (0);
}
