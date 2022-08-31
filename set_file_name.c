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