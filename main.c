#include "minilibx_opengl/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_player
{
	char **right_idle;
	char **left_idle;
	int pos_x;
	int pos_y;
	int face;
} t_player;

typedef struct s_mlx{
	void *mlx;
	void *window;
} t_mlx;

typedef struct s_game
{
	t_mlx mlx;
	t_player player;
} t_game;


int	 idle(void *_game)
{
	static int x;
	int i;
	int j;
	void *img;
	t_game *game = (t_game *) _game;
	if (game->player.face == 1)
		img = mlx_xpm_file_to_image(game->mlx.mlx, game->player.right_idle[x++], &i, &j);
	else
		img = mlx_xpm_file_to_image(game->mlx.mlx, game->player.left_idle[x++], &i, &j);
	mlx_clear_window(game->mlx.mlx, game->mlx.window);
	int k = 0;
	while (k++ < 3000)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, img, game->player.pos_x, game->player.pos_y);
	if (x == 8)
		x = 0;
	return (0);
}

int move(int key_code, void *param)
{
	t_game *game = (t_game *) param;
	if (key_code == 126)
		game->player.pos_y -= 64;
	else if (key_code == 124)
	{
		game->player.pos_x += 64;
		game->player.face = 1;
	}
	else if (key_code == 125)
		game->player.pos_y += 64;
	else if (key_code == 123)
	{
		game->player.pos_x -= 64;
		game->player.face = 0;
	}
	else if (key_code == 53)
		exit(0);
	// printf("keycode: %d\n", key_code);
	return (0);
}
int terminate(void *param)
{
	exit(0);
}

int	main(void)
{

	void	*wall;
	void	*img;
	int i;
	int j;
	int n = 0;
	t_game game;
	char *ptr[] = {
			"wizard/idle_right/wizard_right1.xpm", 
			"wizard/idle_right/wizard_right2.xpm", 
			"wizard/idle_right/wizard_right3.xpm", 
			"wizard/idle_right/wizard_right4.xpm", 
			"wizard/idle_right/wizard_right5.xpm", 
			"wizard/idle_right/wizard_right6.xpm", 
			"wizard/idle_right/wizard_right7.xpm", 
			"wizard/idle_right/wizard_right8.xpm"
	};
	game.player.right_idle = ptr;
	char *ptr1[] = {
			"wizard/idle_left/wizard_left1.xpm", 
			"wizard/idle_left/wizard_left2.xpm", 
			"wizard/idle_left/wizard_left3.xpm", 
			"wizard/idle_left/wizard_left4.xpm", 
			"wizard/idle_left/wizard_left5.xpm", 
			"wizard/idle_left/wizard_left6.xpm", 
			"wizard/idle_left/wizard_left7.xpm", 
			"wizard/idle_left/wizard_left8.xpm"
		};
	game.player.left_idle = ptr1;

	game.player.pos_x = 0;
	game.player.pos_y = 0;
	game.player.face = 1;
	game.mlx.mlx = mlx_init();
	game.mlx.window = mlx_new_window(game.mlx.mlx, 1920, 1080, "so_long");
	mlx_key_hook(game.mlx.window, move, &game);
	// mlx_hook(game.mlx.window, 2, 1L<<0, terminate, &game);
	mlx_loop_hook(game.mlx.mlx, idle, &game);
	mlx_hook(game.mlx.window, 17, (0L), terminate, &game);
	mlx_loop(game.mlx.mlx);
//	system("leaks a.out");
}