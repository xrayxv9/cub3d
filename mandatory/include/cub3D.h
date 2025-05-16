/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:26:38 by cmorel            #+#    #+#             */
/*   Updated: 2025/05/16 12:26:39 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "parsing.h"
# include "struct.h"
# include "raycast.h"
# include "render.h"
# include <SDL2/SDL_scancode.h>
# include "libft.h"
# include "../../MacroLibX/includes/mlx_extended.h"

# define WIN_H 1080
# define WIN_W 1920
# define VER 1
# define HOR 0
# define ARGS_ERROR "Please ensure that you give a map\n"

#endif
