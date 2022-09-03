/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:35:52 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:35:52 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int key_code, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if ((key_code == UP || key_code == W) && !game->key_lock)
		w_key(game);
	else if ((key_code == RIGHT || key_code == D) && !game->key_lock)
		d_key(game);
	else if ((key_code == DOWN || key_code == S) && !game->key_lock)
		s_key(game);
	else if ((key_code == LEFT || key_code == A) && !game->key_lock)
		a_key(game);
	else if (key_code == ESC)
		exit(0);
	return (0);
}

int	terminate(void *param)
{
	exit(0);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	t_game	game;

	set_all_files(&game);
	init_primary_objects(&game);
	if (general_control(&game, ac, av))
		return (1);
	init_secondary_objects(&game);
	game.libx.mlx = mlx_init();
	game.libx.window = mlx_new_window(game.libx.mlx, \
		game.map.num_of_columns * 64, game.map.num_of_rows * 64, "so_long");
	mlx_hook(game.libx.window, 2, 1L << 0, &move, &game);
	mlx_loop_hook(game.libx.mlx, &idle, &game);
	mlx_hook(game.libx.window, 17, (0L), &terminate, &game);
	mlx_loop(game.libx.mlx);
}
