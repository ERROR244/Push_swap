NAME	= push_swap

SRCM	=	functions01.c main.c lstadd_back.c lstnew.c lstlast.c lstadd_front.c\
			lstsize.c rotate.c swap.c reverse_rotate.c functions02.c push.c functions03.c\
			set_the_stacks.c move_nodes.c Libft/ft_strdup.c Libft/ft_strjoin.c Libft/ft_strlen.c\
			functions04.c lstclear.c split.c

OBJM	= ${SRCM:.c=.o}

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

LIBFT 	= Libft/libft.a
FT_PRINTF	=	ft_printf/libftprintf.a

all:		${NAME}

${LIBFT}:
	make -C Libft

${FT_PRINTF}:
	make -C ft_printf

${NAME}:	${LIBFT} ${FT_PRINTF} ${OBJM}
	${CC} ${CFLAGS} ${LIBFT} ${FT_PRINTF} ${OBJM} -o ${NAME}
	
clean:
	rm -f ${OBJM}
	make clean -C Libft
	make clean -C ft_printf

fclean:		clean
	rm -f ${NAME}
	make fclean -C Libft
	make fclean -C ft_printf

re:			fclean all

.SECONDARY : ${OBJM}
.PHONY: all clean fclean re
