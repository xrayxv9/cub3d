/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleportation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:56:07 by mpendilh          #+#    #+#             */
/*   Updated: 2025/05/26 16:56:07 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	is_good_angle(t_player *player, int tmp)
{
	t_portal	portal;

	portal = player->portals[tmp];
	if (player->y < portal.y && (int)player->x == portal.x
		&& portal.dir == NORTH)
		return (1);
	else if (player->y > portal.y && (int)player->x == portal.x
		&& portal.dir == SOUTH)
		return (1);
	else if (player->x > portal.x && (int)player->y == portal.y
		&& portal.dir == WEST)
		return (1);
	else if (player->x < portal.x && (int)player->y == portal.y
		&& portal.dir == EAST)
		return (1);
	else
		return (0);
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
		if (map->map[(int)(player->y + player->speed_y)][(int)player->x] != '1'
			&& map->map[(int)player->y]
			[(int)(player->x + player->speed_x)] != '1')
		{
			player->x += player->speed_x;
			player->y += player->speed_y;
		}
	}
	if (player->portals[BLUE].exist
		&& player->portals[ORANGE].exist)
	{
		tmp = get_portal(player);
		if (tmp != -1 && is_good_angle(player, tmp))
		{
			player->angle = get_angle_tp(player->angle,
					player->portals[tmp].dir, player->portals[!tmp].dir);
			add_coo(player, !tmp);
		}
	}
}
