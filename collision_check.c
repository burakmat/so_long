/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:37:17 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:37:18 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_player_dead(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.foe_num)
	{
		if (game->foe[i].row == game->player.row && \
			game->player.pos_x <= game->foe[i].pos_x + 60 && \
			game->player.pos_x >= game->foe[i].pos_x - 150)
		{
			game->foe[i].state = 0;
			game->foe[i].killing = 1;
			return (1);
		}
		++i;
	}
	return (0);
}

int	is_target_wall(t_game *game, char target)
{
	if (target == 'u')
		return (is_top_num(game, game->player.row, game->player.column, '1'));
	if (target == 'd')
		return (is_bottom_num(game, game->player.row, \
			game->player.column, '1'));
	if (target == 'l')
		return (is_left_num(game, game->player.row, game->player.column, '1'));
	if (target == 'r')
		return (is_right_num(game, game->player.row, game->player.column, '1'));
	return (0);
}

int	is_target_active_collectible(t_game *game, int row, int column)
{
	int	i;

	i = 0;
	while (i < game->map.collectible_num)
	{
		if (game->map.collectible[i].row == row && \
			game->map.collectible[i].column == column && \
			game->map.collectible[i].active)
		{
			return (1);
		}
		++i;
	}
	return (0);
}
