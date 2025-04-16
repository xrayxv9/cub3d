#include "cub3D.h"

void	display_first_scene_buttons(mlx_window window, mlx_context game,
		t_sc *scene)
{
	mlx_put_image_to_window(game, window,
		scene->first_scene[PLAY].texture, 660, 300);
	mlx_put_image_to_window(game, window,
		scene->first_scene[SETTINGS].texture, 660, 525);
	mlx_put_image_to_window(game, window,
		scene->first_scene[QUIT].texture, 660, 750);
}

void	display_second_scene_buttons(mlx_window window, mlx_context game,
		t_sc *scene)
{
	mlx_put_transformed_image_to_window(game, window,
		scene->second_scene[CONTINUE].texture, 510, 300, 1.5, 1.5, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->second_scene[BACK].texture, 10, 865, 0.7, 0.7, 0);
}
