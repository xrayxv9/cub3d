/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:58:27 by mpendilh          #+#    #+#             */
/*   Updated: 2025/05/26 16:58:29 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	destroy_scene(t_sc *scene, mlx_context game)
{
	int	i;

	i = 0;
	if (scene->background)
		mlx_destroy_image(game, scene->background);
	while (i < BUTTONS)
	{
		if (scene->scene[i].texture)
			mlx_destroy_image(game, scene->scene[i].texture);
		i++;
	}
}

void	error_scene(t_data *data, int i)
{
	destroy_scene(&data->scene, data->game);
	ft_putstr_fd(ERROR, 2);
	if (!i)
		ft_putstr_fd(BACKGROUND_ERROR, 2);
	if (i == 1)
		ft_putstr_fd(BUTTONS_ERROR, 2);
	exit(EXIT_FAILURE);
}
