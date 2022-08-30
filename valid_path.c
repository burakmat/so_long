#include "so_long.h"

int is_top_num(t_game *game, int row, int column, char num)
{
	if (game->map.entire_map[row - 1][column] == num)
		return (1);
	return (0);
}

int is_left_num(t_game *game, int row, int column, char num)
{
	if (game->map.entire_map[row][column - 1] == num)
		return (1);
	return (0);
}

int is_right_num(t_game *game, int row, int column, char num)
{
	if (game->map.entire_map[row][column + 1] == num)
		return (1);
	return (0);
}

int is_bottom_num(t_game *game, int row, int column, char num)
{
	if (game->map.entire_map[row + 1][column] == num)
		return (1);
	return (0);
}

void set_bg_to_two(t_game *game, int row, int column)
{
	if (is_top_num(game, row, column, '0'))
	{
		game->map.entire_map[row - 1][column] = '2';
		set_bg_to_two(game, row - 1, column);
	}
	if (is_left_num(game, row, column, '0'))
	{
		game->map.entire_map[row][column - 1] = '2';
		set_bg_to_two(game, row, column - 1);
	}
	if (is_right_num(game, row, column, '0'))
	{
		game->map.entire_map[row][column + 1] = '2';
		set_bg_to_two(game, row, column + 1);
	}
	if (is_bottom_num(game, row, column, '0'))
	{
		game->map.entire_map[row + 1][column] = '2';
		set_bg_to_two(game, row + 1, column);
	}
}

int is_reachable(t_game *game, int row, int column)
{
	if (is_top_num(game, row, column, '2'))
		return (1);
	if (is_right_num(game, row, column, '2'))
		return (1);
	if (is_left_num(game, row, column, '2'))
		return (1);
	if (is_bottom_num(game, row, column, '2'))
		return (1);
	return (0);
}

int is_all_reachable(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (j < game->map.num_of_columns)
		{
			if (game->map.entire_map[i][j] == 'C' || game->map.entire_map[i][j] == 'E')
			{
				if (!is_reachable(game, i, j))
					return (0);
			}
			++j;
		}
		++i;
	}
	return (1);
}

int is_valid(t_game *game)
{
	int i;
	int j;
	int found;

	found = 0;
	i = 0;
	while (i < game->map.num_of_rows && !found)
	{
		j = 0;
		while (j < game->map.num_of_columns && !found)
		{
			if (game->map.entire_map[i][j] == 'P')
				found = 1;
			++j;
		}
		++i;
	}
	game->player.pos_x = 64 * --j;
	game->player.pos_y = 64 * --i;
	set_bg_to_two(game, i, j);
	if (!is_all_reachable(game))
		return (0);
	return (1);
}