NAME = libftprintf.a
SRCS	=	./ft_printf.c		\
			./ft_print_conv.c	\
			./ft_put.c			\
			./ft_strlen.c		\
			./to_hexa.c			\
			./ft_split.c		\
			./pipex.c			\
			./tool_1.c			\
			./tool_2.c			\

OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all