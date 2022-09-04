NAME = so_long
SRCS = main.c set_file_name.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c map_control.c print_functions.c \
	update.c valid_path.c foe_action.c error.c component.c input_control.c \
	init.c collision_check.c utils.c key_press.c set_foe.c player_actions.c \
	general_map_control.c print_all.c print_map_components.c print_foe.c \
	set_player_file_name.c update_player_run.c update_kill_sequence.c \
	update_collect_sequence.c is_direction_num.c tmp_map.c
OBJS = $(SRCS:.c=.o)
LIBX = minilibx_opengl/libmlx.a
GNL = get_next_line/gnl.a
FW = -framework OpenGL -framework AppKit
CC = gcc
RM = rm -rf

$(NAME): $(LIBX) $(GNL) $(OBJS)
	$(CC) $(OBJS) $(LIBX) $(FW) -o $(NAME)

$(LIBX):
	make -C minilibx_opengl

$(GNL):
	make -C get_next_line

all: $(NAME)

clean:
	@make clean -C get_next_line
	$(RM) $(OBJS)

fclean: clean
	@make clean -C minilibx_opengl
	@make fclean -C get_next_line
	$(RM) $(NAME)

re: fclean all