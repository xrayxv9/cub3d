/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:26:41 by cmorel            #+#    #+#             */
/*   Updated: 2025/08/08 01:37:18 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// includes

# include "mlx.h"
# include "struct.h"

// error messages

# define ERROR "\033[31;03mError\n"
# define FILENAME_ERROR "Invalid map, please retry with a valid map\033[00m\n"
# define PERM_ERROR "Please ensure that you have the permissions \
on the textures\033[00m\n"
# define PLAYER_ERROR "The map must contain only 1 player\033[00m\n"
# define FD_ERROR "The path to the file doesn't exist\033[00m\n"
# define MORE_TEXTURES "There is too many textures in the file\033[00m\n"
# define LESS_TEXTURES "There is too few textures in the file\033[00m\n"
# define MAP_CHAR_ERROR "Please ensure that there is only known character like\
: '0' or '1'\033[00m\n"
# define CLOSE_MAP_ERROR "Please ensure that the map is entirely \
close\033[00m\n"
# define NO_MAP_ERROR "Please ensure that there is a map\033[00m\n"
# define MULTI_SPAWN_ERROR "Please ensure that there is at least and \
only one player spawn\033[00m\n"

// typedef for structs

typedef struct s_parse	t_parse;
typedef struct s_data	t_data;
typedef struct s_image	t_image;

// parsing

int			parsing(t_data *data, char *filename);

// handle textures

int			create_textures(t_parse *parse, t_data *data);

// handle errors

void		parsing_error(t_parse *parse, int i);
int			free_tab(char **tab);
int			destroy_textures_free_tab(t_image *textures,
				char **tab, mlx_context game);
int			free_gnl(int fd, char *line);

// utils

int			tab_len(char **tab);
mlx_color	set_colors(char **rgba);
int			check_file(char *map_name, t_parse *parse);
int			map_is_start(char *line);
int			is_map_character(int c);
int			check_textures(char **textures);
int			check_color(char **split_rgba);
int			is_position(int c);

// map

int			create_map(char **map_to_split, int fd);
int			is_second_map_character(int c);
int			check_around(char **map, int i, int j);
int			check_line(char *line);

#endif
