#ifndef STRUCT_H
# define STRUCT_H

// includes

# include "../../MacroLibX/includes/mlx.h"

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

typedef struct s_image
{
	void	*texture;
	int		h;
	int		w;
}	t_image;

typedef struct s_parse
{
	char	*map_to_split;
	int		fd;
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
}	t_player;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_data
{
	mlx_context				game;
	t_player				player;
	mlx_window_create_info	info;
	mlx_window				window;
	t_image					textures[6];
	t_map					map;
}			t_data;

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
