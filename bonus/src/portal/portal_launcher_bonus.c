/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_launcher_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:55:41 by mpendilh          #+#    #+#             */
/*   Updated: 2025/05/26 16:55:41 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	init_portal_textures3(t_data *data)
{
	int	fd;

	fd = open("bonus/textures/crosshair.png", O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open("bonus/textures/portal_launcher.png", O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	data->portal_images[CROSSHAIR] = mlx_new_image_from_file(data->game,
			"bonus/textures/crosshair.png", NULL, NULL);
	data->portal_images[PORTAL_LAUNCHER] = mlx_new_image_from_file(data->game,
			"bonus/textures/portal_launcher.png", NULL, NULL);
	return (1);
}

int	init_portal_textures2(t_data *data)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*tmp2;

	i = ORANGE_IMAGE_1;
	while (i < ORANGE_PORTAL_FRAME + ORANGE_IMAGE_1)
	{
		tmp = ft_strjoin("bonus/textures/portals/orange", ft_itoa
				(i - ORANGE_IMAGE_1 + 1));
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
	return (1);
}

int	init_portal_textures(t_data *data)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*tmp2;

	i = BLUE_IMAGE_1;
	while (i < BLUE_PORTAL_FRAME + BLUE_IMAGE_1)
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
	return (1);
}
