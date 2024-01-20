# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 11:49:39 by ksohail-          #+#    #+#              #
#    Updated: 2024/01/19 17:32:56 by ksohail-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c print_ch.c print_i_d.c print_p.c print_str.c print_u.c print_x.c

OSRC = ${SRC:.c=.o};

all : ${NAME}

${NAME} : ${OSRC}
	ar rcs ${NAME} ${OSRC}

%.o : %.c
	${CC} ${CFLAGS} -c $^ -o $@

clean :
	rm -f ${OSRC}

fclean : clean
	rm -f ${NAME}

re : fclean all

.SECONDARY : ${OSRC}
.PHONY: all clean fclean re bonus
