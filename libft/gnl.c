/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:10:21 by mpendilh          #+#    #+#             */
/*   Updated: 2024/11/14 13:24:03 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gnl.h"

static char	*read_line(int fd, char *buffer)
{
	char	*tmp_buffer;
	ssize_t	read_res;

	tmp_buffer = malloc(BUFFER_SIZE + 1);
	if (!tmp_buffer)
		return (NULL);
	read_res = 1;
	while (read_res > 0)
	{
		read_res = read(fd, tmp_buffer, BUFFER_SIZE);
		if (read_res == -1)
			break ;
		tmp_buffer[read_res] = '\0';
		buffer = ft_gnl_strjoin(&buffer, tmp_buffer);
		if (ft_gnl_strchr(buffer) == 1)
			break ;
	}
	free(tmp_buffer);
	return (buffer);
}

static char	*get_line(char *buffer)
{
	char	*new_return_line;
	int		i;
	int		is_nwl;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	is_nwl = 0;
	if (buffer[i] == '\n')
		is_nwl = 1;
	new_return_line = malloc(i + 1 + is_nwl);
	if (!new_return_line)
		return (ft_gnl_free(&buffer));
	i = -1;
	while (buffer[++i] != '\n' && buffer[i])
		new_return_line[i] = buffer[i];
	if (is_nwl == 1)
	{
		new_return_line[i] = '\n';
		new_return_line[i + 1] = '\0';
		return (new_return_line);
	}
	new_return_line[i] = '\0';
	return (new_return_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(BUFFER_SIZE + 1);
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = '\0';
	}
	line = NULL;
	if (buffer[fd][0])
		buffer[fd] = ft_gnl_strdup(&buffer[fd]);
	if (!ft_gnl_strchr(buffer[fd]))
		buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd][0])
		return (ft_gnl_free(&buffer[fd]));
	line = get_line(buffer[fd]);
	return (line);
}
