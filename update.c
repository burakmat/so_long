#include "so_long.h"

void update_foe(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map.foe_num)
	{
		if (game->foe[i].point_a != game->foe[i].point_b)
		{
			if (game->foe[i].face)
			{
				if (game->foe[i].pos_x >= game->foe[i].point_b)
					game->foe[i].face = 0;
				else
					game->foe[i].pos_x += 4;
			}
			else
			{
				if (game->foe[i].pos_x <= game->foe[i].point_a)
					game->foe[i].face = 1;
				else
					game->foe[i].pos_x -= 4;
			}
		}
		++(game->foe[i].state);
		if (game->foe[i].state == 6)
			game->foe[i].state = 0;
		++i;
	}
}

void update_player(t_game *game)
{
	++(game->player.state);
	if (game->player.state == 8)
		game->player.state = 0;	
}

void update_player_horizontal_one(t_game *game)
{
	if (game->player.face)
		game->player.pos_x += 8;
	else
		game->player.pos_x -= 8;
}

void update_player_horizontal_two(t_game *game)
{
	++(game->player.run_state);
	if (game->player.run_state == 8)
	{
		game->player.run_state = 0;
		if (game->player.face)
			++(game->player.column);
		else
			--(game->player.column);
		mlx_loop_hook(game->libx.mlx, &idle, game);
	}
}

void update_player_vertical_one(t_game *game)
{
	if (game->player.vertical_way)
		game->player.pos_y -= 8;
	else
		game->player.pos_y += 8;
}

void update_player_vertical_two(t_game *game)
{
	++(game->player.run_state);
	if (game->player.run_state == 8)
	{
		game->player.run_state = 0;
		if (game->player.vertical_way)
			--(game->player.row);
		else
			++(game->player.row);
		mlx_loop_hook(game->libx.mlx, &idle, game);
	}
}

void update_collectible(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map.collectible_num)
	{
		++(game->map.collectible[i].state);
		if (game->map.collectible[i].state == 8)
			game->map.collectible[i].state = 0;
		++i;
	}
}