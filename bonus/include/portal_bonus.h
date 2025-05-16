/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:28:43 by cmorel            #+#    #+#             */
/*   Updated: 2025/05/16 16:22:48 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORTAL_BONUS_H
# define PORTAL_BONUS_H

# include "struct_bonus.h"

# define BLUE 0
# define ORANGE 1

t_portal	*init_portal(void);

void		init_coo(t_portal *portals, t_ray *ray, int type);

void		portal_send(t_data *data, int type);

mlx_image	check_portal_coo(t_ray *ray, t_data *data,
				mlx_image image, int dir);

mlx_color	render_portal(t_portal *portals, mlx_color *colors,
				t_current *current, t_data *data);

t_save_info	reset_angle(t_portal *portals, t_ray *ray, int type, t_map *map);

void		line_handle_portal(t_ray *ray, double wall);

int			is_black(mlx_color *color);

int			portal_find(t_portal *portal, int x, int y, int dir);

void		teleport_collision(t_player *player, t_map *map);

#endif
