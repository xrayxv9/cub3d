/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:26:44 by cmorel            #+#    #+#             */
/*   Updated: 2025/05/16 12:26:45 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "struct.h"

// functions

void	raycasting(t_data *data);

void	cast_ray(t_data *data);

double	radian(float angle);

int		square(int number);

t_ray	init(t_ray *ray, t_player *player, float angle);

void	line_handle(t_ray *ray, t_player *player, float x);

#endif
