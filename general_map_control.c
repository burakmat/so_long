/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_map_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:36:45 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:36:46 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rectangle_and_component_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (game->map.entire_map[i][j] && game->map.entire_map[i][j] != '\n')
		{
			if (!is_valid_component(game->map.entire_map[i][j]))
				return (4);
			++j;
		}
		if (!game->map.num_of_columns)
			game->map.num_of_columns = j;
		else if (j != game->map.num_of_columns)
			return (5);
		++i;
	}
	return (0);
}

int	not_surrounded_by_wall(t_game *game)
{
	if (check_column(game, 0))
		return (1);
	if (check_column(game, game->map.num_of_columns - 1))
		return (1);
	if (check_row(game, 0))
		return (1);
	if (check_row(game, game->map.num_of_rows - 1))
		return (1);
	return (0);
}

int	general_control(t_game *game, int ac, char **av)
{
	int	error;

	if (ac != 2)
		return (error_output(game, 1));
	if (extension_check(av))
		return (error_output(game, 2));
	if (read_map(game, av))
		return (error_output(game, 3));
	error = rectangle_and_component_check(game);
	if (error)
		return (error_output(game, error));
	if (not_surrounded_by_wall(game))
		return (error_output(game, 6));
	error = check_component_number(game);
	if (error)
		return (error_output(game, error));
	if (!is_valid(game))
		return (error_output(game, 10));
	return (0);
}
