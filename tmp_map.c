#include "so_long.h"

int	is_top_num_tmp(char **map, int row, int column)
{
	if (map[row - 1][column] == '0' || map[row - 1][column] == 'E' || map[row - 1][column] == 'C')
		return (1);
	return (0);
}

int	is_left_num_tmp(char **map, int row, int column)
{
	if (map[row][column - 1] == '0' || map[row][column - 1] == 'E' || map[row][column - 1] == 'C')
		return (1);
	return (0);
}

int	is_right_num_tmp(char **map, int row, int column)
{
	if (map[row][column + 1] == '0' || map[row][column + 1] == 'E' || map[row][column + 1] == 'C')
		return (1);
	return (0);
}

int	is_bottom_num_tmp(char **map, int row, int column)
{
	if (map[row + 1][column] == '0' || map[row + 1][column] == 'E' || map[row + 1][column] == 'C')
		return (1);
	return (0);
}
