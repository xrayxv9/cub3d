#ifndef RAYCAST_H
# define RAYCAST_H

# include "struct.h"

// functions

void	raycasting(void *da);

void	get_angle(t_halfs *ha, t_player player);

void	cast_ray(t_data *data, t_map map, t_halfs ha); 

double	convert_to_radian(float angle);

int		square(int number);

t_ray	init(t_ray *ray, t_player *player, float angle);

void	line_handle(t_ray *ray, t_player *player);

void	render_walls(t_data *data, t_ray *ray);

#endif
