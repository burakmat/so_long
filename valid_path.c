/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:31:10 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:31:11 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_bg_to_two(char **tmp_map, int row, int column)
{
	if (is_top_num_tmp(tmp_map, row, column))
	{
		tmp_map[row - 1][column] = '2';
		set_bg_to_two(tmp_map, row - 1, column);
	}
	if (is_left_num_tmp(tmp_map, row, column))
	{
		tmp_map[row][column - 1] = '2';
		set_bg_to_two(tmp_map, row, column - 1);
	}
	if (is_right_num_tmp(tmp_map, row, column))
	{
		tmp_map[row][column + 1] = '2';
		set_bg_to_two(tmp_map, row, column + 1);
	}
	if (is_bottom_num_tmp(tmp_map, row, column))
	{
		tmp_map[row + 1][column] = '2';
		set_bg_to_two(tmp_map, row + 1, column);
	}
}

void	free_copy_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (i < game->map.num_of_rows + 1)
	{
		free(map[i]);
		++i;
	}
	free(map);
}

int	is_all_reachable(t_game *game, char **tmp_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (j < game->map.num_of_columns)
		{
			if (tmp_map[i][j] == 'C' || \
				tmp_map[i][j] == 'E')
			{
				free_copy_map(game, tmp_map);
				return (0);
			}
			++j;
		}
		++i;
	}
	free_copy_map(game, tmp_map);
	return (1);
}

char	**copy_map(t_game *game)
{
	int		i;
	int		j;
	char	**tmp_map;

	tmp_map = malloc(sizeof(char *) * game->map.num_of_rows + 1);
	i = 0;
	while (i < game->map.num_of_rows)
	{
		tmp_map[i] = malloc(sizeof(char) * game->map.num_of_columns + 1);
		++i;
	}
	i = 0;
	while (i < game->map.num_of_rows)
	{
		j = 0;
		while (j < game->map.num_of_columns)
		{
			tmp_map[i][j] = game->map.entire_map[i][j];
			++j;
		}
		tmp_map[i][j] = '\0';
		++i;
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}

int	is_valid(t_game *game)
{
	int		i;
	int		j;
	int		found;
	char	**tmp_map;

	found = 0;
	i = 0;
	while (i < game->map.num_of_rows && !found)
	{
		j = 0;
		while (j < game->map.num_of_columns && !found)
		{
			if (game->map.entire_map[i][j] == 'P')
				found = 1;
			++j;
		}
		++i;
	}
	game->player.column = --j;
	game->player.row = --i;
	tmp_map = copy_map(game);
	set_bg_to_two(tmp_map, i, j);
	if (!is_all_reachable(game, tmp_map))
		return (0);
	return (1);
}
