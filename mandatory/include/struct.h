#ifndef STRUCT_H
# define STRUCT_H

// includes

# include "../../MacroLibX/includes/mlx.h"

// enum

typedef enum e_pos
{
	SOUTH,
	EAST,
	WEST,
	NORTH,
	SKY,
	FLOOR
}	t_pos;

typedef enum e_angle
{
	SPAWN_NORTH = 0,
	SPAWN_EAST = 90,
	SPAWN_SOUTH = 180,
	SPAWN_WEST = 270
}	t_angle;

// structs

typedef struct s_player
{
	float	angle;
	float	x;
	float	y;
}	t_player;

typedef struct s_parse
{
	char	*map_to_split;

	int		fd;
}	t_parse;

typedef struct s_data
{
	mlx_context				game;
	mlx_window_create_info	info;
	mlx_window				window;

	void					*textures[6];
	char					**map;

	t_player				player;
}			t_data;

#endif
