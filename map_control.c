#include "so_long.h"
void print_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (j < game->map.num_of_columns)
		{
			printf("%c ", game->map.entire_map[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
}
/////////////////////////////////////////
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
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == 'F')
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
				return (4);
			++j;
		}
		if (!game->map.num_of_columns)
			game->map.num_of_columns = j;
		else if (j != game->map.num_of_columns)
			return (5);
		++i;
	}
	return (0);
}

int check_column(t_game *game, int column)
{
	int i;

	i = 0;
	while (i < game->map.num_of_rows)
	{
		if (game->map.entire_map[i][column] != '1')
			return (1);
		++i;
	}
	return (0);
}

int check_row(t_game *game, int row)
{
	int i;

	i = 0;
	while (i < game->map.num_of_columns)
	{
		if (game->map.entire_map[row][i] != '1')
			return (1);
		++i;
	}
	return (0);
}

int not_surrounded_by_wall(t_game *game)
{
	if (check_column(game, 0))
		return (1);
	if (check_column(game, game->map.num_of_columns - 1))
		return (1);
	if (check_row(game, 0))
		return (1);
	if (check_row(game, game->map.num_of_rows - 1))
		return (1);
	return (0);
}


int general_control(t_game *game, int ac, char **av)
{
	int error;

	if (ac != 2)
		return (error_output(game, 1));
	if (extension_check(av))
		return (error_output(game, 2));
	if (read_map(game, av))
		return (error_output(game, 3));
	error = rectangle_and_component_check(game);
	if (error)
		return (error_output(game, error));
	// add surrounded by wall check
	if (not_surrounded_by_wall(game))
		return (error_output(game, 6));
	// add component number check
	error = check_component_number(game);
	if (error)
		return (error_output(game, error));
	// add valid path check
	if (!is_valid(game))
		return (error_output(game, 10));
	return (0);
}