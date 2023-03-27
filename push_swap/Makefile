NAME = push_swap

SRCS	=	./free.c		\
			./ft_atoi.c		\
			./grouping.c	\
			./main.c		\
			./max_to_a.c	\
			./pre_sort.c	\
			./push_swap.c	\
			./sort.c	\
			./tool_push.c	\
			./tool_r.c		\
			./tool_rrev.c	\
			./tool_s.c		\

OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all