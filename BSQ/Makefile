# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mprofett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 10:58:03 by mprofett          #+#    #+#              #
#    Updated: 2022/07/27 19:15:17 by tbarbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq

SRCS	= srcs/ft_atoi.c srcs/ft_filetostr.c srcs/ft_gridtools.c srcs/main.c \
		  srcs/ft_initgrid.c srcs/ft_putresult.c srcs/ft_split.c \
		  srcs/ft_strutils.c

HEADERS	= includes/

OBJS	= ${SRCS:.c=.o} 

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -I ${HEADERS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
