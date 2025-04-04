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
} t_image;

typedef struct s_parse
{
	char	*map_to_split;
	int		fd;
}	t_parse;

typedef struct s_player
{
	float	angle;
	float	x;
	float	y;
	
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

typedef struct s_halfs
{
	int	begin;
	int half;
	int	end;
}	t_halfs;

typedef struct s_ray
{
	int		mapX;
	int		mapY;
	int		side;
	int		line_height;
	int		line_start;
	int		line_end;
	double	wall_distance;
	double	dirX;
	double	dirY;
	double	deltaX;
	double	deltaY;
	double	posX;
	double	posY;
	double	sideX;
	double	sideY;
	double	stepX;
	double	stepY;
	double	wallX;
	double	cameraX;
	double	planeX;
	double	planeY;
}	t_ray;

#endif
