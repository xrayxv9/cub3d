#include "mlx.h"
#include "portal_bonus.h"
#include "render_bonus.h"
#include <cub3D_bonus.h>

int	is_color(mlx_color color, unsigned int r, unsigned int g, unsigned int b)
{
	mlx_color black;

	black.r = r;
	black.g = g;
	black.b = b;
	black.a = 255;
	if (color.rgba == black.rgba)
		return (1);
	return (0);
}

int	portal_find(t_portal *portal, int x, int y, int dir)
{
	if (portal[BLUE].x == x && portal[BLUE].y == y && dir == portal[BLUE].dir)
		return (BLUE);
	else if (portal[ORANGE].x == x && portal[ORANGE].y == y && dir == portal[ORANGE].dir)
		return (ORANGE);
	return (-1);
}
