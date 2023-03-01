NAME = pipex

SRCS	=	./ft_print_conv.c	\
			./ft_printf.c		\
			./ft_put.c			\
			./ft_split.c		\
			./pipe_tool.c		\
			./pipex.c			\
			./to_hexa.c			\
			./tool_1.c			\
			./tool_2.c			\

OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all