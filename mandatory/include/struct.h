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

typedef struct s_image
{
	void	*texture;
	int		h;
	int		w;
}	t_image;

typedef enum e_angle
{
	SPAWN_NORTH = 0,
	SPAWN_EAST = 90,
	SPAWN_SOUTH = 180,
	SPAWN_WEST = 270
}	t_angle;

// structs

typedef struct s_parse
{
	char	*map_to_split;
	int		fd;
	int		counter;
	int		is_map;
}	t_parse;

typedef struct s_player
{
	double	angle;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	double	move_angle;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		h;
}	t_map;

typedef struct s_data
{
	mlx_context				game;
	t_player				player;
	mlx_window_create_info	info;
	mlx_window				window;
	t_image					textures[7];
	mlx_image				image;
	t_map					map;
}			t_data;

typedef struct s_vector
{
	int	i;
	int	j;
}	t_vector;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	int		side;
	int		line_height;
	int		line_start;
	int		line_end;
	double	wall_distance;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	double	step_x;
	double	step_y;
	double	wall_x;
	double	camera_x;
}	t_ray;

#endif
