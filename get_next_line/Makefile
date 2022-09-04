NAME = gnl.a
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
AR = ar -rc
FLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -rf

$(NAME): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)