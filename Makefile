# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opacaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 09:11:35 by opacaud           #+#    #+#              #
#    Updated: 2021/07/15 10:32:15 by opacaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		pipex

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

SRC =		files.c main.c path.c split_and_join.c

OBJ =		${SRC:.c=.o}

all:		${NAME}

${NAME}:	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -o ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY :	all clean fclean re

