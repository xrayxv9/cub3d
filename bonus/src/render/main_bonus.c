#include "cub3D_bonus.h"
#include "raycast_bonus.h"
#include "struct_bonus.h"

static void	init_window(t_data *data)
{
	data->game = mlx_init();
	data->info.height = 1080;
	data->info.width = 1920;
	data->info.title = "portal";
}

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static void	update(t_data *data)
{
	if (data->is_game == MENU)
		handle_scene(data);
	else if (data->is_game == GAME)
	{
		data->curr_timestamp = timestamp();
		if (data->curr_timestamp < data->timestamp_last_frame + 1000 / FPS)
		{
			if (data->portal_frame_ctr > PORTAL_FRAME - 1)
				data->portal_frame_ctr = BLUE_IMAGE_1;
			usleep((data->timestamp_last_frame
					+ 1000 / FPS - data->curr_timestamp) * 1000);
			data->portal_frame_ctr++;
			cast_ray(data);
		}
		data->timestamp_last_frame = data->curr_timestamp;
		if (!data->pause)
		{
			handle_mouse(data, 0);
			handle_player_move(&data->player);
			if (data->player.a_move || data->player.d_move
				|| data->player.s_move || data->player.w_move)
				calculate_speed(&data->player,
					data->player.save_angle, &data->player.save_angle);
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

int	init_portal_textures(t_data *data)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*tmp2;

	i = BLUE_IMAGE_1;
	while (i < PORTAL_FRAME + BLUE_IMAGE_1)
	{
		tmp = ft_strjoin("bonus/textures/portals/blue", ft_itoa(i));
		tmp2 = ft_strjoin(tmp, ".png");
		free(tmp);
		fd = open(tmp2, O_RDONLY);
		if (fd == -1)
		{
			free(tmp2);
			return (0);
		}
		close(fd);
		data->portal_images[i] = mlx_new_image_from_file
			(data->game, tmp2, NULL, NULL);
		free(tmp2);
		i++;
	}
	data->portal_images[CROSSHAIR] = mlx_new_image_from_file(data->game,
			"bonus/textures/crosshair.png", NULL, NULL);
	data->portal_images[ORANGE_IMAGE] = mlx_new_image_from_file(data->game,
			"bonus/textures/portals/orange.png", NULL, NULL);
	data->portal_images[PORTAL_LAUNCHER] = mlx_new_image_from_file(data->game,
			"bonus/textures/portal_launcher.png", NULL, NULL);
	return (1);
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
	data.portal_frame_ctr = BLUE_IMAGE_1;
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
