NAME	= push_swap
bonus	= checker

SRCM	=	functions01.c main.c lstadd_back.c lstnew.c lstlast.c lstadd_front.c\
			lstsize.c rotate.c swap.c reverse_rotate.c functions02.c push.c functions03.c\
			Libft/ft_strdup.c Libft/ft_strjoin.c Libft/ft_strlen.c\
			functions04.c lstclear.c split.c finish_rotation.c Libft/ft_itoa.c\
			ft_printf/ft_printf.c ft_printf/print_ch.c ft_printf/print_i_d.c\
			ft_printf/print_p.c ft_printf/print_str.c ft_printf/print_u.c ft_printf/print_x.c


SRCB	=	checker_bonus/main_bonus.c checker_bonus/split_bonus.c Libft/ft_strjoin.c Libft/ft_strdup.c\
			Libft/ft_strlen.c checker_bonus/functions01_bonus.c checker_bonus/lstclear_bonus.c checker_bonus/stack_bonus.c\
			checker_bonus/lstlast_bonus.c checker_bonus/lstnew_bonus.c Libft/get_next_line.c\
			Libft/get_next_line_utils.c checker_bonus/rotate_bonus.c checker_bonus/swap_bonus.c\
			checker_bonus/reverse_rotate_bonus.c checker_bonus/push_bonus.c checker_bonus/lstsize_bonus.c\
			checker_bonus/lstadd_back_bonus.c checker_bonus/lstadd_front_bonus.c checker_bonus/functions02_bonus.c\

OBJM	= ${SRCM:.c=.o}
OBJB	= ${SRCB:.c=.o}

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

LIBFT 	= Libft/libft.a
FT_PRINTF	=	ft_printf/libftprintf.a

all:		${NAME}

${LIBFT}:
	@make -C Libft

${FT_PRINTF}:
	@make -C ft_printf

${NAME}:	${LIBFT} ${FT_PRINTF} ${OBJM}
	${CC} ${CFLAGS} ${LIBFT} ${FT_PRINTF} ${OBJM} -o ${NAME}

bonus:	${bonus}

${bonus}:	${LIBFT} ${OBJB}
	${CC} ${CFLAGS} ${LIBFT} ${OBJB} -o ${bonus}
	
clean:
	@rm -f ${OBJM}
	@rm -f ${OBJB}
	@make clean -C Libft
	@make clean -C ft_printf

fclean:		clean
	@rm -f ${NAME}
	@rm -f ${bonus}
	@make fclean -C Libft
	@make fclean -C ft_printf

re:			fclean all

.SECONDARY : ${OBJM} ${OBJB}
.PHONY: all clean fclean re
