# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 11:10:11 by ksohail-          #+#    #+#              #
#    Updated: 2024/01/28 11:00:25 by ksohail-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME	= checker

SRCM	=	 main_bonus.c split_bonus.c Libft/ft_strjoin.c Libft/ft_strdup.c\
			Libft/ft_strlen.c functions01_bonus.c lstclear_bonus.c stack_bonus.c\
			lstlast_bonus.c lstnew_bonus.c Libft/get_next_line.c\
			Libft/get_next_line_utils.c rotate_bonus.c swap_bonus.c\
			reverse_rotate_bonus.c push_bonus.c lstsize_bonus.c functions02_bonus.c\

OBJM	= ${SRCM:.c=.o}

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

LIBFT 	= Libft/libft.a

all:		${NAME}

${LIBFT}:
	@make -C Libft

${NAME}:	${LIBFT} ${OBJM}
	${CC} ${CFLAGS} ${LIBFT} ${OBJM} -o ${NAME}
	
clean:
	@rm -f ${OBJM}
	@make clean -C Libft

fclean:		clean
	@rm -f ${NAME}
	@make fclean -C Libft

re:			fclean all

.SECONDARY : ${OBJM}
.PHONY: all clean fclean re
