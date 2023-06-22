# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mprofett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 10:58:03 by mprofett          #+#    #+#              #
#    Updated: 2022/07/27 09:12:47 by mprofett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

HEADERS	= includes/

OBJS	= ${SRCS:.c=.o} 

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS}  -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
