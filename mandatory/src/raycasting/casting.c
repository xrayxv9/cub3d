#include "../../include/cub3D.h"
#include <mandatory/include/struct.h>
#include <math.h>

int is_wall(double *dir, t_map map)
{
	int rounded_x;
	int	rounded_y;

	rounded_x = round(dir[0]);
	rounded_y = round(dir[0]);
	if ((rounded_x >= 0 || rounded_x == map.x)
		&& (rounded_y == 0 || rounded_y == map.y))
	{
		if (map.map[rounded_x][rounded_y] == '1')
			return (1);
	}
	return (0);
}

int	*find_ray(t_player player, t_map map, double *dir)
{
	int *walls;

	walls = malloc(2 * sizeof(int));
	while (!is_wall(dir, map))
	{

	}
	return (walls);
}

void	cast_ray(t_player player, t_map map, t_halfs ha)
{
	double	directions[2];
	int		*wall;

	directions[0] = sin(ha.begin);
	directions[1] = cos(ha.begin);
	wall = find_ray(player, map, directions);
	
}
