NAME = so_long

SRCS	=	srcs/main.c					\
			srcs/check_file.c			\
			srcs/check_map.c			\
			srcs/error.c				\
			srcs/get_next_line_utils.c	\
			srcs/get_next_line.c		\
			srcs/init.c					\
			srcs/ft_strchr.c			\
			srcs/ft_strlen.c			\
			srcs/destroy.c				\
			srcs/draw.c					\
			srcs/next_frame.c			\
			srcs/ft_strcmp.c			\
			srcs/ft_print_conv.c		\
			srcs/ft_printf.c			\
			srcs/ft_put.c				\
			srcs/to_hexa.c				\
			srcs/free.c					\
			srcs/next_frame_tool.c		\

OBJS = $(SRCS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS) $(M_OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

bonus:	$(OBJS) $(B_OBJS)
	make WITH_BONUS=1

re: fclean all