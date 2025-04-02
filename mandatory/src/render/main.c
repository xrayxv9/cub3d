#include "../../include/cub3D.h"
#include <MacroLibX/includes/mlx.h>

void	key_hook(int key, t_data *data)
{
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(data->game);
}

void	window_hook(int event, t_data *data)
{
	if (event == 0)
		mlx_loop_end(data->game);
}

t_player	player_init(void)
{
	t_player player;
	
	player.angle = 0.0f;
	player.x = 6.0f;
	player.y = 17.0f;
	return (player);
}

void	init_window(t_data *data)
{
	data->player = player_init();
	data->game = mlx_init();
	load_content(data->textures, data->game);
	data->map = read_map();
	data->info.height = 1080;
	data->info.width = 1920;
	data->info.title = "test";
	data->window = mlx_new_window(data->game, &data->info);
	mlx_on_event(data->game, data->window, MLX_KEYDOWN, (void *)key_hook, data);
	mlx_on_event(data->game, data->window, MLX_WINDOW_EVENT,
		(void *)window_hook, data);
	mlx_add_loop_hook(data->game, (void *)background, data);
	mlx_add_loop_hook(data->game, (void *)raycasting, data);
	mlx_loop(data->game);
}

// funtion to remove

static void	free_all(char **t)
{
	char	**tmp;

	tmp = t;
	while (*t)
		free(*t++);
	free(tmp);
}

t_map read_map( void )
{
	int fd = open("mandatory/textures/map.cub", O_RDONLY);
	t_map map;
	char *line;
	char **tmp;
	int	i = 1;

	map.map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (map.map)
		{
			tmp = malloc((i + 1) * sizeof(char *));
			for (int x = 0; map.map[x]; x++)
			{
				tmp[x] = ft_strdup(map.map[x]);	
			}
			tmp[i - 1] = ft_strdup(line);
			tmp[i] = NULL;
			free_all(map.map);
			map.map = tmp;
		}
		else
		{
			map.map = malloc((i + 1) * sizeof(char *)); 
			map.map[i - 1] = ft_strdup(line);
			map.map[i] = NULL;
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	for (map.x = 0; map.map[map.x]; map.x++)
		;
	for (map.y = 0; map.map[0][map.y]; map.y++)
		;
	return (map);
}

void	load_content(t_image *textures, mlx_context game)
{
	int	x;
	int	y;

	textures[EAST].texture = mlx_new_image_from_file(game, "mandatory/textures/EAST.png", &x, &y);
	textures[WEST].texture = mlx_new_image_from_file(game, "mandatory/textures/WEST.png", &x, &y);
	textures[SOUTH].texture = mlx_new_image_from_file(game, "mandatory/textures/SOUTH.png", &x, &y);
	textures[NORTH].texture = mlx_new_image_from_file(game, "mandatory/textures/NORTH.png", &x, &y);
	textures[FLOOR].texture = mlx_new_image_from_file(game, "mandatory/textures/floor.png", &x, &y);
	textures[SKY].texture = mlx_new_image_from_file(game, "mandatory/textures/celing.png", &x, &y);
}

int	main(void)
{
	t_data	data;

	ft_bzero((char *)&data, sizeof(t_data));
	init_window(&data);
	destroy_all(&data);
	return (0);
}
