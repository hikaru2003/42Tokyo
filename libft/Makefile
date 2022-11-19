NAME = libft.a
SRCS	=	./ft_isalpha.c		\
			./ft_isdigit.c		\
			./ft_isalnum.c		\
			./ft_isascii.c		\
			./ft_isprint.c		\
			./ft_strlen.c		\
			./ft_memset.c		\
			./ft_bzero.c		\
			./ft_calloc.c		\
			./ft_memcpy.c		\
			./ft_memmove.c	 	\
			./ft_strlcat.c 		\
			./ft_toupper.c 		\
			./ft_tolower.c 		\
			./ft_strchr.c 		\
			./ft_strrchr.c 		\
			./ft_strdup.c		\
			./ft_strncmp.c 		\
			./ft_substr.c		\
			./ft_strjoin.c		\
			./ft_memchr.c 		\
			./ft_memcmp.c 		\
			./ft_strnstr.c 		\
			./ft_atoi.c 		\
			./ft_split.c 		\
			./ft_itoa.c			\
			./ft_strmapi.c		\
			./ft_striteri.c		\
			./ft_putchar_fd.c	\
			./ft_putstr_fd.c	\
			./ft_putendl_fd.c	\
			./ft_putnbr_fd.c	\
			./ft_strlcpy.c 		\
			./ft_strtrim.c		\

B_SRC	=	./ft_lstnew.c		\
			./ft_lstadd_front.c	\
			./ft_lstsize.c		\
			./ft_lstlast.c		\
			./ft_lstadd_back.c	\
			./ft_lstdelone.c	\
			./ft_lstclear.c		\
			./ft_lstiter.c		\
			./ft_lstmap.c		\

OBJS = $(notdir $(SRCS:.c=.o))
B_OBJS = $(notdir $(B_SRC:.c=.o))
CC = cc
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJS += $(B_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

bonus: $(OBJS) $(B_OBJS)
	make WITH_BONUS=1

re: fclean all