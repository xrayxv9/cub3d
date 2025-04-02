#include "../../include/cub3D.h"

void	get_angle(t_halfs *ha, t_player player)
{
	float angle;

	angle = player.angle;
	ha->half = angle;
	if (angle >= 45 && angle <= 315)
	{
		ha->begin = angle - 45;
		ha->end = angle + 45;
	}
	else if (angle < 45)
	{
		ha->begin = (360 - (angle - 45));
		ha->end = angle + 45;
	}
	else if (angle > 315)
	{
		ha->begin = angle - 45;
		ha->end = (360 - angle);
	}
}
