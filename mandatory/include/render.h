#ifndef RENDER_H
# define RENDER_H

# include "../include/struct.h"

void	background(void *da);

char	**read_map( void );

void	destroy_all(t_data *data);

void	load_content(t_image *textures, mlx_context game);


#endif
