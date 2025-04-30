#include "cub3D_bonus.h"
#include "libft.h"
#include "mlx.h"
#include "parsing_bonus.h"
#include "struct_bonus.h"

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
	if (data->is_game == GAME)
	{
		if (!data->pause)
		{
			handle_mouse(data, 0);
			handle_player_move(&data->player);
			if (data->player.a_move || data->player.d_move
				|| data->player.s_move || data->player.w_move)
				calculate_speed(&data->player,
					data->player.save_angle, &data->player.save_angle);
			data->player.angle += data->player.move_angle;
			data->player.x += data->player.speed_x;
			data->player.y += data->player.speed_y;
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

int	free_fail(t_data *data)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	if (data->portal_images[CROSSHAIR] && data->portal_images[BLUE_IMAGE]
			&& data->portal_images[ORANGE_IMAGE])
		return (0);
	while (i++ < 3)
	{
		if (data->portal_images[i])
		{
			mlx_destroy_image(data->game, data->portal_images[i]);
			ret = 1;
		}
	}
	return (ret);
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
	data->portal_images[CROSSHAIR] = mlx_new_image_from_file(data->game,
								   "bonus/textures/crosshair.png", NULL, NULL);
	data->portal_images[BLUE_IMAGE] = mlx_new_image_from_file(data->game,
									"bonus/textures/portals/blue.png", NULL, NULL);
	data->portal_images[ORANGE_IMAGE] = mlx_new_image_from_file(data->game,
								"bonus/textures/portals/orange.png", NULL, NULL);
	if (free_fail(data))
		destroy_textures_free_tab(data->textures, data->map.map, data->game);
	if (!load_pause_screen(data->game, &data->scene))
		return (error_scene(data, 1));
}

int	main(int ac, char **av)
{
	t_data		data;

	ft_bzero((char *)&data, sizeof(t_data));
	init_all(&data, ac, av);
	data.scene.sensi = 1.00f;
	minimap(&data);
	data.minimap = false;
	data.is_game = MENU;
	data.scene.menu = FIRST;
	data.keyboard_input = WASD;
	mlx_set_fps_goal(data.game, 60);
	data.window = mlx_new_window(data.game, &data.info);
	mlx_add_loop_hook(data.game, (void *)update, &data);
	event(&data);
	mlx_loop(data.game);
	free(data.player.portals);
	destroy_textures_free_tab(data.textures, data.map.map, data.game);
	destroy_scene(&data.scene, data.game);
	return (0);
}
