# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 14:41:19 by anovio-c          #+#    #+#              #
#    Updated: 2024/02/20 19:03:28 by asiercara        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRC = 	push_swap.c ft_check_args.c ft_args_utils.c \
		ft_lst_utils.c ft_size3.c calculate_costs.c \
	 	algorithm.c algorithm_two.c ft_algorithm_utils.c \
	  	ft_swap.c ft_push.c ft_reverse_rotate.c ft_rotate.c 

SRCDIR = src/
OBJDIR = obj/

LIBFT = libft.a
LIBDIR = libft

GET = ../get_next_line

OBJS =	${addprefix $(OBJDIR), $(SRC:.c=.o)}
DEPS = ${addprefix $(OBJDIR), $(SRC:.c=.d)}

AR = ar rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all:		dir $(NAME)

dir:
			make -C $(LIBDIR)
			mkdir -p ${OBJDIR}

$(NAME):	$(OBJS)
			cc $(OBJS) $(LIBDIR)/${LIBFT} -o ${NAME}

obj/%.o:	src/%.c Makefile
			$(CC) $(CFLAGS) -MMD -c $< -o $@ -g

clean:
			make -C libft clean
			$(RM) -r $(OBJDIR)

fclean: 	clean
			$(RM) $(OBJDIR)
			$(RM) $(NAME)

re:			fclean all

-include $(DEPS)

.PHONY: all clean fclean re dir
