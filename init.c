#include "so_long.h"

void init_primary_objects(t_game *game)
{
	game->map.all_collected = 0;
	game->map.num_of_columns = 0;
	game->map.num_of_rows = 0;
	game->map.collectible_num = 0;
	game->map.exit.num = 0;
	game->map.player = 0;
	game->map.entire_map = NULL;

	game->player.face = 1;
	game->player.pos_x = 0;//change later
	game->player.pos_y = 0;//change later
	game->player.state = 0;

	// game->foe.state = 0;
	// game->foe.face = 1;
}

void set_collectibles(t_game *game)
{
	int i;
	int j;
	int id;

	id = 0;
	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (j < game->map.num_of_columns)
		{
			if (game->map.entire_map[i][j] == 'C')
			{
				game->map.collectible[id].active = 1;
				game->map.collectible[id].column = j;
				game->map.collectible[id].row = i;
				game->map.collectible[id].state = 0;
				++id;
			}
			if (id == game->map.collectible_num)
				return ;
			++j;
		}
		++i;
	}
}

void set_foe_move_range(t_game *game)
{
	int i;
	int num;

	i = 0;
	while (i < game->map.foe_num)
	{
		num = 1;
		while (game->map.entire_map[game->foe[i].row][game->foe[i].column - num] != '1')
			++num;
		game->foe[i].point_a = game->foe[i].pos_x - (64 * (num - 1));
		num = 1;
		while (game->map.entire_map[game->foe[i].row][game->foe[i].column + num] != '1')
			++num;
		game->foe[i].point_b = game->foe[i].pos_x + (64 * (num - 1));
		++i;
	}
}

void set_foe(t_game *game)
{
	int i;
	int j;
	int id;

	id = 0;
	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (j < game->map.num_of_columns)
		{
			if (game->map.entire_map[i][j] == 'F')
			{
				game->foe[id].row = i;
				game->foe[id].column = j;
				game->foe[id].face = 1;
				game->foe[id].state = 0;
				++id;
			}
			if (id == game->map.foe_num)
				return ;
			++j;
		}
		++i;
	}
}

void init_secondary_objects(t_game *game)
{
	game->map.collectible = (t_collectible *)malloc(sizeof(t_collectible) * game->map.collectible_num);
	game->foe = (t_foe *)malloc(sizeof(t_foe) * game->map.foe_num);
	if (!game->map.collectible || !game->foe)
		exit(0);
	set_collectibles(game);
	set_foe(game);
	set_foe_move_range(game);

}