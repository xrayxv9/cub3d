#ifndef STRUCT_H
# define STRUCT_H

// includes

# include "../../MacroLibX/includes/mlx.h"
# include <stdio.h>

// structs

typedef enum e_pos
{
	SOUTH,
	EAST,
	WEST,
	NORTH,
	SKY,
	FLOOR
}	t_pos;

typedef struct s_parse
{
}	t_parse;

typedef struct s_data
{
	void	*textures[6];
	char	**map;
}			t_data;

#endif
