#include "so_long.h"

void init_primary_objects(t_game *game)
{
	game->map.all_collected = 0;
	game->map.num_of_columns = 0;
	game->map.num_of_rows = 0;
	game->map.collectible_num = 0;
	game->map.foe_num = 0;
	game->map.exit.num = 0;
	game->map.player = 0;
	game->map.entire_map = NULL;

	game->player.face = 1;
	game->player.pos_x = 0;//change later
	game->player.pos_y = 0;//change later
	game->player.state = 0;
	game->player.run_state = 0;
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
		printf("move range for demon %d is a: %d, b: %d\n", i + 1, game->foe[i].point_a, game->foe[i].point_b);
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
				game->foe[id].face = 0;
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

void set_foes_position(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map.foe_num)
	{
		game->foe[i].pos_x = (game->foe[i].column * 64) - 32;
		game->foe[i].pos_y = (game->foe[i].row * 64) - 65;
		++i;
	}
}

void set_collectible_position(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map.collectible_num)
	{
		game->map.collectible[i].pos_x = (game->map.collectible[i].column * 64) + 10;
		game->map.collectible[i].pos_y = (game->map.collectible[i].row * 64) - 5;
		++i;
	}
}

void init_secondary_objects(t_game *game)
{
	game->map.collectible = (t_collectible *)malloc(sizeof(t_collectible) * game->map.collectible_num);
	game->foe = (t_foe *)malloc(sizeof(t_foe) * game->map.foe_num);
	// if (!game->map.collectible || !game->foe)
	// 	exit(0);
	set_collectibles(game);
	set_collectible_position(game);
	set_foe(game);
	set_foes_position(game);
	set_foe_move_range(game);
	

	game->player.pos_x = (game->player.column * 64) - 93;
	game->player.pos_y = (game->player.row * 64) - 115;

}