NAME = push_swap

SRCS	=	./ft_atoi.c		\
			./main.c		\
			./push_swap.c	\
			./sort.c		\
			./tool_push.c	\
			./tool_r.c		\
			./tool_rrev.c	\
			./tool_s.c		\

# B_SRCS	=	./

OBJS = $(SRCS:%.c=%.o)
# B_OBJS = $(B_SRCS:%.c=%.o)
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