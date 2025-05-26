/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:58:22 by mpendilh          #+#    #+#             */
/*   Updated: 2025/05/26 16:58:22 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	load_background(mlx_context game, t_sc *scene)
{
	int			w;
	int			h;
	int			fd;

	fd = open("bonus/textures/background.png", O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	scene->background = mlx_new_image_from_file(game,
			"bonus/textures/background.png", &w, &h);
	return (1);
}

int	load_buttons_first_menu(mlx_context game, t_sc *scene)
{
	int			fd;
	int			i;
	char		*tmp;
	char		*tmp2;

	i = 0;
	while (i < FIRST_MENU_BUTTON)
	{
		tmp = ft_strjoin("bonus/textures/main_menu/button", ft_itoa(i + 1));
		tmp2 = ft_strjoin(tmp, ".bmp");
		free(tmp);
		fd = open(tmp2, O_RDONLY);
		if (fd == -1)
		{
			free(tmp2);
			return (0);
		}
		scene->scene[i].texture = mlx_new_image_from_file(game,
				tmp2, &scene->scene[i].w, &scene->scene[i].h);
		free(tmp2);
		close(fd);
		i++;
	}
	return (1);
}

int	load_buttons_second_menu(mlx_context game, t_sc *scene)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*tmp2;

	i = FIRST_MENU_BUTTON;
	while (i < FIRST_MENU_BUTTON + SECOND_MENU_BUTTON)
	{
		tmp = ft_strjoin("bonus/textures/play/button",
				ft_itoa(i - FIRST_MENU_BUTTON + 1));
		tmp2 = ft_strjoin(tmp, ".bmp");
		free(tmp);
		fd = open (tmp2, O_RDONLY);
		if (fd == -1)
		{
			free(tmp2);
			return (0);
		}
		scene->scene[i].texture = mlx_new_image_from_file(game,
				tmp2, &scene->scene[i].w, &scene->scene[i].h);
		free(tmp2);
		close(fd);
		i++;
	}
	return (1);
}

int	load_buttons_third_menu(mlx_context game, t_sc *scene)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*tmp2;

	i = FIRST_MENU_BUTTON + SECOND_MENU_BUTTON;
	while (i < BUTTONS - PAUSE_MENU)
	{
		tmp = ft_strjoin("bonus/textures/settings/button",
				ft_itoa(i - FIRST_MENU_BUTTON - SECOND_MENU_BUTTON + 1));
		tmp2 = ft_strjoin(tmp, ".png");
		free(tmp);
		fd = open(tmp2, O_RDONLY);
		if (fd == -1)
		{
			free(tmp2);
			return (0);
		}
		scene->scene[i].texture = mlx_new_image_from_file(game, tmp2,
				&scene->scene[i].w, &scene->scene[i].h);
		close(fd);
		i++;
	}
	return (1);
}

int	load_pause_screen(mlx_context game, t_sc *scene)
{
	int	fd;

	fd = open("bonus/textures/pause/button1.png", O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open("bonus/textures/pause/button2.png", O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open("bonus/textures/pause/background.jpg", O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	scene->scene[RESUME].texture = mlx_new_image_from_file(game,
			"bonus/textures/pause/button2.png", &scene->scene[RESUME].w,
			&scene->scene[RESUME].h);
	scene->scene[GO_TO_MENU].texture = mlx_new_image_from_file(game,
			"bonus/textures/pause/button1.png",
			&scene->scene[GO_TO_MENU].w, &scene->scene[GO_TO_MENU].h);
	scene->scene[BACKGROUND].texture = mlx_new_image_from_file(game,
			"bonus/textures/pause/background.jpg",
			&scene->scene[BACKGROUND].w, &scene->scene[BACKGROUND].h);
	return (1);
}
