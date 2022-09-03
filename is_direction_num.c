/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_direction_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:36:11 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:36:12 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_top_num(t_game *game, int row, int column, char num)
{
	if (game->map.entire_map[row - 1][column] == num)
		return (1);
	return (0);
}

int	is_left_num(t_game *game, int row, int column, char num)
{
	if (game->map.entire_map[row][column - 1] == num)
		return (1);
	return (0);
}

int	is_right_num(t_game *game, int row, int column, char num)
{
	if (game->map.entire_map[row][column + 1] == num)
		return (1);
	return (0);
}

int	is_bottom_num(t_game *game, int row, int column, char num)
{
	if (game->map.entire_map[row + 1][column] == num)
		return (1);
	return (0);
}
