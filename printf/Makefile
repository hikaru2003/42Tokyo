NAME = libftprintf.a
SRCS	=	./ft_printf.c		\
			./ft_print_conv.c	\
			./ft_put.c			\
			./ft_strlen.c		\
			./to_hexa.c			\

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

.PHONY: all clean fclean re