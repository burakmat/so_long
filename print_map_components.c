/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:34:51 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:34:52 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_bg(t_game *game)
{
	int		i;
	int		j;
	int		n;
	int		m;
	void	*img;

	img = mlx_xpm_file_to_image(game->libx.mlx, game->map.image.bg, &n, &m);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (j < game->map.num_of_columns)
		{
			if (game->map.entire_map[i][j] != '1' && \
				game->map.entire_map[i][j] != 'E')
				mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
					img, j * 64, i * 64);
			++j;
		}
		++i;
	}
	mlx_destroy_image(game->libx.mlx, img);
}

void	print_fg(t_game *game, int row)
{
	int		i;
	int		x;
	int		y;
	void	*img;

	img = mlx_xpm_file_to_image(game->libx.mlx, game->map.image.fg, &x, &y);
	i = 0;
	while (i < game->map.num_of_columns)
	{
		if (game->map.entire_map[row][i] == '1')
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
				img, i * 64, row * 64);
		++i;
	}
	mlx_destroy_image(game->libx.mlx, img);
}

void	print_door(t_game *game)
{
	void	*img;
	int		x;
	int		y;

	if (game->map.all_collected == game->map.collectible_num)
		img = mlx_xpm_file_to_image(game->libx.mlx, \
			game->map.exit.exit_open, &x, &y);
	else
		img = mlx_xpm_file_to_image(game->libx.mlx, \
			game->map.exit.exit_close, &x, &y);
	mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
		img, game->map.exit.column * 64, game->map.exit.row * 64);
	mlx_destroy_image(game->libx.mlx, img);
}

void	print_collectibles(t_game *game, int row)
{
	int		i;
	void	*img;
	int		x;
	int		y;

	i = 0;
	img = mlx_xpm_file_to_image(game->libx.mlx, \
		game->map.image.collectible[game->map.collectible[i].state], &x, &y);
	while (i < game->map.collectible_num)
	{
		if (game->map.collectible[i].row == row && \
			game->map.collectible[i].active)
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
				img, game->map.collectible[i].pos_x, \
				game->map.collectible[i].pos_y);
		++i;
	}
	mlx_destroy_image(game->libx.mlx, img);
}
