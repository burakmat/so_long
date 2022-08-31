#include "so_long.h"

// int dying_animation(void *_game);



int	 idle(void *_game)
{
	t_game *game;

	game = (t_game *)_game;
	// if (game->player.row == game->foe.row && (game->player.pos_x < game->foe.pos_x + 50 && game->player.pos_x > game->foe.pos_x - 50))
	// 	mlx_loop_hook(game->libx.mlx, &dying_animation, &game);||||||||||||||||||||||
	// if (game->map.all_collected && game->player.column == game->map.exit.column && game->player.row == game->map.exit.row)
	// 	exit(0);
	usleep(60000);
	print_all(game);//should print all scene in right order
	// printf("x: %d\n", game->foe[1].pos_x);
	if (is_player_dead(game))
		printf("you died\n");//add attack and dying
	update_collectible(game);
	update_foe(game);
	update_player(game);
	
}

int run_horizontal(void *_game)
{
	t_game *game;
	game = (t_game *)_game;

	usleep(60000);
	update_player_horizontal_one(game);
	print_all_run(game);
	update_collectible(game);
	update_foe(game);
	update_player_horizontal_two(game);
}

int run_vertical(void *_game)
{
	t_game *game;
	game = (t_game *)_game;

	usleep(60000);
	update_player_vertical_one(game);
	print_all_run(game);
	update_collectible(game);
	update_foe(game);
	update_player_vertical_two(game);
}