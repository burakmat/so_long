#include "so_long.h"

// int	 idle(void *_game)
// {
// 	static int x;
// 	int i;
// 	int j;
// 	void *img;
// 	t_game *game = (t_game *) _game;
// 	if (game->player.face == 1)
// 		img = mlx_xpm_file_to_image(game->libx.mlx, game->player.right_idle[x++], &i, &j);
// 	else
// 		img = mlx_xpm_file_to_image(game->libx.mlx, game->player.left_idle[x++], &i, &j);
// 	mlx_clear_window(game->libx.mlx, game->libx.window);
// 	int k = 0;
// 	while (k++ < FRAME_NUM)
// 		mlx_put_image_to_window(game->libx.mlx, game->libx.window, img, game->player.pos_x, game->player.pos_y);
// 	if (x == 8)
// 		x = 0;
// 	return (0);
// }

// int run_horizontal(void *_game)
// {
// 	static int x = 0;
// 	int i;
// 	int j;
// 	int k;
// 	void *img;
// 	t_game *game = (t_game *)_game;
// 	if (game->player.face)
// 	{
// 		img = mlx_xpm_file_to_image(game->libx.mlx, game->player.run_right[x++], &i, &j);
// 		mlx_clear_window(game->libx.mlx, game->libx.window);
// 		game->player.pos_x += 8;
// 		k = 0;
// 		while (k++ < FRAME_NUM)
// 			mlx_put_image_to_window(game->libx.mlx, game->libx.window, img, game->player.pos_x, game->player.pos_y);
// 	}
// 	else
// 	{
// 		img = mlx_xpm_file_to_image(game->libx.mlx, game->player.run_left[x++], &i, &j);
// 		mlx_clear_window(game->libx.mlx, game->libx.window);
// 		game->player.pos_x -= 8;
// 		k = 0;
// 		while (k++ < FRAME_NUM)
// 			mlx_put_image_to_window(game->libx.mlx, game->libx.window, img, game->player.pos_x, game->player.pos_y);
// 	}
// 	if (x == 8)
// 	{
// 		x = 0;
// 		mlx_loop_hook(game->libx.mlx, &idle, game);
// 	}
// 	return 0;
// }

// int run_vertical(void *_game)
// {
// 	static int x = 0;
// 	int i;
// 	int j;
// 	int k;
// 	void *img;
// 	t_game *game = (t_game *)_game;
// 	if (game->player.face)
// 		img = mlx_xpm_file_to_image(game->libx.mlx, game->player.run_right[x++], &i, &j);
// 	else
// 		img = mlx_xpm_file_to_image(game->libx.mlx, game->player.run_left[x++], &i, &j);
// 	mlx_clear_window(game->libx.mlx, game->libx.window);
// 	if (game->player.vertical_way)
// 		game->player.pos_y -= 8;
// 	else
// 		game->player.pos_y += 8;
// 	k = 0;
// 	while (k++ < FRAME_NUM)
// 		mlx_put_image_to_window(game->libx.mlx, game->libx.window, img, game->player.pos_x, game->player.pos_y);
// 	if (x == 8)
// 	{
// 		x = 0;
// 		mlx_loop_hook(game->libx.mlx, &idle, game);
// 	}
// 	return 0;
// }

int move(int key_code, void *param)
{
	t_game *game = (t_game *) param;
	if ((key_code == UP || key_code == W) && !game->key_lock)
	{
		game->player.vertical_way = 1;
		if (!is_target_wall(game, 'u'))
		{	
			game->key_lock = 1;
			mlx_loop_hook(game->libx.mlx, &run_vertical, game);
		}
	}
	else if ((key_code == RIGHT || key_code == D) && !game->key_lock)
	{
		game->player.vertical_way = -1;
		game->player.face = 1;
		if (!is_target_wall(game, 'r'))
		{
			game->key_lock = 1;
			if (is_target_active_collectible(game, game->player.row, game->player.column + 1))
			{
				mlx_loop_hook(game->libx.mlx, &player_collects, game);
			}
			else
				mlx_loop_hook(game->libx.mlx, &run_horizontal, game);
		}
	}
	else if ((key_code == DOWN || key_code == S) && !game->key_lock)
	{
		game->player.vertical_way = 0;
		if (!is_target_wall(game, 'd'))
		{
			game->key_lock = 1;
			mlx_loop_hook(game->libx.mlx, &run_vertical, game);
		}
	}
	else if ((key_code == LEFT || key_code == A) && !game->key_lock)
	{
		game->player.vertical_way = -1;
		game->player.face = 0;
		if (!is_target_wall(game, 'l'))
		{
			game->key_lock = 1;
			if (is_target_active_collectible(game, game->player.row, game->player.column - 1))
			{
				mlx_loop_hook(game->libx.mlx, &player_collects, game);
			}
			else
				mlx_loop_hook(game->libx.mlx, &run_horizontal, game);
		}
	}
	else if (key_code == ESC)
	{
		exit(0);
	}
	// printf("keycode: %d\n", key_code);
	return (0);
}

int terminate(void *param)
{
	system("leaks a.out");
	exit(0);
}

// void out(t_game *game)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < game->map.num_of_rows)
// 	{
// 		j = 0;
// 		while (j < game->map.num_of_columns)
// 		{
// 			if (game->map.entire_map[i][j] == 'C' || game->map.entire_map[i][j] == 'P')
// 				printf("found row: %d, column: %d\n", i, j);
// 			++j;
// 		}
// 		++i;
// 	}
// 	printf("end\n");
// 	i = 0;
// 	while (i < game->map.collectible_num)
// 	{
// 		printf("row: %d, column: %d\n", game->map.collectible[i].row, game->map.collectible[i].column);
// 		++i;
// 	}
// 	printf("player row: %d, column: %d\n", game->player.row, game->player.column);
	
// }

int	main(int ac, char **av)
{

	void	*wall;
	void	*img;
	int i;
	int j;
	int n = 0;
	t_game game;

	set_all_files(&game);

	init_primary_objects(&game);
	if (general_control(&game, ac, av))
		return (1);
	else
	{
	printf("row: %d, column: %d\n", game.map.num_of_rows, game.map.num_of_columns);
	init_secondary_objects(&game);
	game.libx.mlx = mlx_init();
	game.libx.window = mlx_new_window(game.libx.mlx, game.map.num_of_columns * 64, game.map.num_of_rows * 64, "so_long");
// //
// //	


	// print_bg(&game);
	// int p;

	// p = 0;
	// while (p < 11)
	// {
	// 	mlx_put_image_to_window(game.libx.mlx, game.libx.window, mlx_xpm_file_to_image(game.libx.mlx, game.map.image.foe_right_attack[p], &i, &j), 80 * p, 64 * 3);
	// 	printf("a\n");
	// 	++p;
	// }
	// mlx_put_image_to_window(game.libx.mlx, game.libx.window, mlx_xpm_file_to_image(game.libx.mlx, "demon/idle_right/demon_right1.xpm", &i, &j), 64 * 3, 64 * 3);
	// mlx_put_image_to_window(game.libx.mlx, game.libx.window, mlx_xpm_file_to_image(game.libx.mlx, "demon/attack_right/demon-right-attack.xpm", &i, &j), 64 * 3, 64 * 3 - 45);
	// mlx_put_image_to_window(game.libx.mlx, game.libx.window, mlx_xpm_file_to_image(game.libx.mlx, game.map.exit.exit_image, &i, &j), game.map.exit.column * 64, game.map.exit.row * 64);
	mlx_hook(game.libx.window, 2, 1L<<0, &move, &game);
	mlx_loop_hook(game.libx.mlx, &idle, &game);
	mlx_hook(game.libx.window, 17, (0L), &terminate, &game);

	mlx_loop(game.libx.mlx);

	}




//	system("leaks a.out");
}