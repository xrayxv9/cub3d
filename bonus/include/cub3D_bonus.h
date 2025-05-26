/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:28:36 by cmorel            #+#    #+#             */
/*   Updated: 2025/05/26 15:02:09 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include <sys/time.h>
# include <SDL2/SDL_scancode.h>
# include "../../MacroLibX/includes/mlx_extended.h"
# include "../../MacroLibX/includes/mlx.h"
# include "parsing_bonus.h"
# include "struct_bonus.h"
# include "raycast_bonus.h"
# include "render_bonus.h"
# include "scene_bonus.h"
# include "libft.h"
# include "portal_bonus.h"

# define WIN_H 1080
# define WIN_W 1920
# define FPS 160
# define VER 1
# define HOR 0
# define ARGS_ERROR "Please ensure that you give a map\n"

// minimap

void	minimap(t_data *data);
void	display_minimap(t_data *data);

#endif
