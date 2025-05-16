/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:28:47 by cmorel            #+#    #+#             */
/*   Updated: 2025/05/16 16:03:25 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_BONUS_H
# define RAYCAST_BONUS_H

# include "struct_bonus.h"

// functions

void		raycasting(t_data *data);

void		cast_ray(t_data *data);

double		radian(float angle);

int			square(int number);

t_ray		init_dda(t_ray *ray, double x, double y, float angle);

void		line_handle(t_ray *ray, t_player *player, float x);

void		init_step(t_ray *ray);

void		init_side(t_ray *ray, double x, double y);

t_save_info	init_side_portal(double touch_loc, t_portal *portal,
				int type, int anti);

double		get_angle_tp(float angle, int dir_portal, int dir_tp);

#endif
