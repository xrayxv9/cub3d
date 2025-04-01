/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:10:25 by mpendilh          #+#    #+#             */
/*   Updated: 2025/04/01 16:12:24 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char **s1, char *s2);
int		ft_gnl_strchr(char *str);
char	*ft_gnl_free(char **str);
char	*ft_gnl_strdup(char **str);

#endif
