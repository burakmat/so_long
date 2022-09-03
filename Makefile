NAME = so_long
SRCS = main.c set_file_name.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c map_control.c print_functions.c \
	update.c valid_path.c foe_action.c error.c component.c input_control.c \
	init.c collision_check.c utils.c key_press.c set_foe.c player_actions.c \
	general_map_control.c print_all.c print_map_components.c print_foe.c \
	set_player_file_name.c update_player_run.c update_kill_sequence.c \
	update_collect_sequence.c is_direction_num.c tmp_map.c
OBJS = $(SRCS:.c=.o)
LIBX = libmlx.a
FW = -framework OpenGL -framework AppKit
CC = gcc
RM = rm -rf

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBX) $(FW) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all