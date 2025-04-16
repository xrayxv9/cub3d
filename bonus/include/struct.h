#ifndef STRUCT_H
# define STRUCT_H

// includes

# include "mlx.h"

// define

# define TEXTURES_NUMBER 5
# define COLORS 2
# define FIRST_MENU_BUTTON 3
# define SECOND_MENU_BUTTON 2

// enum

typedef enum e_first
{
	PLAY,
	SETTINGS,
	QUIT
}	t_first;

typedef enum e_second
{
	CONTINUE,
	BACK
}	t_second;

typedef enum e_menu
{
	FIRST,
	SECOND,
	THIRD
}	t_menu;

typedef enum e_scene
{
	MENU,
	GAME
}	t_scene;

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

typedef enum e_angle
{
	SPAWN_NORTH = 270,
	SPAWN_EAST = 0,
	SPAWN_SOUTH = 90,
	SPAWN_WEST = 180
}	t_angle;

// structs

typedef struct s_image
{
	mlx_image	texture;
	int			h;
	int			w;
}	t_image;

typedef struct s_scene_struct
{
	mlx_image	background;
	t_image		first_scene[FIRST_MENU_BUTTON];
	t_image		second_scene[SECOND_MENU_BUTTON];
	int			menu;
}	t_sc;

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
	double	save_angle;
	double	speed_x;
	double	speed_y;

	bool	w_move;
	bool	s_move;
	bool	a_move;
	bool	d_move;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		h;
}	t_map;

typedef struct s_data
{
	t_player				player;
	t_image					textures[TEXTURES_NUMBER];
	t_sc					scene;
	t_map					map;
	mlx_context				game;
	mlx_window_create_info	info;
	mlx_window				window;
	mlx_color				color[COLORS];
	mlx_image				image;
	int						is_game;
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
	double	line_start_tmp;
}	t_ray;

#endif
