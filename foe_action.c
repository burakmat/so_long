/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:36:58 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:36:59 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	foe_attacks(void *_game)
{
	t_game	*game;

	game = (t_game *)_game;
	print_all_killing(game);
	update_collectible(game);
	update_killing_foe(game);
	update_player(game);
	return (0);
}
