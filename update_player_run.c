/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_run.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:32:10 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:32:11 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_horizontal_one(t_game *game)
{
	if (game->player.face)
		game->player.pos_x += 8;
	else
		game->player.pos_x -= 8;
}

void	update_player_horizontal_two(t_game *game)
{
	++(game->player.run_state);
	if (game->player.run_state == 8)
	{
		game->player.run_state = 0;
		game->player.step += 1;
		if (game->player.face)
			++(game->player.column);
		else
			--(game->player.column);
		mlx_loop_hook(game->libx.mlx, &idle, game);
		game->key_lock = 0;
	}
}

void	update_player_vertical_one(t_game *game)
{
	if (game->player.vertical_way)
		game->player.pos_y -= 8;
	else
		game->player.pos_y += 8;
}

void	reset_run_state(t_game *game)
{
	game->player.run_state = 0;
	game->player.step += 1;
	if (game->player.vertical_way)
		--(game->player.row);
	else
		++(game->player.row);
	mlx_loop_hook(game->libx.mlx, &idle, game);
	game->key_lock = 0;
}

void	update_player_vertical_two(t_game *game)
{
	++(game->player.run_state);
	if (game->player.run_state == 5)
	{
		if (game->player.vertical_way && \
			is_target_active_collectible(game, game->player.row - 1, \
			game->player.column))
		{
			game->player.state = 0;
			mlx_loop_hook(game->libx.mlx, &player_collects, game);
		}	
		else if (!game->player.vertical_way && \
			is_target_active_collectible(game, game->player.row + 1, \
			game->player.column))
		{
			game->player.state = 0;
			mlx_loop_hook(game->libx.mlx, &player_collects, game);
		}	
	}
	if (game->player.run_state == 8)
		reset_run_state(game);
}
