/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:36:33 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:36:34 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_primary_objects(t_game *game)
{
	game->key_lock = 0;
	game->map.all_collected = 0;
	game->map.num_of_columns = 0;
	game->map.num_of_rows = 0;
	game->map.collectible_num = 0;
	game->map.foe_num = 0;
	game->map.exit.num = 0;
	game->map.player = 0;
	game->map.entire_map = NULL;
	game->player.face = 1;
	game->player.step = 0;
	game->player.next_attack = 1;
	game->player.state = 0;
	game->player.run_state = 0;
	game->player.attack_state = 0;
}

void	set_collectibles(t_game *game)
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
			if (game->map.entire_map[i][j] == 'C')
			{
				game->map.collectible[id].active = 1;
				game->map.collectible[id].column = j;
				game->map.collectible[id].row = i;
				game->map.collectible[id].state = 0;
				++id;
			}
			if (id == game->map.collectible_num)
				return ;
			++j;
		}
		++i;
	}
}

void	set_collectible_position(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.collectible_num)
	{
		game->map.collectible[i].pos_x = \
			(game->map.collectible[i].column * 64) + 10;
		game->map.collectible[i].pos_y = \
			(game->map.collectible[i].row * 64) - 5;
		++i;
	}
}

void	set_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (j < game->map.num_of_columns)
		{
			if (game->map.entire_map[i][j] == 'E')
			{
				game->map.exit.row = i;
				game->map.exit.column = j;
			}
			++j;
		}
		++i;
	}
}

void	init_secondary_objects(t_game *game)
{
	game->map.collectible = (t_collectible *)malloc(sizeof(t_collectible) \
		* game->map.collectible_num);
	game->foe = (t_foe *)malloc(sizeof(t_foe) * game->map.foe_num);
	set_collectibles(game);
	set_collectible_position(game);
	set_foe(game);
	set_foes_position(game);
	set_foe_move_range(game);
	set_exit(game);
	game->player.pos_x = (game->player.column * 64) - 93;
	game->player.pos_y = (game->player.row * 64) - 115;
}
