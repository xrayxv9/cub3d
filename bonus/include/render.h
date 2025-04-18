#ifndef RENDER_H
# define RENDER_H

# include "mlx.h"

typedef struct s_data	t_data;
typedef struct s_ray	t_ray;
typedef struct s_player	t_player;

// render

void	render_floor(t_data *data, mlx_color color);
void	render_celling(t_data *data, mlx_color color);
void	render_bg(t_data *data);
void	render_walls(t_data *data, t_ray *ray, float angle);
void	calcul_touch(t_ray *ray, t_player *player, int dir);

// event

void	event(t_data *data);
void	window_hook(int event, t_data *data);
void	handle_mouse(t_data *data, int i);
void	mouse_hook3(int button, t_data *data, int x, int y);
void	key_up_wasd(int key, t_data *data);
void	player_move_arrow(int key, t_data *data);
void	player_move_zqsd(int key, t_data *data);
void	player_move_wasd(int key, t_data *data);
void	handle_player_move(t_player *player);

// utils

void	calculate_speed(t_player *player, double pos_angle,
			double *save_angle);
void	calculate_second_speed(t_player *player, double first_pos_angle,
			double second_pos_angle, double *save_angle);

#endif
