#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include <SDL2/SDL_scancode.h>
# include "mlx_extended.h"
# include "parsing.h"
# include "struct.h"
# include "raycast.h"
# include "render.h"
# include "scene.h"
# include "libft.h"

# define WIN_H 1080
# define WIN_W 1920
# define VER 1
# define HOR 0
# define ARGS_ERROR "Please ensure that you give a map\n"

// minimap

void	minimap(t_data *data);
void	display_minimap(t_data *data);

#endif
