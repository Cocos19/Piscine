# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mprofett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 10:58:03 by mprofett          #+#    #+#              #
#    Updated: 2022/07/27 19:02:31 by mprofett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= do-op

SRCS	= srcs/do-op.c srcs/ft_operator.c srcs/print_numbers.c

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
