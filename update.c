/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:33:01 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:33:04 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_free_foe(t_game *game, int i)
{
	if (game->foe[i].face)
	{
		if (game->foe[i].pos_x >= game->foe[i].point_b)
			game->foe[i].face = 0;
		else
			game->foe[i].pos_x += 4;
	}
	else
	{
		if (game->foe[i].pos_x <= game->foe[i].point_a)
			game->foe[i].face = 1;
		else
			game->foe[i].pos_x -= 4;
	}
}

void	update_foe(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.foe_num)
	{
		if (!is_left_num(game, game->foe[i].row, game->foe[i].column, '1') \
			|| !is_right_num(game, game->foe[i].row, game->foe[i].column, '1'))
			update_free_foe(game, i);
		++(game->foe[i].state);
		if (game->foe[i].state == 6)
			game->foe[i].state = 0;
		++i;
	}
}

void	update_player(t_game *game)
{
	++(game->player.state);
	if (game->player.state == 8)
		game->player.state = 0;
}

void	update_collectible(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.collectible_num)
	{
		++(game->map.collectible[i].state);
		if (game->map.collectible[i].state == 8)
			game->map.collectible[i].state = 0;
		++i;
	}
}
