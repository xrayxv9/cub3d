#include "cub3D_bonus.h"

static int	get_portal(t_player *player)
{
	if (player->portals[BLUE].x
		== (int)(player->x + player->speed_x)
		&& player->portals[BLUE].y
		== (int)(player->y + player->speed_y))
		return (BLUE);
	if (player->portals[ORANGE].x
		== (int)(player->x + player->speed_x)
		&& player->portals[ORANGE].y
		== (int)(player->y + player->speed_y))
		return (ORANGE);
	return (-1);
}

static void	add_coo(t_player *player, int color)
{
	if (player->portals[color].dir == SOUTH)
	{
		player->x = player->portals[color].x + 0.5f;
		player->y = player->portals[color].y + 1.5f;
	}
	if (player->portals[color].dir == NORTH)
	{
		player->x = player->portals[color].x + 0.5f;
		player->y = player->portals[color].y - 0.5f;
	}
	if (player->portals[color].dir == EAST)
	{
		player->x = player->portals[color].x + 1.5f;
		player->y = player->portals[color].y + 0.5f;
	}
	if (player->portals[color].dir == WEST)
	{
		player->x = player->portals[color].x - 0.5f;
		player->y = player->portals[color].y + 0.5f;
	}
}

static int	is_good_angle(t_player *player, int tmp)
{
	return ((player->y < player->portals[tmp].y
			&& player->portals[tmp].dir == NORTH)
		|| (player->y > player->portals[tmp].y
			&& player->portals[tmp].dir == SOUTH)
		|| (player->x > player->portals[tmp].x
			&& player->portals[tmp].dir == EAST)
		|| (player->x < player->portals[tmp].x
			&& player->portals[tmp].dir == WEST));
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
			if (tmp == BLUE)
			{
				player->angle = get_angle_tp(player->angle,
						player->portals[tmp].dir, player->portals[ORANGE].dir);
				add_coo(player, ORANGE);
			}
			if (tmp == ORANGE)
			{
				player->angle = get_angle_tp(player->angle,
						player->portals[tmp].dir, player->portals[BLUE].dir);
				add_coo(player, BLUE);
			}
		}
	}
}
