#include "minilibx_opengl/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FRAME_NUM 1000

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

typedef struct s_libx{
	void *mlx;
	void *window;
} t_libx;

typedef struct s_game
{
	t_libx libx;
	t_player player;
} t_game;


//------------FUNCTIONS------------//


//set_file_name.c
void set_idle_name(t_player *player);
void set_run_name(t_player *player);