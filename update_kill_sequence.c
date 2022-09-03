/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_kill_sequence.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:32:26 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:32:27 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_dying(t_game *game)
{
	if (game->player.state != 6)
		++(game->player.state);
}

void	update_killer(t_game *game, int i, int *n)
{
	if (game->foe[i].state > 9 && *n < 10)
	{
		game->foe[i].state = 7;
		++(*n);
	}
	else if (game->foe[i].state == 11)
	{
		game->foe[i].killing = 0;
		game->foe[i].state = 0;
		game->player.state = -1;
		mlx_loop_hook(game->libx.mlx, &player_dies, game);
	}
}

void	update_killing_foe(t_game *game)
{
	static int	n;
	int			i;

	i = 0;
	while (i < game->map.foe_num)
	{
		++(game->foe[i].state);
		if (game->foe[i].killing)
			update_killer(game, i, &n);
		else if (!game->foe[i].killing && game->foe[i].state == 6)
			game->foe[i].state = 0;
		++i;
	}
}
