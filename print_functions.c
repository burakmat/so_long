/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:35:03 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:35:05 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_step(t_game *game)
{
	char	*step1;
	char	*str;
	int i;

	step1 = ft_itoa(game->player.step);
	str = ft_strjoin("Number of steps: ", step1);
	free(step1);
	i = 0;
	while (i++ < FRAME_NUM)
		mlx_string_put(game->libx.mlx, game->libx.window, 20, 20, 0x44384C, str);
	free(str);
}

void	print_player_idle(t_game *game, int row)
{
	int		i;
	int		j;
	void	*img;

	if (game->player.row == row)
	{
		if (game->player.face)
		{
			img = mlx_xpm_file_to_image(game->libx.mlx, \
				game->player.right_idle[game->player.state], &i, &j);
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
				img, game->player.pos_x, game->player.pos_y);
		}
		else
		{
			img = mlx_xpm_file_to_image(game->libx.mlx, \
				game->player.left_idle[game->player.state], &i, &j);
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
				img, game->player.pos_x, game->player.pos_y);
		}
		mlx_destroy_image(game->libx.mlx, img);
	}
}

void	print_player_run(t_game *game, int row)
{
	int		i;
	int		j;
	void	*img;

	if (game->player.row == row)
	{
		if (game->player.face)
		{
			img = mlx_xpm_file_to_image(game->libx.mlx, \
				game->player.run_right[game->player.run_state], &i, &j);
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
				img, game->player.pos_x, game->player.pos_y);
		}
		else
		{
			img = mlx_xpm_file_to_image(game->libx.mlx, \
				game->player.run_left[game->player.run_state], &i, &j);
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
				img, game->player.pos_x, game->player.pos_y);
		}
		mlx_destroy_image(game->libx.mlx, img);
	}
}

void	print_player_attack(t_game *game, int i, int j, void *img)
{
	if (game->player.face)
	{
		if (game->player.next_attack == 1)
			img = mlx_xpm_file_to_image(game->libx.mlx, \
				game->player.attack_one_right[game->player.attack_state], \
				&i, &j);
		else
			img = mlx_xpm_file_to_image(game->libx.mlx, \
				game->player.attack_two_right[game->player.attack_state], \
				&i, &j);
	}
	else
	{
		if (game->player.next_attack == 1)
			img = mlx_xpm_file_to_image(game->libx.mlx, \
			game->player.attack_one_left[game->player.attack_state], &i, &j);
		else
			img = mlx_xpm_file_to_image(game->libx.mlx, \
				game->player.attack_two_left[game->player.attack_state], \
				&i, &j);
	}
	mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
		img, game->player.pos_x, game->player.pos_y);
	mlx_destroy_image(game->libx.mlx, img);
}

void	print_player_dying(t_game *game, int row)
{
	int		i;
	int		j;
	void	*img;

	if (game->player.row == row)
	{
		if (game->player.face)
		{
			img = mlx_xpm_file_to_image(game->libx.mlx, \
				game->player.death_right[game->player.state], \
				&i, &j);
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
				img, game->player.pos_x, game->player.pos_y);
		}
		else
		{
			img = mlx_xpm_file_to_image(game->libx.mlx, \
				game->player.death_left[game->player.state], \
				&i, &j);
			mlx_put_image_to_window(game->libx.mlx, game->libx.window, \
				img, game->player.pos_x, game->player.pos_y);
		}
		mlx_destroy_image(game->libx.mlx, img);
	}
}
