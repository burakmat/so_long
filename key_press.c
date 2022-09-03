/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:35:59 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:36:00 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_key(t_game *game)
{
	game->player.vertical_way = 1;
	if (!is_target_wall(game, 'u'))
	{	
		game->key_lock = 1;
		mlx_loop_hook(game->libx.mlx, &run_vertical, game);
	}
}

void	d_key(t_game *game)
{
	game->player.vertical_way = -1;
	game->player.face = 1;
	if (!is_target_wall(game, 'r'))
	{
		game->key_lock = 1;
		if (is_target_active_collectible(game, game->player.row, \
			game->player.column + 1))
		{
			mlx_loop_hook(game->libx.mlx, &player_collects, game);
		}
		else
			mlx_loop_hook(game->libx.mlx, &run_horizontal, game);
	}
}

void	a_key(t_game *game)
{
	game->player.vertical_way = -1;
	game->player.face = 0;
	if (!is_target_wall(game, 'l'))
	{
		game->key_lock = 1;
		if (is_target_active_collectible(game, game->player.row, \
			game->player.column - 1))
		{
			mlx_loop_hook(game->libx.mlx, &player_collects, game);
		}
		else
			mlx_loop_hook(game->libx.mlx, &run_horizontal, game);
	}
}

void	s_key(t_game *game)
{
	game->player.vertical_way = 0;
	if (!is_target_wall(game, 'd'))
	{
		game->key_lock = 1;
		mlx_loop_hook(game->libx.mlx, &run_vertical, game);
	}
}
