#include "so_long.h"

void update_foe(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map.foe_num)
	{
		if (!is_left_num(game, game->foe[i].row, game->foe[i].column, '1') || !is_right_num(game, game->foe[i].row, game->foe[i].column, '1'))
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
		game->player.step += 1;
		if (game->player.face)
			++(game->player.column);
		else
			--(game->player.column);
		mlx_loop_hook(game->libx.mlx, &idle, game);
		game->key_lock = 0;
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
	if (game->player.run_state == 5)
	{
		if (game->player.vertical_way && is_target_active_collectible(game, game->player.row - 1, game->player.column))
		{
			game->player.state = 0;
			mlx_loop_hook(game->libx.mlx, &player_collects, game);//attack
		}
				
		else if (!game->player.vertical_way && is_target_active_collectible(game, game->player.row + 1, game->player.column))
		{
			game->player.state = 0;
			mlx_loop_hook(game->libx.mlx, &player_collects, game);//attack
		}	
	}
	if (game->player.run_state == 8)
	{
		game->player.run_state = 0;
		game->player.step += 1;
		if (game->player.vertical_way)
			--(game->player.row);
		else
			++(game->player.row);
		mlx_loop_hook(game->libx.mlx, &idle, game);
		game->key_lock = 0;
	}
}

void deactivate_collectible(t_game *game, int row, int column)
{
	int i;

	i = 0;
	while (i < game->map.collectible_num)
	{
		if (game->map.collectible[i].row == row && game->map.collectible[i].column == column)
		{
			game->map.all_collected += 1;
			printf("collected: %d\n", game->map.all_collected);
			game->map.collectible[i].active = 0;
			return ;
		}	
		++i;
	}
}

void update_player_collect(t_game *game)
{
	++(game->player.attack_state);
	if (game->player.attack_state == 8)
	{
		game->player.attack_state = 0;
		if (game->player.next_attack == 1)
			game->player.next_attack = 2;
		else
			game->player.next_attack = 1;
		game->player.state = 0;
		if (game->player.vertical_way == -1)
		{
			if (game->player.face)
				deactivate_collectible(game, game->player.row, game->player.column + 1);
			else
				deactivate_collectible(game, game->player.row, game->player.column - 1);
			mlx_loop_hook(game->libx.mlx, &run_horizontal, game);
		}
		else
		{
			if (game->player.vertical_way)
				deactivate_collectible(game, game->player.row - 1, game->player.column);
			else
				deactivate_collectible(game, game->player.row + 1, game->player.column);
			mlx_loop_hook(game->libx.mlx, &run_vertical, game);
		}
	}
}

void update_player_dying(t_game *game)
{
	if (game->player.state != 6)
		++(game->player.state);

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

void update_killing_foe(t_game *game)
{
	static int n;
	int i;

	i = 0;
	while (i < game->map.foe_num)
	{
		++(game->foe[i].state);
		if (game->foe[i].killing)
		{
			if (game->foe[i].state > 9 && n < 10)
			{
				game->foe[i].state = 7;
				++n;
			}
			else if (game->foe[i].state == 11)
			{

				game->foe[i].killing = 0;
				game->foe[i].state = 0;
				game->player.state = -1;
				mlx_loop_hook(game->libx.mlx, &player_dies, game);
				return ;
			}	
		}
		else if (!game->foe[i].killing && game->foe[i].state == 6)
			game->foe[i].state = 0;
		++i;
	}
}