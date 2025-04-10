#ifndef STRUCT_H
# define STRUCT_H

// includes

# include "mlx.h"

// enum

typedef enum e_sf
{
	FLOOR,
	SKY
}	t_sf;

typedef enum e_pos
{
	SOUTH,
	EAST,
	WEST,
	NORTH,
	IMAGE
}	t_pos;

typedef struct s_image
{
	mlx_image	texture;
	int			h;
	int			w;
}	t_image;

typedef enum e_angle
{
	SPAWN_NORTH = 270,
	SPAWN_EAST = 0,
	SPAWN_SOUTH = 90,
	SPAWN_WEST = 180
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
	mlx_color				color[2];
	t_image					textures[5];
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
	double	touch_loc;
}	t_ray;

#endif
