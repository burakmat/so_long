#include "so_long.h"

void init_objects(t_game *game)
{
	game->map.all_collected = 0;
	game->map.num_of_columns = 0;
	game->map.num_of_rows = 0;
	game->map.entire_map = NULL;

	game->player.face = 1;
	game->player.pos_x = 0;//change later
	game->player.pos_y = 0;//change later
}