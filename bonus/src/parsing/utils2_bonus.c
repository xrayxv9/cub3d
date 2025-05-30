/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:56:27 by mpendilh          #+#    #+#             */
/*   Updated: 2025/05/30 16:16:20 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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
