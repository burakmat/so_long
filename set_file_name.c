#include "so_long.h"

void set_idle_name(t_player *player)
{
	player->right_idle[0] = "wizard/idle_right/wizard_right1.xpm";
	player->right_idle[1] = "wizard/idle_right/wizard_right2.xpm";
	player->right_idle[2] = "wizard/idle_right/wizard_right3.xpm";
	player->right_idle[3] = "wizard/idle_right/wizard_right4.xpm";
	player->right_idle[4] = "wizard/idle_right/wizard_right5.xpm";
	player->right_idle[5] = "wizard/idle_right/wizard_right6.xpm";
	player->right_idle[6] = "wizard/idle_right/wizard_right7.xpm";
	player->right_idle[7] = "wizard/idle_right/wizard_right8.xpm";
	player->left_idle[0] = "wizard/idle_left/wizard_left1.xpm";
	player->left_idle[1] = "wizard/idle_left/wizard_left2.xpm";
	player->left_idle[2] = "wizard/idle_left/wizard_left3.xpm";
	player->left_idle[3] = "wizard/idle_left/wizard_left4.xpm";
	player->left_idle[4] = "wizard/idle_left/wizard_left5.xpm";
	player->left_idle[5] = "wizard/idle_left/wizard_left6.xpm";
	player->left_idle[6] = "wizard/idle_left/wizard_left7.xpm";
	player->left_idle[7] = "wizard/idle_left/wizard_left8.xpm";
}

void set_run_name(t_player *player)
{
	player->run_right[0] = "wizard/run_right/run_right1.xpm";
	player->run_right[1] = "wizard/run_right/run_right2.xpm";
	player->run_right[2] = "wizard/run_right/run_right3.xpm";
	player->run_right[3] = "wizard/run_right/run_right4.xpm";
	player->run_right[4] = "wizard/run_right/run_right5.xpm";
	player->run_right[5] = "wizard/run_right/run_right6.xpm";
	player->run_right[6] = "wizard/run_right/run_right7.xpm";
	player->run_right[7] = "wizard/run_right/run_right8.xpm";
	player->run_left[0] = "wizard/run_left/run_left1.xpm";
	player->run_left[1] = "wizard/run_left/run_left2.xpm";
	player->run_left[2] = "wizard/run_left/run_left3.xpm";
	player->run_left[3] = "wizard/run_left/run_left4.xpm";
	player->run_left[4] = "wizard/run_left/run_left5.xpm";
	player->run_left[5] = "wizard/run_left/run_left6.xpm";
	player->run_left[6] = "wizard/run_left/run_left7.xpm";
	player->run_left[7] = "wizard/run_left/run_left8.xpm";
}

void set_attack_one_files(t_player *player)
{
	player->attack_one_left[0] = "wizard/attack1_left/attack_left1.xpm";
	player->attack_one_left[1] = "wizard/attack1_left/attack_left2.xpm";
	player->attack_one_left[2] = "wizard/attack1_left/attack_left3.xpm";
	player->attack_one_left[3] = "wizard/attack1_left/attack_left4.xpm";
	player->attack_one_left[4] = "wizard/attack1_left/attack_left5.xpm";
	player->attack_one_left[5] = "wizard/attack1_left/attack_left6.xpm";
	player->attack_one_left[6] = "wizard/attack1_left/attack_left7.xpm";
	player->attack_one_left[7] = "wizard/attack1_left/attack_left8.xpm";
	player->attack_one_right[0] = "wizard/attack1_right/attack_right1.xpm";
	player->attack_one_right[1] = "wizard/attack1_right/attack_right2.xpm";
	player->attack_one_right[2] = "wizard/attack1_right/attack_right3.xpm";
	player->attack_one_right[3] = "wizard/attack1_right/attack_right4.xpm";
	player->attack_one_right[4] = "wizard/attack1_right/attack_right5.xpm";
	player->attack_one_right[5] = "wizard/attack1_right/attack_right6.xpm";
	player->attack_one_right[6] = "wizard/attack1_right/attack_right7.xpm";
	player->attack_one_right[7] = "wizard/attack1_right/attack_right8.xpm";
}

void set_attack_two_files(t_player *player)
{
	player->attack_two_left[0] = "wizard/attack2_left/attack_left1.xpm";
	player->attack_two_left[1] = "wizard/attack2_left/attack_left2.xpm";
	player->attack_two_left[2] = "wizard/attack2_left/attack_left3.xpm";
	player->attack_two_left[3] = "wizard/attack2_left/attack_left4.xpm";
	player->attack_two_left[4] = "wizard/attack2_left/attack_left5.xpm";
	player->attack_two_left[5] = "wizard/attack2_left/attack_left6.xpm";
	player->attack_two_left[6] = "wizard/attack2_left/attack_left7.xpm";
	player->attack_two_left[7] = "wizard/attack2_left/attack_left8.xpm";
	player->attack_two_right[0] = "wizard/attack2_right/attack_right1.xpm";
	player->attack_two_right[1] = "wizard/attack2_right/attack_right2.xpm";
	player->attack_two_right[2] = "wizard/attack2_right/attack_right3.xpm";
	player->attack_two_right[3] = "wizard/attack2_right/attack_right4.xpm";
	player->attack_two_right[4] = "wizard/attack2_right/attack_right5.xpm";
	player->attack_two_right[5] = "wizard/attack2_right/attack_right6.xpm";
	player->attack_two_right[6] = "wizard/attack2_right/attack_right7.xpm";
	player->attack_two_right[7] = "wizard/attack2_right/attack_right8.xpm";
}

void set_death_files(t_player *player)
{
	player->death_left[0] = "wizard/death_left/death_left1.xpm";
	player->death_left[1] = "wizard/death_left/death_left2.xpm";
	player->death_left[2] = "wizard/death_left/death_left3.xpm";
	player->death_left[3] = "wizard/death_left/death_left4.xpm";
	player->death_left[4] = "wizard/death_left/death_left5.xpm";
	player->death_left[5] = "wizard/death_left/death_left6.xpm";
	player->death_left[6] = "wizard/death_left/death_left7.xpm";
	player->death_right[0] = "wizard/death_right/death_right1.xpm";
	player->death_right[1] = "wizard/death_right/death_right2.xpm";
	player->death_right[2] = "wizard/death_right/death_right3.xpm";
	player->death_right[3] = "wizard/death_right/death_right4.xpm";
	player->death_right[4] = "wizard/death_right/death_right5.xpm";
	player->death_right[5] = "wizard/death_right/death_right6.xpm";
	player->death_right[6] = "wizard/death_right/death_right7.xpm";
}

void set_map_files_one(t_game *game)
{
	game->map.image.bg = "bg/bg3.xpm";
	game->map.image.fg = "bg/bg.xpm";

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

void set_foe_attack_files(t_game *game)
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
	game->map.image.foe_right_attack[0] = "demon/attack_right/right_attack1.xpm";
	game->map.image.foe_right_attack[1] = "demon/attack_right/right_attack2.xpm";
	game->map.image.foe_right_attack[2] = "demon/attack_right/right_attack3.xpm";
	game->map.image.foe_right_attack[3] = "demon/attack_right/right_attack4.xpm";
	game->map.image.foe_right_attack[4] = "demon/attack_right/right_attack5.xpm";
	game->map.image.foe_right_attack[5] = "demon/attack_right/right_attack6.xpm";
	game->map.image.foe_right_attack[6] = "demon/attack_right/right_attack7.xpm";
	game->map.image.foe_right_attack[7] = "demon/attack_right/right_attack8.xpm";
	game->map.image.foe_right_attack[8] = "demon/attack_right/right_attack9.xpm";
	game->map.image.foe_right_attack[9] = "demon/attack_right/right_attack10.xpm";
	game->map.image.foe_right_attack[10] = "demon/attack_right/right_attack11.xpm";

}

void set_map_files_two(t_game *game)
{
	game->map.image.collectible[0] = "skull/skull1.xpm";
	game->map.image.collectible[1] = "skull/skull2.xpm";
	game->map.image.collectible[2] = "skull/skull3.xpm";
	game->map.image.collectible[3] = "skull/skull4.xpm";
	game->map.image.collectible[4] = "skull/skull5.xpm";
	game->map.image.collectible[5] = "skull/skull6.xpm";
	game->map.image.collectible[6] = "skull/skull7.xpm";
	game->map.image.collectible[7] = "skull/skull8.xpm";
}

void set_all_files(t_game *game)
{
	set_idle_name(&game->player);
	set_run_name(&game->player);
	set_attack_one_files(&game->player);
	set_attack_two_files(&game->player);
	set_death_files(&game->player);
	set_map_files_one(game);
	set_map_files_two(game);
	set_foe_attack_files(game);
}