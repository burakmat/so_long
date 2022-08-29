#include "so_long.h"

void add_to_map(t_game *game, char *new_line)
{
	int i;
	char **tmp_map;

	tmp_map = malloc(sizeof(char *) * (game->map.num_of_rows + 1));
	i = 0;
	if (game->map.num_of_rows != 1)
	{
		while (game->map.entire_map[i])
		{
			tmp_map[i] = game->map.entire_map[i];
			++i;
		}
	}
	tmp_map[i] = new_line;
	tmp_map[++i] = NULL;
	if (game->map.num_of_rows != 1)
		free(game->map.entire_map);
	game->map.entire_map = tmp_map;
}

int read_map(t_game *game, char **av)
{
	int fd;
	char *line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		game->map.num_of_rows += 1;
		add_to_map(game, line);
	}
}

int is_valid_component(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

int rectangle_and_component_check(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (game->map.entire_map[i][j] && game->map.entire_map[i][j] != '\n')
		{
			if (!is_valid_component(game->map.entire_map[i][j]))
			{
				printf("invalid component\n");
				return (1);
			}
			++j;
		}
		if (!game->map.num_of_columns)
			game->map.num_of_columns = j;
		else if (j != game->map.num_of_columns)
		{
			printf("map is not rectangle\n");
			return (1);
		}
		++i;
	}
	return (0);
}

int general_control(t_game *game, char **av)
{
	if (read_map(game, av))
	{
		printf("error while reading\n");
		return (1);
	}
	if (rectangle_and_component_check(game))
	{
		printf("rectangle check fail\n");
		return (1);
	}
	// add surrounded by wall check
	// add valid path check
	// add component number check
	
}