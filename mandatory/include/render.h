#ifndef RENDER_H
# define RENDER_H

# include "../include/struct.h"

void	render_floor(t_data *data, mlx_color color);

void	render_celling(t_data *data, mlx_color color);

void	render_bg(t_data *data);

void	render_walls(t_data *data, t_ray *ray, int angle);

#endif
