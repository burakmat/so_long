#include "so_long.h"

int dying_animation(void *_game);



int	 idle(void *_game)
{
	t_game *game;

	game = (t_game *)_game;
	// if (game->player.row == game->foe.row && (game->player.pos_x < game->foe.pos_x + 50 && game->player.pos_x > game->foe.pos_x - 50))
	// 	mlx_loop_hook(game->libx.mlx, &dying_animation, &game);||||||||||||||||||||||
	if (game->map.all_collected && game->player.column == game->map.exit.column && game->player.row == game->map.exit.row)
		exit(0);
	print_all(game);//should print all scene in right order
	++(game->player.state);

}
