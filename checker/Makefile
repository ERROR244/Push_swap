# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 11:10:11 by ksohail-          #+#    #+#              #
#    Updated: 2024/01/27 15:15:23 by ksohail-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME	= checker

SRCM	=	 main.c split.c ./Libft/ft_strjoin.c ./Libft/ft_strdup.c\
			./Libft/ft_strlen.c functions01.c lstclear.c stack.c\
			lstlast.c lstnew.c ./Get-Next-Line/get_next_line.c\
			./Get-Next-Line/get_next_line_utils.c rotate.c swap.c\
			reverse_rotate.c push.c lstsize.c functions02.c\
			ft_printf/ft_printf.c ft_printf/print_ch.c ft_printf/print_i_d.c\
			ft_printf/print_p.c ft_printf/print_str.c ft_printf/print_u.c ft_printf/print_x.c

OBJM	= ${SRCM:.c=.o}

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

LIBFT 	= ./Libft/libft.a

all:		${NAME}

${LIBFT}:
	make -C ./Libft

${NAME}:	${LIBFT} ${OBJM}
	${CC} ${CFLAGS} ${LIBFT} ${OBJM} -o ${NAME}
	
clean:
	rm -f ${OBJM}
	make clean -C Libft

fclean:		clean
	rm -f ${NAME}
	make fclean -C Libft

re:			fclean all

.SECONDARY : ${OBJM}
.PHONY: all clean fclean re
