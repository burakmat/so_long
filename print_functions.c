#include "so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void print_step(t_game *game, int t, int r, int g, int b)
{
	char *str;

	








	mlx_string_put(game->libx.mlx, game->libx.window, 600, 150, create_trgb(t, r, g, b), str);


}

void print_bg(t_game *game)
{
	int i;
	int j;
	int n;
	int m;
	void *img;

	img = mlx_xpm_file_to_image(game->libx.mlx, game->map.image.bg, &n, &m);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (j < game->map.num_of_columns)
		{
			if (game->map.entire_map[i][j] != '1' && game->map.entire_map[i][j] != 'E')
				mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
				img, j * 64, i * 64);
			++j;
		}
		++i;
	}
	mlx_destroy_image(game->libx.mlx, img);
}

void print_fg(t_game *game, int row)
{
	int i;
	int x;
	int y;
	void *img;

	img = mlx_xpm_file_to_image(game->libx.mlx, game->map.image.fg, &x, &y);
	i = 0;
	while (i < game->map.num_of_columns)
	{
		if (game->map.entire_map[row][i] == '1')
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, img
			, i * 64, row * 64);
		++i;
	}
	mlx_destroy_image(game->libx.mlx, img);
}

void print_door(t_game *game, int row)//change later
{
	int i;

	i = 0;
	while (i < game->map.num_of_columns)
	{
		if (game->map.entire_map[row][i] == 'E')
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			mlx_xpm_file_to_image(game->libx.mlx, game->map.exit.exit_image, NULL, NULL), 
			game->map.exit.column * 64, game->map.exit.row * 64);
		++i;
	}
}

void print_collectibles(t_game *game, int row)
{
	int i;
	void *img;
	int x;
	int y;

	i = 0;
	img = mlx_xpm_file_to_image(game->libx.mlx, 
			game->map.image.collectible[game->map.collectible[i].state], &x, &y);
	while (i < game->map.collectible_num)
	{
		if (game->map.collectible[i].row == row && game->map.collectible[i].active)
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			img, game->map.collectible[i].pos_x, game->map.collectible[i].pos_y);
		++i;
	}
	mlx_destroy_image(game->libx.mlx, img);
}

void print_player_idle(t_game *game, int row)
{
	int i;
	int j;
	void *img;

	if (game->player.row == row)
	{
		if (game->player.face)
		{
			img = mlx_xpm_file_to_image(game->libx.mlx, 
			game->player.right_idle[game->player.state], &i, &j);
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			img, game->player.pos_x, game->player.pos_y);
		}
		else
		{
			img = mlx_xpm_file_to_image(game->libx.mlx, 
			game->player.left_idle[game->player.state], &i, &j);
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			img, game->player.pos_x, game->player.pos_y);
		}
		mlx_destroy_image(game->libx.mlx, img);
	}
}

void print_player_run(t_game *game, int row)
{
	int i;
	int j;
	void *img;

	if (game->player.row == row)
	{
		if (game->player.face)
		{
			img = mlx_xpm_file_to_image(game->libx.mlx, 
			game->player.run_right[game->player.run_state], &i, &j);
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			img, game->player.pos_x, game->player.pos_y);
		}
		else
		{
			img = mlx_xpm_file_to_image(game->libx.mlx, 
			game->player.run_left[game->player.run_state], &i, &j);
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			img, game->player.pos_x, game->player.pos_y);
		}
		mlx_destroy_image(game->libx.mlx, img);
	}
}

void print_player_attack(t_game *game)
{
	int i;
	int j;
	void *img;

	if (game->player.face)
	{
		if (game->player.next_attack == 1)
			img = mlx_xpm_file_to_image(game->libx.mlx, 
			game->player.attack_one_right[game->player.attack_state], &i, &j);
		else
			img = mlx_xpm_file_to_image(game->libx.mlx, 
			game->player.attack_two_right[game->player.attack_state], &i, &j);
	}
	else
	{
		if (game->player.next_attack == 1)
			img = mlx_xpm_file_to_image(game->libx.mlx, 
			game->player.attack_one_left[game->player.attack_state], &i, &j);
		else
			img = mlx_xpm_file_to_image(game->libx.mlx, 
			game->player.attack_two_left[game->player.attack_state], &i, &j);
	}
	mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			img, game->player.pos_x, game->player.pos_y);
	mlx_destroy_image(game->libx.mlx, img);
}

void print_player_dying(t_game *game, int row)
{
	int i;
	int j;
	void *img;

	if (game->player.row == row)
	{
		if (game->player.face)
		{
			img = mlx_xpm_file_to_image(game->libx.mlx, 
			game->player.death_right[game->player.state], &i, &j);
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			img, game->player.pos_x, game->player.pos_y);
		}
		else
		{
			img = mlx_xpm_file_to_image(game->libx.mlx, 
			game->player.death_left[game->player.state], &i, &j);
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			img, game->player.pos_x, game->player.pos_y);
		}
		mlx_destroy_image(game->libx.mlx, img);
	}
}

void print_foe(t_game *game, int row)
{
	int i;
	int x;
	int y;
	void *img;

	i = 0;

	while (i < game->map.foe_num)
	{
		if (game->foe[i].row == row && !game->foe[i].killing)
		{
			if (game->foe[i].face)
			{
				img = mlx_xpm_file_to_image(game->libx.mlx, 
				game->map.image.foe_right[game->foe[i].state], &x, &y);
				mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
				img, game->foe[i].pos_x, game->foe[i].pos_y);
			}
			else
			{
				img = mlx_xpm_file_to_image(game->libx.mlx, 
				game->map.image.foe_left[game->foe[i].state], &x, &y);
				mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
				img, game->foe[i].pos_x, game->foe[i].pos_y);
			}
			mlx_destroy_image(game->libx.mlx, img);
		}
		else if (game->foe[i].row == row && game->foe[i].killing)
		{
			if (game->player.pos_x > game->foe[i].pos_x)
			{
				img = mlx_xpm_file_to_image(game->libx.mlx, 
				game->map.image.foe_right_attack[game->foe[i].state], &x, &y);
				mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
				img, game->foe[i].pos_x, game->foe[i].pos_y - 45);
			}
			else
			{
				img = mlx_xpm_file_to_image(game->libx.mlx, 
				game->map.image.foe_left_attack[game->foe[i].state], &x, &y);
				mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
				img, game->foe[i].pos_x - 75, game->foe[i].pos_y - 45);
			}
			mlx_destroy_image(game->libx.mlx, img);
		}
		++i;
	}
}

void print_all(t_game *game)
{
	int i;

	print_bg(game);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		// print_door(game, i);
		print_fg(game, i);
		print_collectibles(game, i);
		print_player_idle(game, i);
		print_foe(game, i);
		++i;
	}	
}
void print_all_run(t_game *game)
{
	int i;

	print_bg(game);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		// print_door(game, i);
		print_fg(game, i);
		print_collectibles(game, i);
		print_player_run(game, i);
		print_foe(game, i);
		++i;
	}
}

void print_all_collect(t_game *game)
{
	int i;

	print_bg(game);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		// print_door(game, i);
		print_fg(game, i);
		print_collectibles(game, i);
		print_foe(game, i);
		++i;
	}
	print_player_attack(game);
}

void print_all_killing(t_game *game)
{
	int i;

	print_bg(game);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		// print_door(game, i);
		print_fg(game, i);
		print_collectibles(game, i);
		print_player_idle(game, i);
		print_foe(game, i);
		++i;
	}
}

void print_all_dying(t_game *game)
{
	int i;

	print_bg(game);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		// print_door(game, i);
		print_fg(game, i);
		print_collectibles(game, i);
		print_player_dying(game, i);
		print_foe(game, i);
		++i;
	}
}