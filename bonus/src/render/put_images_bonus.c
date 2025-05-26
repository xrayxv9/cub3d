/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:57:43 by mpendilh          #+#    #+#             */
/*   Updated: 2025/05/26 16:57:44 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	put_images_to_window(t_data *data)
{
	mlx_put_image_to_window(data->game, data->window,
		data->textures[4].texture, 0, 0);
	mlx_put_image_to_window(data->game, data->window,
		data->portal_images[CROSSHAIR],
		WIN_W >> 1, WIN_H >> 1);
	mlx_put_transformed_image_to_window(data->game, data->window,
		data->portal_images[PORTAL_LAUNCHER], 1000, 600, 1.7f, 1.7f, 0);
}
