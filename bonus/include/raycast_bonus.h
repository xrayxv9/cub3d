#ifndef RAYCAST_BONUS_H
# define RAYCAST_BONUS_H

# include "struct_bonus.h"

// functions

void	raycasting(t_data *data);

void	cast_ray(t_data *data);

double	radian(float angle);

int		square(int number);

t_ray	init(t_ray *ray, t_player *player, float angle);

void	line_handle(t_ray *ray, t_player *player, float x);

void	init_step(t_ray *ray);

void	init_side(t_ray *ray, double x, double y);

#endif
