#ifndef STRUCT_H
# define STRUCT_H

// includes

# include "mlx.h"

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
	float	x;
	float	y;

	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_map
{
	char	**map;

	int		h;
}	t_map;

typedef struct s_parse
{
	char	*map_to_split;

	int		fd;
	int		counter;
	int		is_map;
}	t_parse;

typedef struct s_data
{
	mlx_context				game;
	mlx_window_create_info	info;
	mlx_window				window;
	mlx_image				textures[6];

	t_map					map;

	t_player				player;
}			t_data;

#endif
