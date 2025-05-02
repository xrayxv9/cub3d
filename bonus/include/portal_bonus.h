#ifndef PORTAL_BONUS_H
# define PORTAL_BONUS_H

# include "struct_bonus.h"

# define BLUE 0
# define ORANGE 1

t_portal	*init_portal(void);

void		init_coo(t_portal *portals, t_ray *ray, int type);

void		portal_send(t_data *data, int type);

mlx_image	check_portal_coo(t_ray *ray, t_data *data, mlx_image image, int dir);

void		render_portal(t_data *data, t_double *dou, mlx_color color, t_ray *ray);

void		reset_angle(t_portal *portals, t_ray *ray, int type, t_map *map);

void		line_handle_portal(t_ray *ray, t_portal portal, float x);

#endif
