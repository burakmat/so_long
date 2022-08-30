#include "so_long.h"

int error_output(t_game *game, int err_code)
{
	if (!err_code)
		return (0);
	if (err_code > 3)
		free(game->map.entire_map);
	if (err_code == 1)
		write(2, "Error: Number of given argument(s) is invalid\n", 46);
	else if (err_code == 2)
		write(2, "Error: File name does not have '.ber' extension\n", 48);
	else if (err_code == 3)
		write(2, "Error occured while reading the file\n", 37);
	else if (err_code == 4)
		write(2, "Error: Invalid map component(s) in the given file\n", 50);
	else if (err_code == 5)
		write(2, "Error: Given map is not rectangle\n", 34);
	else if (err_code == 6)
		write(2, "Error: The map is not surrounded by the walls\n", 46);
	else if (err_code == 7)
		write(2, "Error: The map does not contain any collectibles\n", 49);
	else if (err_code == 8)
		write(2, "Error: Number of exit(s) is not one\n", 36);
	else if (err_code == 9)
		write(2, "Error: Number of player(s) is not one\n", 38);
	else if (err_code == 10)
		write(2, "Error: There is no valid path in the map\n", 41);
	return (1);
}