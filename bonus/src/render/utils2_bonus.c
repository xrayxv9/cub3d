/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:58:07 by mpendilh          #+#    #+#             */
/*   Updated: 2025/08/08 01:55:09 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	handle_frame_limiter(t_data *data)
{
	data->curr_timestamp = timestamp();
	if (data->curr_timestamp < data->timestamp_last_frame + 1000 / FPS)
		usleep((data->timestamp_last_frame
				+ 1000 / FPS - data->curr_timestamp) * 1000);
	data->timestamp_last_frame = data->curr_timestamp;
	data->counter++;
	if (data->blue_portal_frame_ctr >= BLUE_PORTAL_FRAME)
		data->blue_portal_frame_ctr = BLUE_IMAGE_1;
	if (data->orange_portal_frame_ctr
		>= BLUE_PORTAL_FRAME + ORANGE_PORTAL_FRAME)
		data->orange_portal_frame_ctr = ORANGE_IMAGE_1;
	if (data->counter > 12)
	{
		data->blue_portal_frame_ctr++;
		data->orange_portal_frame_ctr++;
		cast_ray(data);
		data->counter = 0;
	}
}

void	handle_move(t_data *data)
{
	if (data->player.a_move || data->player.d_move
		|| data->player.s_move || data->player.w_move)
		calculate_speed(&data->player,
			data->player.save_angle, &data->player.save_angle);
}
