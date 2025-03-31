/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:10:29 by mpendilh          #+#    #+#             */
/*   Updated: 2024/11/14 13:22:38 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gnl.h"

char	*ft_gnl_strjoin(char **s1, char *s2)
{
	int		i;
	int		j;
	char	*new_buffer;

	if (!*s1 || !s2)
		return (NULL);
	new_buffer = malloc(ft_strlen(*s1) + ft_strlen(s2) + 1);
	if (!new_buffer)
		return (NULL);
	i = 0;
	j = 0;
	while ((*s1)[i])
	{
		new_buffer[i] = (*s1)[i];
		i++;
	}
	while (s2[j])
	{
		new_buffer[i + j] = s2[j];
		j++;
	}
	ft_gnl_free(s1);
	new_buffer[i + j] = '\0';
	return (new_buffer);
}

int	ft_gnl_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_gnl_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_gnl_strdup(char **str)
{
	char	*str_cpy;
	int		j;
	int		i;

	if (!*str)
		return (NULL);
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	if ((*str)[i] == '\n')
		i++;
	j = 0;
	str_cpy = malloc(ft_strlen(*str) + 1 - i);
	if (!str_cpy)
		return (ft_gnl_free(str));
	while ((*str)[i + j])
	{
		str_cpy[j] = (*str)[i + j];
		j++;
	}
	str_cpy[j] = '\0';
	ft_gnl_free(str);
	return (str_cpy);
}
