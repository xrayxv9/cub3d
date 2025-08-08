/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:57:32 by mpendilh          #+#    #+#             */
/*   Updated: 2025/08/08 02:08:46 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D_bonus.h"

static void	init_window(t_data *data)
{
	data->game = mlx_init();
	data->info.height = 1080;
	data->info.width = 1920;
	data->info.title = "portal";
}

static void	update(t_data *data)
{
	t_player *player;
    static unsigned long frame_count = 0;
    static unsigned long last_fps = 0;
    static time_t last_time = 0;
    time_t now = time(NULL);

    frame_count++;

    // Affiche le FPS chaque seconde
    if (now != last_time) {
        printf("FPS: %lu\n", frame_count - last_fps);
        last_fps = frame_count;
        last_time = now;
    }

	player = &data->player;
	if (data->is_game == MENU)
		handle_scene(data);
	else if (data->is_game == GAME)
	{
		handle_frame_limiter(data);
		if (!data->pause)
		{
			handle_mouse(data, 0);
			handle_player_move(player);
			handle_move(data);
			player->angle += player->move_angle;
			teleport_collision(player, &data->map);
			handle_mouse(data, 1);
			if (player->move_angle != 0
				|| player->speed_x != 0 || player->speed_y != 0)
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
	data->player.angle = -1;
	if (!parsing(data, av[1]))
		exit (0);
	data->player.portals = init_portal();
	init_portal_textures(data);
	init_portal_textures2(data);
	init_portal_textures3(data);
	data->scene.sensi = 0.23f;
	data->blue_portal_frame_ctr = BLUE_IMAGE_1;
	data->orange_portal_frame_ctr = ORANGE_IMAGE_1;
	data->minimap = false;
	data->is_game = MENU;
	data->scene.menu = FIRST;
	data->keyboard_input = WASD;
	if (!load_pause_screen(data->game, &data->scene))
		return (error_scene(data, 1));
}

static void	destroy_all_textures(t_data *data)
{
	int	i;

	i = -1;
	while (++i && data->portal_images[i])
		mlx_destroy_image(data->game, data->portal_images[i]);
	if (data->image)
		mlx_destroy_image(data->game, data->image);
	if (data->minimap_image)
		mlx_destroy_image(data->game, data->minimap_image);
	if (data->player_pos)
		mlx_destroy_image(data->game, data->player_pos);
}

int	main(int ac, char **av)
{
	t_data		data;

	ft_bzero((char *)&data, sizeof(t_data));
	if (ac != 2)
	{
		ft_putstr_fd(ERROR ARGS_ERROR, 2);
		return (0);
	}
	init_all(&data, ac, av);
	minimap(&data);
	mlx_set_fps_goal(data.game, 60);
	data.window = mlx_new_window(data.game, &data.info);
	data.timestamp_last_frame = timestamp();
	mlx_add_loop_hook(data.game, (void *)update, &data);
	event(&data);
	mlx_loop(data.game);
	free(data.player.portals);
	destroy_all_textures(&data);
	destroy_textures_free_tab(data.textures, data.map.map, data.game);
	destroy_scene(&data.scene, data.game);
	return (0);
}
