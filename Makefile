NAME	= push_swap

SRCM	=	ft_split.c functions.c main.c lstadd_back.c lstnew.c lstlast.c lstadd_front.c\
			lstsize.c rotate.c swap.c reverse_rotate.c functions1.c push.c function3.c\
			set_the_stacks.c move_nodes.c

OBJM	= ${SRCM:.c=.o}

CCC		=  -fsanitize=address -g
CC		= cc
# CFLAGS	= -Wall -Werror -Wextra


LIBFT 	= Libft/libft.a
FT_PRINTF	=	ft_printf/libftprintf.a

all:		${NAME}

${NAME}:	${OBJM}
	${CC} ${OBJM} -o ${NAME}
	
clean:
	rm -f ${OBJM}

fclean:		clean
	rm -f ${NAME}
	make fclean -C Libft
	make fclean -C ft_printf

re:			fclean all

.SECONDARY : ${OBJM}
.PHONY: all clean fclean re