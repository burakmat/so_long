// #include "minilibx_opengl/mlx.h"
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
	int pos_x;
	int pos_y;
	int face;
	int vertical_way;
} t_player;

typedef struct s_map
{
	int all_collected;
	int num_of_rows;
	int num_of_columns;
	int collectible;
	int exit;
	int player;
	char **entire_map;
} t_map;

typedef struct s_libx{
	void *mlx;
	void *window;
} t_libx;

typedef struct s_game
{
	t_libx libx;
	t_player player;
	t_map map;
} t_game;


//------------FUNCTIONS------------//


//set_file_name.c
void set_idle_name(t_player *player);
void set_run_name(t_player *player);

//input_control.c
int extension_check(char **av);

//init.c
void init_objects(t_game *game);

//map_control.c
void add_to_map(t_game *game, char *new_line);
int read_map(t_game *game, char **av);
int general_control(t_game *game, int ac, char **av);

//component.c
int check_component_number(t_game *game);

//valid_path.c
int is_valid(t_game *game);

//error.c
int error_output(t_game *game, int err_code);


//------------TEMPORARY------------//

//map_control.c
void print_map(t_game *game);