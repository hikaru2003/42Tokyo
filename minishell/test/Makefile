NAME = minishell

SRCS	=	free.c				\
			ft_split.c			\
			ft_strjoin.c		\
			pipex.c				\
			readline.c			\
			tool.c				\

OBJS = $(SRCS:%.c=%.o)

CC = cc
# CFLAGS  = -Wall -Wextra -Werror #-fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lreadline -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all