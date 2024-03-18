NAME		= libft.a

HEADER 		= libft.h

SRCS		=	ft_isdigit.c	\
				ft_join.c		\
				ft_strdup.c		\
				ft_strlen.c

OBJS	= 		$(SRCS:.c=.o)

LIB		=		ar -rcs
CC		= 		gcc
RM		= 		rm -f
CFLAGS	= 		-Wall -Wextra -Werror

all:			$(NAME)

$(NAME): 		$(OBJS)	$(OBJS_B) Makefile $(HEADER)
				$(LIB) $(NAME) $(OBJS)

# Depend. adicionales = solo se ejecutara la regla si cambia make o header
%.o:			%.c
				$(CC) $(FLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
