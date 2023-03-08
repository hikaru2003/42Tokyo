NAME = pipex

SRCS	=	./ft_print_conv.c		\
			./ft_printf.c			\
			./ft_put.c				\
			./ft_split.c			\
			./get_next_line_utils.c	\
			./get_next_line.c		\
			./here_doc.c			\
			./path.c				\
			./pipe_tool.c			\
			./pipex.c				\
			./to_hexa.c				\
			./tool_1.c				\
			./tool_2.c				\

B_SRCS	=	./pipex_bonus.c			\

OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJS += $(B_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

bonus:	$(OBJS) $(B_OBJS)
	make WITH_BONUS=1

re: fclean all