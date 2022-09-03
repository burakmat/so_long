/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:30:50 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:30:53 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_all(t_game *game)
{
	int	i;

	print_bg(game);
	print_door(game);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		print_fg(game, i);
		print_collectibles(game, i);
		print_player_idle(game, i);
		print_foe(game, i);
		++i;
	}	
	print_step(game);
}

void	print_all_run(t_game *game)
{
	int	i;

	print_bg(game);
	print_door(game);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		print_fg(game, i);
		print_collectibles(game, i);
		print_player_run(game, i);
		print_foe(game, i);
		++i;
	}
	print_step(game);
}

void	print_all_collect(t_game *game)
{
	int		i;
	int		x;
	int		y;
	void	*img;

	print_bg(game);
	print_door(game);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		print_fg(game, i);
		print_collectibles(game, i);
		print_foe(game, i);
		++i;
	}
	print_step(game);
	print_player_attack(game, x, y, img);
}

void	print_all_killing(t_game *game)
{
	int	i;

	print_bg(game);
	print_door(game);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		print_fg(game, i);
		print_collectibles(game, i);
		print_player_idle(game, i);
		print_foe(game, i);
		++i;
	}
	print_step(game);
}

void	print_all_dying(t_game *game)
{
	int	i;

	print_bg(game);
	print_door(game);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		print_fg(game, i);
		print_collectibles(game, i);
		print_player_dying(game, i);
		print_foe(game, i);
		++i;
	}
	print_step(game);
}
