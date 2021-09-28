# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 20:56:57 by ddecourt          #+#    #+#              #
#    Updated: 2021/09/28 20:56:59 by ddecourt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	pipex.c \

OBJS = ${SRCS:.c=.o}

NAME = pipex

HEADER = pipex.h

CC = clang 

CFLAGS = -Wall -Werror -Wextra
RM = rm -f

.c.o:
	${CC} -c ${CFLAGS} -o $@ $< 

$(NAME):    ${OBJS}
	make -C libft
	${CC} ${CFLAGS} ${OBJS} -L./libft -lft -o ${NAME}
	echo "Compilation done"

all:	${NAME}

clean: 
	make clean -C libft
	${RM} ${OBJS}

fclean: clean
	make fclean -C libft	
	s${RM} ${NAME}

re:	 fclean all

.PHONY: all clean fclean re