/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:27:13 by cmorel            #+#    #+#             */
/*   Updated: 2025/05/30 16:16:18 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_textures(char **textures)
{
	if (!textures)
		return (0);
	if (!ft_strcmp(textures[0], "\n"))
		return (1);
	return (1);
}

int	check_color(char **split_rgba)
{
	int	i;
	int	j;

	i = 0;
	while (split_rgba[i])
	{
		j = 0;
		if (split_rgba[i][j] == '\n')
			return (0);
		if (ft_strlen(split_rgba[i]) > 3)
			if (split_rgba[i][ft_strlen(split_rgba[i]) - 1] != '\n')
				return (0);
		while (split_rgba[i][j])
		{
			if (!ft_isdigit(split_rgba[i][j]) && split_rgba[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_position(int c)
{
	return (c == 'W' || c == 'E' || c == 'S' || c == 'N');
}
