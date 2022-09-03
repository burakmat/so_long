/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_foe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:35:19 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:35:20 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_killing_foe(t_game *game, void *img, int i)
{
	int	x;
	int	y;

	if (game->player.pos_x > game->foe[i].pos_x)
	{
		img = mlx_xpm_file_to_image(game->libx.mlx, \
			game->map.image.foe_right_attack[game->foe[i].state], \
			&x, &y);
		mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
			img, game->foe[i].pos_x, game->foe[i].pos_y - 45);
	}
	else
	{
		img = mlx_xpm_file_to_image(game->libx.mlx, \
			game->map.image.foe_left_attack[game->foe[i].state], \
			&x, &y);
		mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
			img, game->foe[i].pos_x - 75, game->foe[i].pos_y - 45);
	}
	mlx_destroy_image(game->libx.mlx, img);
}

void	print_idle_foe(t_game *game, void *img, int i)
{
	int	x;
	int	y;

	if (game->foe[i].face)
	{
		img = mlx_xpm_file_to_image(game->libx.mlx, \
			game->map.image.foe_right[game->foe[i].state], \
			&x, &y);
		mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
			img, game->foe[i].pos_x, game->foe[i].pos_y);
	}
	else
	{
		img = mlx_xpm_file_to_image(game->libx.mlx, \
			game->map.image.foe_left[game->foe[i].state], \
			&x, &y);
		mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
			img, game->foe[i].pos_x, game->foe[i].pos_y);
	}
	mlx_destroy_image(game->libx.mlx, img);
}

void	print_foe(t_game *game, int row)
{
	int		i;
	int		x;
	int		y;
	void	*img;

	i = 0;
	while (i < game->map.foe_num)
	{
		if (game->foe[i].row == row && !game->foe[i].killing)
			print_idle_foe(game, img, i);
		else if (game->foe[i].row == row && game->foe[i].killing)
			print_killing_foe(game, img, i);
		++i;
	}
}
