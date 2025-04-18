#ifndef SCENE_H
# define SCENE_H

// include

# include "mlx.h"

// define

# define BACKGROUND_ERROR "Please ensure that you have the permissions\
 for the background\n"
# define BUTTONS_ERROR "Please ensure that you have the permissions\
 for the buttons\n"

// struct

typedef struct s_data			t_data;
typedef struct s_scene_struct	t_sc;

// scene

void	handle_scene(t_data *data);

// error

void	error_scene(t_data *data, int i);
void	destroy_scene(t_sc *scene, mlx_context game);

// load scene

int		load_background(mlx_context game, t_sc *scene);
int		load_buttons_first_menu(mlx_context game, t_sc *scene);
int		load_buttons_second_menu(mlx_context game, t_sc *scene);
int		load_buttons_third_menu(mlx_context game, t_sc *scene);

// event

void	window_event(t_data *data);
void	mouse_hook(int button, t_data *data);

// display scenes

void	display_first_scene_buttons(mlx_window window, mlx_context game,
			t_sc *scene);
void	display_second_scene_buttons(mlx_window window, mlx_context game,
			t_sc *scene);
void	display_third_scene_buttons(mlx_window window, mlx_context game,
			t_sc *scene, int controls);

#endif
