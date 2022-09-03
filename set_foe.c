/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_foe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:34:11 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:34:19 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_foe(t_game *game)
{
	int	i;
	int	j;
	int	id;

	id = 0;
	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (j < game->map.num_of_columns)
		{
			if (game->map.entire_map[i][j] == 'F')
			{
				game->foe[id].row = i;
				game->foe[id].column = j;
				game->foe[id].face = 0;
				game->foe[id].state = 0;
				game->foe[id].killing = 0;
				++id;
			}
			++j;
		}
		++i;
	}
}

void	set_foes_position(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.foe_num)
	{
		game->foe[i].pos_x = (game->foe[i].column * 64) - 32;
		game->foe[i].pos_y = (game->foe[i].row * 64) - 65;
		++i;
	}
}

void	set_foe_move_range(t_game *game)
{
	int	i;
	int	num;

	i = 0;
	while (i < game->map.foe_num)
	{
		num = 1;
		while (game->map.entire_map[game->foe[i].row] \
		[game->foe[i].column - num] != '1')
			++num;
		game->foe[i].point_a = game->foe[i].pos_x - (64 * (num - 1));
		num = 1;
		while (game->map.entire_map[game->foe[i].row] \
			[game->foe[i].column + num] != '1')
			++num;
		game->foe[i].point_b = game->foe[i].pos_x + (64 * (num - 1)) - 30;
		++i;
	}
}
