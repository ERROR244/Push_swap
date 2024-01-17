# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 11:10:11 by ksohail-          #+#    #+#              #
#    Updated: 2024/01/15 14:25:50 by ksohail-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME	= checker

SRCM	=	main.c ../push_swap/split.c ../push_swap/Libft/ft_strjoin.c ../push_swap/Libft/ft_strdup.c\
			../push_swap/Libft/ft_strlen.c ../push_swap/functions01.c ../push_swap/lstclear.c stack.c\
			../push_swap/lstnew.c ../push_swap/lstlast.c Get-Next-Line/get_next_line.c\
			Get-Next-Line/get_next_line_utils.c ../push_swap/rotate.c ../push_swap/swap.c\
			../push_swap/reverse_rotate.c ../push_swap/push.c ../push_swap/lstsize.c ../push_swap/functions02.c

OBJM	= ${SRCM:.c=.o}

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g -O2

LIBFT 	= ../push_swap/Libft/libft.a
FT_PRINTF	=	../push_swap/ft_printf/libftprintf.a

all:		${NAME}

${LIBFT}:
	make -C ../push_swap/Libft

${FT_PRINTF}:
	make -C ../push_swap/ft_printf

${NAME}:	${LIBFT} ${FT_PRINTF} ${OBJM}
	${CC} ${CFLAGS} ${LIBFT} ${FT_PRINTF} ${OBJM} -o ${NAME}
	
clean:
	rm -f ${OBJM}
	make clean -C ../push_swap

fclean:		clean
	rm -f ${NAME}
	make fclean -C ../push_swap

re:			fclean all

.SECONDARY : ${OBJM}
.PHONY: all clean fclean re
