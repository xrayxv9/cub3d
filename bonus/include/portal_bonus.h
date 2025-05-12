#ifndef PORTAL_BONUS_H
# define PORTAL_BONUS_H

# include "struct_bonus.h"

# define BLUE 0
# define ORANGE 1

t_portal	*init_portal(void);

void		init_coo(t_portal *portals, t_ray *ray, int type);

void		portal_send(t_data *data, int type);

mlx_image	check_portal_coo(t_ray *ray, t_data *data, mlx_image image, int dir);

mlx_color	render_portal(t_portal *portals, mlx_color *colors, t_current *current, t_data *data);

void		reset_angle(t_portal *portals, t_ray *ray, int type, t_map *map);

void		line_handle_portal(t_ray *ray, t_portal portal, float x, double wall);

int			is_color(mlx_color color, unsigned int r, unsigned int g, unsigned int b);

int		portal_find(t_portal *portal, int x, int y, int dir);

#endif
