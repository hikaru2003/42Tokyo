NAME = minishell

SRCS	=	built_in_cmd.c		\
			free.c				\
			ft_split.c			\
			libft1.c			\
			libft2.c			\
			main.c				\
			pipex.c				\

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