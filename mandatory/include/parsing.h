#ifndef PARSING_H
# define PARSING_H

// includes

# include "mlx.h"

// error messages

# define ERROR "Error\n"
# define FILENAME_ERROR "Invalid map, please retry with a valid map\n"
# define PLAYER_ERROR "The map must contain only 1 player\n"
# define FD_ERROR "The path to the file doesn't exist\n"
# define MORE_TEXTURES "There is too many textures in the file\n"
# define LESS_TEXTURES "There is too few textures in the file\n"
# define MAP_CHAR_ERROR "Please ensure that there is only known character like\
: '0' or '1'\n"
# define CLOSE_MAP_ERROR "Please ensure that the map is entirely close\n"
# define NO_MAP_ERROR "Please ensure that there is a map\n"
# define MULTI_SPAWN_ERROR "Please ensure that there is only one player spawn\n"

// typedef for structs

typedef struct s_parse	t_parse;
typedef struct s_data	t_data;

// parsing

int			parsing(t_data *data, char *filename);

// handle textures

int			create_textures(t_parse *parse, mlx_image image[6],
				mlx_context game);

// handle errors

void		parsing_error(t_parse *parse, int i);
int			free_tab(char **tab);
int			destroy_textures_free_tab(mlx_image textures[6],
				char **tab, mlx_context game);
int			free_gnl(int fd, char *line);

// utils

int			tab_len(char **tab);
mlx_color	set_colors(char **rgba);
int			check_file(char *map_name, t_parse *parse);
int			map_is_start(char *line);
int			is_map_character(int c);

// map

int			create_map(char **map_to_split, int fd);
int			is_second_map_character(int c);
int			check_around(char **map, int i, int j);
int			check_line(char *line);

#endif
