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

typedef struct s_data
{
	mlx_context				game;
	t_player				player;
	mlx_window_create_info	info;
	mlx_window				window;
	t_image					textures[6];
	char					**map;
}			t_data;

typedef struct s_dict
{
	char	key;
	char	c;
	int		i;
	float	f;
	struct s_dict	*next;
}	t_dict;

#endif
