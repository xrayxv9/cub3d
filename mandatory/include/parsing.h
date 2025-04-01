#ifndef PARSING_H
# define PARSING_H

// error messages

# define ERROR "Error\n"
# define FILENAME_ERROR "Invalid map, please retry with a valid map\n"
# define PLAYER_ERROR "The map must contain only 1 player\n"

// typedef for structs

typedef struct s_parse	t_parse;
typedef struct s_data	t_data;

// parsing

int		parsing(t_data *data, char *filename);

// handle map

int		check_file(char *map_name, t_parse *parse);

// handle errors

void	parsing_error(t_parse *parse, int i);
void	free_tab(char **tab);
void	destroy_textures(t_data *data);

// utils

int		tab_len(char **tab);

#endif
