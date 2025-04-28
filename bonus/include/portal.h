#ifndef PORTAL_H
# define PORTAL_H

# include "struct.h"

# define BLUE 0
# define ORANGE 1

void	init_portal(t_portal *portals);

void	init_coo(t_portal portals, t_ray *ray, t_player *player);

void	portal_send(t_data *data, int type);

#endif
