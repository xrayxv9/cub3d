#include "cub3D_bonus.h"

static int	is_good_angle(t_player *player, int tmp)
{
	return ((player->y < player->portals[tmp].y
			&& player->portals[tmp].dir == NORTH)
		|| (player->y > player->portals[tmp].y
			&& player->portals[tmp].dir == SOUTH)
		|| (player->x < player->portals[tmp].x
			&& player->portals[tmp].dir == EAST)
		|| (player->x > player->portals[tmp].x
			&& player->portals[tmp].dir == WEST));
}

static int	get_portal(t_player *player)
{
	t_portal	blue;
	t_portal	orange;

	blue = player->portals[BLUE];
	orange = player->portals[ORANGE];
	if (blue.x
		== (int)(player->x + player->speed_x)
		&& blue.y
		== (int)(player->y + player->speed_y)
		&& is_good_angle(player, BLUE))
		return (BLUE);
	if (orange.x
		== (int)(player->x + player->speed_x)
		&& orange.y
		== (int)(player->y + player->speed_y)
		&& is_good_angle(player, ORANGE))
		return (ORANGE);
	return (-1);
}

static void	add_coo(t_player *player, int color)
{
	if (player->portals[color].dir == SOUTH)
	{
		player->x = player->portals[color].x + 0.5f;
		player->y = player->portals[color].y + 1.01f;
	}
	if (player->portals[color].dir == NORTH)
	{
		player->x = player->portals[color].x + 0.5f;
		player->y = player->portals[color].y - 0.01f;
	}
	if (player->portals[color].dir == WEST)
	{
		player->x = player->portals[color].x + 1.01f;
		player->y = player->portals[color].y + 0.5f;
	}
	if (player->portals[color].dir == EAST)
	{
		player->x = player->portals[color].x - 0.01f;
		player->y = player->portals[color].y + 0.5f;
	}
}


void	teleport_collision(t_player *player, t_map *map)
{
	int	tmp;

	if (map->map[(int)(player->y + player->speed_y)]
		[(int)(player->x + player->speed_x)] != '1')
	{
		player->x += player->speed_x;
		player->y += player->speed_y;
	}
	if (player->portals[BLUE].exist
		&& player->portals[ORANGE].exist)
	{
		tmp = get_portal(player);
		if (is_good_angle(player, tmp))
		{
			player->angle = get_angle_tp(player->angle,
					player->portals[tmp].dir, player->portals[tmp == 0].dir);
			add_coo(player, tmp == 0);
		}
	}
}
