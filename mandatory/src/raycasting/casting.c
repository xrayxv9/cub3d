#include "../../include/cub3D.h"
#include <mandatory/include/raycast.h>
#include <mandatory/include/struct.h>
#include <math.h>

void	main_while(t_ray *ray)
{
	(void)ray;
}

void	cast_ray(t_player player, t_map map, t_halfs ha)
{
	t_ray	ray;
	int		i;
	(void)map;

	i = ha.begin;
	while (i)
	{
		init(&ray, player, ha.half);
		main_while(&ray);
		if (i == ha.half || i == 360)
			i = ha.end;
	}
}
