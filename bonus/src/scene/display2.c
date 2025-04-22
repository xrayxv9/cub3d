#include "cub3D.h"
#include "mlx.h"

static void	display_wasd_controls(mlx_window window, mlx_context game,
		t_sc *scene)
{
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[W].texture, 770, 330, 2.5, 2.5, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[A].texture, 870, 330, 2.5, 2.5, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[S].texture, 970, 330, 2.5, 2.5, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[D].texture, 1070, 330, 2.5, 2.5, 0);
}

static void	display_zqsd_controls(mlx_window window, mlx_context game,
		t_sc *scene)
{
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[Z].texture, 770, 330, 2.5, 2.5, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[Q].texture, 870, 330, 2.5, 2.5, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[S].texture, 970, 330, 2.5, 2.5, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[D].texture, 1070, 330, 2.5, 2.5, 0);
}

static void	display_arrow_controls(mlx_window window, mlx_context game,
		t_sc *scene)
{
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[LEFT].texture, 770, 330, 2.5, 2.5, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[UP].texture, 870, 330, 2.5, 2.5, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[DOWN].texture, 970, 330, 2.5, 2.5, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[RIGHT].texture, 1070, 330, 2.5, 2.5, 0);
}

void	display_sensi(mlx_context game, mlx_window window,
		t_sc *scene)
{
	mlx_color	color;
	float		sensi;

	color.r = 0;
	color.g = 70;
	color.b = 255;
	color.a = 255;
	mlx_set_font_scale(game, "bonus/textures/font/font.ttf", 90.0);
	mlx_string_put(game, window, 770, 630, color, ft_itoa((int)scene->sensi));
	sensi = scene->sensi - (int)scene->sensi;
	sensi *= 100;
	mlx_string_put(game, window, 870, 630, color, ".");
	if ((int)sensi >= 0 && (int)sensi <= 9)
	{
		mlx_string_put(game, window, 900, 630, color, "0");
		mlx_string_put(game, window, 1005, 630, color, ft_itoa((int)sensi));
	}
	else
		mlx_string_put(game, window, 900, 630, color, ft_itoa((int)sensi));
}

void	display_third_scene_buttons(mlx_window window, mlx_context game,
		t_sc *scene, int controls)
{
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[BACK].texture, 10, 865, 0.7, 0.7, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[CONTROL_LEFT].texture, 590, 300, 0.7, 0.7, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[CONTROL_RIGHT].texture, 1190, 300, 0.7, 0.7, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[CONTROL_LEFT].texture, 590, 500, 0.7, 0.7, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[CONTROL_RIGHT].texture, 1190, 500, 0.7, 0.7, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[CONTROL_LEFT].texture, 350, 475, 1.0, 1.0, 0);
	mlx_put_transformed_image_to_window(game, window,
		scene->scene[CONTROL_RIGHT].texture, 1380, 475, 1.0, 1.0, 0);
	if (controls == WASD)
		display_wasd_controls(window, game, scene);
	if (controls == ZQSD)
		display_zqsd_controls(window, game, scene);
	if (controls == DIRARROW)
		display_arrow_controls(window, game, scene);
	display_sensi(game, window, scene);
}
