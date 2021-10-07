# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 20:56:57 by ddecourt          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2021/10/07 21:25:40 by ddecourt         ###   ########.fr        #
=======
#    Updated: 2021/10/07 18:38:09 by ddecourt         ###   ########.fr        #
>>>>>>> 7f8e01c8d449a26418ec380a9d6cacd3ba739368
#                                                                              #
# **************************************************************************** #

SRCS =	pipex.c \
		srcs/pipex_utils.c \
		srcs/pipex_utils2.c \
		srcs/ft_split.c \

OBJS = ${SRCS:.c=.o}

NAME = pipex

HEADER = pipex.h

CC = clang

CFLAGS = -Wall -Werror -Wextra
RM = rm -f

.c.o:
	${CC} -c ${CFLAGS} -o $@ $< 

$(NAME):    ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	 fclean all

.PHONY: all clean fclean re
