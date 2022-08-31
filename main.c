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
	if (key_code == UP || key_code == W)
	{
		game->player.vertical_way = 1;
		if (!is_target_wall(game, 'u'))
			mlx_loop_hook(game->libx.mlx, &run_vertical, game);
	}
	else if (key_code == RIGHT || key_code == D)
	{
		game->player.face = 1;
		if (!is_target_wall(game, 'r'))
			mlx_loop_hook(game->libx.mlx, &run_horizontal, game);
	}
	else if (key_code == DOWN || key_code == S)
	{
		game->player.vertical_way = 0;
		if (!is_target_wall(game, 'd'))
			mlx_loop_hook(game->libx.mlx, &run_vertical, game);
	}
	else if (key_code == LEFT || key_code == A)
	{
		game->player.face = 0;
		if (!is_target_wall(game, 'l'))
			mlx_loop_hook(game->libx.mlx, &run_horizontal, game);
	}
	else if (key_code == ESC)
	{
		system("leaks a.out");
		exit(0);
	}
	// printf("keycode: %d\n", key_code);
	return (0);
}

int terminate(void *param)
{
	exit(0);
}

int	main(int ac, char **av)
{

	void	*wall;
	void	*img;
	int i;
	int j;
	int n = 0;
	t_game game;

	set_idle_name(&game.player);
	set_run_name(&game.player);
	set_map_files_one(&game);
	set_map_files_two(&game);

	init_primary_objects(&game);
	if (general_control(&game, ac, av))
		return (1);
	else
	{

		printf("valid\n");
	printf("row: %d, column: %d\n", game.map.num_of_rows, game.map.num_of_columns);
	init_secondary_objects(&game);
	game.libx.mlx = mlx_init();
	game.libx.window = mlx_new_window(game.libx.mlx, game.map.num_of_columns * 64, game.map.num_of_rows * 64, "so_long");
// //
// //	


	// mlx_put_image_to_window(game.libx.mlx, game.libx.window, mlx_xpm_file_to_image(game.libx.mlx, "wizard/idle_right/wizard_right1.xpm", &i, &j), 64 - 93, 64 - 115);
	// print_bg(&game);
	// mlx_put_image_to_window(game.libx.mlx, game.libx.window, mlx_xpm_file_to_image(game.libx.mlx, "skull/skull1.xpm", &i, &j), 128 + 10, 64 - 5);


	mlx_key_hook(game.libx.window, &move, &game);
	mlx_loop_hook(game.libx.mlx, &idle, &game);
	mlx_hook(game.libx.window, 17, (0L), &terminate, &game);

	mlx_loop(game.libx.mlx);

	}




//	system("leaks a.out");
}