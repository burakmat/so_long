#include "so_long.h"

void set_component_numbers(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (j < game->map.num_of_columns)
		{
			if (game->map.entire_map[i][j] == 'E')
				game->map.exit.num += 1;
			else if (game->map.entire_map[i][j] == 'P')
				game->map.player += 1;
			else if (game->map.entire_map[i][j] == 'C')
				game->map.collectible_num += 1;
			else if (game->map.entire_map[i][j] == 'F')
				game->map.foe_num += 1;
			++j;
		}
		++i;
	}
}

int check_component_number(t_game *game)
{
	set_component_numbers(game);
	if (game->map.collectible_num < 1)
		return (7);
	if (game->map.exit.num != 1)
		return (8);
	if (game->map.player != 1)
		return (9);
	return (0);
}