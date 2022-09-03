/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:35:41 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:35:42 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_to_map(t_game *game, char *new_line)
{
	int		i;
	char	**tmp_map;

	tmp_map = malloc(sizeof(char *) * (game->map.num_of_rows + 1));
	i = 0;
	if (game->map.num_of_rows != 1)
	{
		while (game->map.entire_map[i])
		{
			tmp_map[i] = game->map.entire_map[i];
			++i;
		}
	}
	tmp_map[i] = new_line;
	tmp_map[++i] = NULL;
	if (game->map.num_of_rows != 1)
		free(game->map.entire_map);
	game->map.entire_map = tmp_map;
}

int	read_map(t_game *game, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		game->map.num_of_rows += 1;
		add_to_map(game, line);
	}
}

int	is_valid_component(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == 'F')
		return (1);
	return (0);
}

int	check_column(t_game *game, int column)
{
	int	i;

	i = 0;
	while (i < game->map.num_of_rows)
	{
		if (game->map.entire_map[i][column] != '1')
			return (1);
		++i;
	}
	return (0);
}

int	check_row(t_game *game, int row)
{
	int	i;

	i = 0;
	while (i < game->map.num_of_columns)
	{
		if (game->map.entire_map[row][i] != '1')
			return (1);
		++i;
	}
	return (0);
}
