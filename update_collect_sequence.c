/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_collect_sequence.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:32:46 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:32:48 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	deactivate_collectible(t_game *game, int row, int column)
{
	int	i;

	i = 0;
	while (i < game->map.collectible_num)
	{
		if (game->map.collectible[i].row == row && \
			game->map.collectible[i].column == column)
		{
			game->map.all_collected += 1;
			game->map.collectible[i].active = 0;
			return ;
		}	
		++i;
	}
}

void	update_run_after_collect(t_game *game)
{
	if (game->player.vertical_way == -1)
	{
		if (game->player.face)
			deactivate_collectible(game, game->player.row, \
				game->player.column + 1);
		else
			deactivate_collectible(game, game->player.row, \
				game->player.column - 1);
		mlx_loop_hook(game->libx.mlx, &run_horizontal, game);
	}
	else
	{
		if (game->player.vertical_way)
			deactivate_collectible(game, game->player.row - 1, \
				game->player.column);
		else
			deactivate_collectible(game, game->player.row + 1, \
				game->player.column);
		mlx_loop_hook(game->libx.mlx, &run_vertical, game);
	}
}

void	update_player_collect(t_game *game)
{
	++(game->player.attack_state);
	if (game->player.attack_state == 8)
	{
		game->player.attack_state = 0;
		if (game->player.next_attack == 1)
			game->player.next_attack = 2;
		else
			game->player.next_attack = 1;
		game->player.state = 0;
		update_run_after_collect(game);
	}
}
