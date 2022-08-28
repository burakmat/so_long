#include "so_long.h"

int	 idle(void *_game)
{
	static int x;
	int i;
	int j;
	void *img;
	t_game *game = (t_game *) _game;
	if (game->player.face == 1)
		img = mlx_xpm_file_to_image(game->libx.mlx, game->player.right_idle[x++], &i, &j);
	else
		img = mlx_xpm_file_to_image(game->libx.mlx, game->player.left_idle[x++], &i, &j);
	mlx_clear_window(game->libx.mlx, game->libx.window);
	int k = 0;
	while (k++ < FRAME_NUM)
		mlx_put_image_to_window(game->libx.mlx, game->libx.window, img, game->player.pos_x, game->player.pos_y);
	if (x == 8)
		x = 0;
	return (0);
}

int run_horizontal(void *_game)
{
	static int x = 0;
	int i;
	int j;
	int k;
	void *img;
	t_game *game = (t_game *)_game;
	if (game->player.face)
	{
		img = mlx_xpm_file_to_image(game->libx.mlx, game->player.run_right[x++], &i, &j);
		mlx_clear_window(game->libx.mlx, game->libx.window);
		game->player.pos_x += 8;
		k = 0;
		while (k++ < FRAME_NUM)
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, img, game->player.pos_x, game->player.pos_y);
	}
	else
	{
		img = mlx_xpm_file_to_image(game->libx.mlx, game->player.run_left[x++], &i, &j);
		mlx_clear_window(game->libx.mlx, game->libx.window);
		game->player.pos_x -= 8;
		k = 0;
		while (k++ < FRAME_NUM)
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, img, game->player.pos_x, game->player.pos_y);
	}
	if (x == 8)
	{
		x = 0;
		mlx_loop_hook(game->libx.mlx, &idle, game);
	}
	return 0;
}

int run_vertical(void *_game)
{
	static int x = 0;
	int i;
	int j;
	int k;
	void *img;
	t_game *game = (t_game *)_game;
	if (game->player.face)
		img = mlx_xpm_file_to_image(game->libx.mlx, game->player.run_right[x++], &i, &j);
	else
		img = mlx_xpm_file_to_image(game->libx.mlx, game->player.run_left[x++], &i, &j);
	mlx_clear_window(game->libx.mlx, game->libx.window);
	if (game->player.vertical_way)
		game->player.pos_y -= 8;
	else
		game->player.pos_y += 8;
	k = 0;
	while (k++ < FRAME_NUM)
		mlx_put_image_to_window(game->libx.mlx, game->libx.window, img, game->player.pos_x, game->player.pos_y);
	if (x == 8)
	{
		x = 0;
		mlx_loop_hook(game->libx.mlx, &idle, game);
	}
	return 0;
}

int move(int key_code, void *param)
{
	t_game *game = (t_game *) param;
	if (key_code == UP || key_code == W)
	{
		game->player.vertical_way = 1;
		mlx_loop_hook(game->libx.mlx, &run_vertical, game);
	}
	else if (key_code == RIGHT || key_code == D)
	{
		game->player.face = 1;
		mlx_loop_hook(game->libx.mlx, &run_horizontal, game);
	}
	else if (key_code == DOWN || key_code == S)
	{
		game->player.vertical_way = 0;
		mlx_loop_hook(game->libx.mlx, &run_vertical, game);
	}
	else if (key_code == LEFT || key_code == A)
	{
		game->player.face = 0;
		mlx_loop_hook(game->libx.mlx, &run_horizontal, game);
	}
	else if (key_code == ESC)
		exit(0);
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

	if (ac == 2 && extension_check(av))
	{
	set_idle_name(&game.player);
	set_run_name(&game.player);

	game.player.pos_x = 0;
	game.player.pos_y = 0;
	game.player.face = 1;
	game.libx.mlx = mlx_init();
	game.libx.window = mlx_new_window(game.libx.mlx, 2000, 1080, "so_long");
//

//	

	mlx_key_hook(game.libx.window, &move, &game);
	mlx_loop_hook(game.libx.mlx, &idle, &game);
	mlx_hook(game.libx.window, 17, (0L), &terminate, &game);

	mlx_loop(game.libx.mlx);

	}





//	system("leaks a.out");
}