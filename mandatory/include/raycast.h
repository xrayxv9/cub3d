#ifndef RAYCAST_H
# define RAYCAST_H

# include "struct.h"

// functions

void	raycasting(void *da);

void	get_angle(t_halfs *ha, t_player player);

void	cast_ray(t_player player, t_map map, t_halfs ha); 

#endif
