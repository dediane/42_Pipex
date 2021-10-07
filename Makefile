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
		srcs/pipex_utils.c \
		srcs/pipex_utils2.c \
		srcs/ft_split.c \

OBJS = ${SRCS:.c=.o}

NAME = pipex

HEADER = pipex.h

CC = clang

CFLAGS = -g -Wall -Werror -Wextra
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

re:	 fclean alls

.PHONY: all clean fclean re