#include "minilibx_opengl/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


#define FRAME_NUM 900
#define UP 126
#define RIGHT 124
#define LEFT 123
#define DOWN 125
#define ESC 53
#define W 13
#define A 0
#define S 1
#define D 2

typedef struct s_player
{
	char *right_idle[8];
	char *left_idle[8];
	char *run_right[8];
	char *run_left[8];
	char *attack_one_left[8];
	char *attack_one_right[8];
	char *attack_two_left[8];
	char *attack_two_right[8];
	char *death_left[7];
	char *death_right[7];
	int step;
	int next_attack;
	int pos_x;
	int pos_y;
	int row;
	int column;
	int face;
	int vertical_way;
	int state;
	int run_state;
	int attack_state;
} t_player;

typedef struct s_image
{
	char *foe_left[8];
	char *foe_right[8];
	char *foe_left_attack[11];
	char *foe_right_attack[11];
	char *collectible[8];
	char *bg;
	char *fg;
} t_image;

typedef struct s_foe
{
	int pos_x;
	int pos_y;
	int row;
	int column;
	int face;
	int state;
	int killing;
	int point_a;
	int point_b;
} t_foe;

typedef struct s_collectible
{
	int row;
	int column;
	int pos_x;
	int pos_y;
	int state;
	int active;
} t_collectible;

typedef struct s_exit
{
	int num;
	int x_pos;
	int y_pos;
	int row;
	int column;
	char *exit_image;
} t_exit;

typedef struct s_map
{
	int all_collected;
	int num_of_rows;
	int num_of_columns;
	int player;
	int foe_num;
	int collectible_num;
	char **entire_map;
	t_image image;
	t_collectible *collectible;
	t_exit exit;
} t_map;

typedef struct s_libx{
	void *mlx;
	void *window;
} t_libx;

typedef struct s_game
{
	int key_lock;
	t_libx libx;
	t_player player;
	t_foe *foe;
	t_map map;
} t_game;


//------------FUNCTIONS------------//


//set_file_name.c
void set_all_files(t_game *game);

//input_control.c
int extension_check(char **av);

//init.c
void init_primary_objects(t_game *game);
void init_secondary_objects(t_game *game);

//map_control.c
void add_to_map(t_game *game, char *new_line);
int read_map(t_game *game, char **av);
int general_control(t_game *game, int ac, char **av);

//component.c
int check_component_number(t_game *game);

//valid_path.c
int is_valid(t_game *game);
int is_right_num(t_game *game, int row, int column, char num);
int is_left_num(t_game *game, int row, int column, char num);
int is_top_num(t_game *game, int row, int column, char num);
int is_bottom_num(t_game *game, int row, int column, char num);

//print_functions.c
void print_all(t_game *game);
void print_all_run(t_game *game);
void print_bg(t_game *game);
void print_all_killing(t_game *game);
void print_all_dying(t_game *game);
void print_all_collect(t_game *game);
void print_step(t_game *game, char *str, int t, int r, int g, int b);


//loop_hooks.c
int	 idle(void *_game);
int run_horizontal(void *_game);
int run_vertical(void *_game);
int player_collects(void *_game);
int foe_attacks(void *_game);
int player_dies(void *_game);

//update.c
void update_player(t_game *game);
void update_player_horizontal_one(t_game *game);
void update_player_horizontal_two(t_game *game);
void update_player_vertical_one(t_game *game);
void update_player_vertical_two(t_game *game);
void update_player_collect(t_game *game);
void update_player_dying(t_game *game);
void update_foe(t_game *game);
void update_collectible(t_game *game);
void update_killing_foe(t_game *game);

//collision_check.c
int is_target_wall(t_game *game, char target);
int is_player_dead(t_game *game);
int is_target_active_collectible(t_game *game, int row, int column);

//error.c
int error_output(t_game *game, int err_code);


//------------TEMPORARY------------//

//map_control.c
void print_map(t_game *game);