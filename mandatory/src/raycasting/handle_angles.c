#include "../../include/cub3D.h"

void	get_angle(t_halfs *ha, t_player player)
{
	float angle;

	angle = player.angle;
	ha->half = angle;
	ha->begin = angle - 45;
	ha->end = angle + 45;
}
