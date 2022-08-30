#include "so_long.h"

void print_bg(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (j < game->map.num_of_columns)
		{
			if (game->map.entire_map[i][j] != '1' && game->map.entire_map[i][j] != 'E')
				mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
				mlx_xpm_file_to_image(game->libx.mlx, game->map.bg_image, NULL, NULL), j * 64, i * 64);
			++j;
		}
		++i;
	}
}

void print_fg(t_game *game, int row)
{
	int i;

	i = 0;
	while (i < game->map.num_of_columns)
	{
		if (game->map.entire_map[row][i] == '1')
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			mlx_xpm_file_to_image(game->libx.mlx, game->map.fg_image, NULL, NULL), i * 64, row * 64);
		++i;
	}
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

	i = 0;
	while (i < game->map.collectible_num)
	{
		if (game->map.collectible[i].row == row && game->map.collectible[i].active)
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			mlx_xpm_file_to_image(game->libx.mlx, 
			game->map.collectible[i].collect_image[game->map.collectible[i].state], NULL, NULL), 
			game->map.collectible[i].column * 64, game->map.collectible[i].row * 64);
		++i;
	}
}

void print_player_idle(t_game *game, int row)
{
	if (game->player.row == row)
	{
		if (game->player.face)
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			mlx_xpm_file_to_image(game->libx.mlx, 
			game->player.right_idle[game->player.state], NULL, NULL), 
			game->player.pos_x, game->player.pos_y);
		else
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
			mlx_xpm_file_to_image(game->libx.mlx, 
			game->player.left_idle[game->player.state], NULL, NULL), 
			game->player.pos_x, game->player.pos_y);
	}
}

void print_foe(t_game *game, int row)
{
	int i;

	i = 0;
	while (i < game->map.foe_num)
	{
		if (game->foe[i].row == row)
		{
			if (game->foe[i].face)
			{
				mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
				mlx_xpm_file_to_image(game->libx.mlx, 
				game->foe[i].right_idle[game->foe[i].state], NULL, NULL), 
				game->foe[i].pos_x, game->foe[i].pos_y);
			}
			else
			{
				mlx_put_image_to_window(game->libx.mlx, game->libx.window, 
				mlx_xpm_file_to_image(game->libx.mlx, 
				game->foe[i].left_idle[game->foe[i].state], NULL, NULL), 
				game->foe[i].pos_x, game->foe[i].pos_y);
			}
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
		print_door(game, i);
		print_fg(game, i);
		print_collectibles(game, i);
		print_player_idle(game, i);
		print_foe(game, i);
		++i;
	}	
}