/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:58:19 by mpendilh          #+#    #+#             */
/*   Updated: 2025/05/26 16:58:19 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	display_first_scene_buttons(mlx_window window, mlx_context game,
		t_sc *scene)
{
	mlx_put_image_to_window(game, window,
		scene->scene[PLAY].texture, 660, 300);
	mlx_put_image_to_window(game, window,
		scene->scene[SETTINGS].texture, 660, 525);
	mlx_put_image_to_window(game, window,
		scene->scene[QUIT].texture, 660, 750);
}

void	display_second_scene_buttons(mlx_window window, mlx_context game,
		t_sc *scene)
{
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[CONTINUE].texture, 510, 300, 1.5, 1.5, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[BACK].texture, 10, 865, 0.7, 0.7, 0);
}
