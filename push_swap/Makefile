NAME = push_swap

SRCS	=	./ft_atoi.c		\
			./main.c		\
			./max_to_a.c	\
			./pre_sort.c	\
			./push_swap.c	\
			./sort_cpy.c	\
			./tool_push.c	\
			./tool_r.c		\
			./tool_rrev.c	\
			./tool_s.c		\

OBJS = $(SRCS:%.c=%.o)
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