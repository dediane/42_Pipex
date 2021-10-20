# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 22:02:16 by ddecourt          #+#    #+#              #
#    Updated: 2021/10/20 16:35:58 by ddecourt@st      ###   ########.fr        #
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

CFLAGS = -Wall -Werror -Wextra -g3
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
