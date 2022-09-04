/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 04:34:35 by bmat              #+#    #+#             */
/*   Updated: 2022/09/03 04:34:36 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map_files_one(t_game *game)
{
	game->map.image.fg = "bg/bg_dark.xpm";
	game->map.image.bg = "bg/bg_test.xpm";
	game->map.image.foe_left[0] = "demon/idle_left/demon_left1.xpm";
	game->map.image.foe_left[1] = "demon/idle_left/demon_left2.xpm";
	game->map.image.foe_left[2] = "demon/idle_left/demon_left3.xpm";
	game->map.image.foe_left[3] = "demon/idle_left/demon_left4.xpm";
	game->map.image.foe_left[4] = "demon/idle_left/demon_left5.xpm";
	game->map.image.foe_left[5] = "demon/idle_left/demon_left6.xpm";
	game->map.image.foe_right[0] = "demon/idle_right/demon_right1.xpm";
	game->map.image.foe_right[1] = "demon/idle_right/demon_right2.xpm";
	game->map.image.foe_right[2] = "demon/idle_right/demon_right3.xpm";
	game->map.image.foe_right[3] = "demon/idle_right/demon_right4.xpm";
	game->map.image.foe_right[4] = "demon/idle_right/demon_right5.xpm";
	game->map.image.foe_right[5] = "demon/idle_right/demon_right6.xpm";
}

void	set_foe_left_attack_files(t_game *game)
{
	game->map.image.foe_left_attack[0] = "demon/attack_left/left_attack1.xpm";
	game->map.image.foe_left_attack[1] = "demon/attack_left/left_attack2.xpm";
	game->map.image.foe_left_attack[2] = "demon/attack_left/left_attack3.xpm";
	game->map.image.foe_left_attack[3] = "demon/attack_left/left_attack4.xpm";
	game->map.image.foe_left_attack[4] = "demon/attack_left/left_attack5.xpm";
	game->map.image.foe_left_attack[5] = "demon/attack_left/left_attack6.xpm";
	game->map.image.foe_left_attack[6] = "demon/attack_left/left_attack7.xpm";
	game->map.image.foe_left_attack[7] = "demon/attack_left/left_attack8.xpm";
	game->map.image.foe_left_attack[8] = "demon/attack_left/left_attack9.xpm";
	game->map.image.foe_left_attack[9] = "demon/attack_left/left_attack10.xpm";
	game->map.image.foe_left_attack[10] = "demon/attack_left/left_attack11.xpm";
}

void	set_foe_right_attack_files(t_game *game)
{
	game->map.image.foe_right_attack[0] = \
		"demon/attack_right/right_attack1.xpm";
	game->map.image.foe_right_attack[1] = \
		"demon/attack_right/right_attack2.xpm";
	game->map.image.foe_right_attack[2] = \
		"demon/attack_right/right_attack3.xpm";
	game->map.image.foe_right_attack[3] = \
		"demon/attack_right/right_attack4.xpm";
	game->map.image.foe_right_attack[4] = \
		"demon/attack_right/right_attack5.xpm";
	game->map.image.foe_right_attack[5] = \
		"demon/attack_right/right_attack6.xpm";
	game->map.image.foe_right_attack[6] = \
		"demon/attack_right/right_attack7.xpm";
	game->map.image.foe_right_attack[7] = \
		"demon/attack_right/right_attack8.xpm";
	game->map.image.foe_right_attack[8] = \
		"demon/attack_right/right_attack9.xpm";
	game->map.image.foe_right_attack[9] = \
		"demon/attack_right/right_attack10.xpm";
	game->map.image.foe_right_attack[10] = \
		"demon/attack_right/right_attack11.xpm";
}

void	set_map_files_two(t_game *game)
{
	game->map.image.collectible[0] = "skull/skull1.xpm";
	game->map.image.collectible[1] = "skull/skull2.xpm";
	game->map.image.collectible[2] = "skull/skull3.xpm";
	game->map.image.collectible[3] = "skull/skull4.xpm";
	game->map.image.collectible[4] = "skull/skull5.xpm";
	game->map.image.collectible[5] = "skull/skull6.xpm";
	game->map.image.collectible[6] = "skull/skull7.xpm";
	game->map.image.collectible[7] = "skull/skull8.xpm";
	game->map.exit.exit_close = "bg/exit_closed.xpm";
	game->map.exit.exit_open = "bg/exit_open.xpm";
}

void	set_all_files(t_game *game)
{
	set_idle_name(&game->player);
	set_run_name(&game->player);
	set_attack_one_files(&game->player);
	set_attack_two_files(&game->player);
	set_death_files(&game->player);
	set_map_files_one(game);
	set_map_files_two(game);
	set_foe_left_attack_files(game);
	set_foe_right_attack_files(game);
}
