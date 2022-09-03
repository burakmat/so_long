/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:35:30 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:35:32 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	idle(void *_game)
{
	t_game	*game;

	game = (t_game *)_game;
	if (game->map.all_collected == game->map.collectible_num && \
		game->player.column == game->map.exit.column && \
		game->player.row == game->map.exit.row)
		exit(0);
	usleep(60000);
	print_all(game);
	if (is_player_dead(game))
	{
		game->key_lock = 1;
		mlx_loop_hook(game->libx.mlx, &foe_attacks, game);
	}
	update_collectible(game);
	update_foe(game);
	update_player(game);
	return (0);
}

int	run_horizontal(void *_game)
{
	t_game	*game;

	game = (t_game *)_game;
	usleep(60000);
	update_player_horizontal_one(game);
	print_all_run(game);
	update_collectible(game);
	update_foe(game);
	update_player_horizontal_two(game);
	return (0);
}

int	run_vertical(void *_game)
{
	t_game	*game;

	game = (t_game *)_game;
	usleep(60000);
	update_player_vertical_one(game);
	print_all_run(game);
	update_collectible(game);
	update_foe(game);
	update_player_vertical_two(game);
	return (0);
}

int	player_collects(void *_game)
{
	t_game	*game;

	game = (t_game *)_game;
	usleep(60000);
	print_all_collect(game);
	update_collectible(game);
	update_player_collect(game);
	update_foe(game);
	return (0);
}

int	player_dies(void *_game)
{
	t_game	*game;

	game = (t_game *)_game;
	usleep(60000);
	print_all_dying(game);
	update_collectible(game);
	update_killing_foe(game);
	update_player_dying(game);
	return (0);
}
