#include "../../include/cub3D.h"

int	check_file(char *map_name, t_parse *parse)
{
	if (ft_strlen(map_name) <= 4)
		return (0);
	parse->fd = open(map_name, O_RDONLY);
	if (parse->fd == -1)
		return (0);
	while (ft_strlen(map_name) > 4)
		map_name++;
	if (ft_strcmp(map_name, ".cub"))
		return (0);
	return (1);
}
