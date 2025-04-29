#ifndef PORTAL_BONUS_H
# define PORTAL_BONUS_H

# include "struct_bonus.h"

# define BLUE 0
# define ORANGE 1

t_portal	*init_portal(void);

void		init_coo(t_portal *portals, t_ray *ray, int type, t_player *player);

void		portal_send(t_data *data, int type);

#endif
