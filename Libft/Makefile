# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 14:29:42 by ksohail-          #+#    #+#              #
#    Updated: 2024/01/28 10:59:33 by ksohail-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_strjoin.c\
		ft_strdup.c\
		ft_strlen.c\
		ft_itoa.c\
		get_next_line.c\
		get_next_line_utils.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:	%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.SECONDARY : $(OBJS)
.PHONY: all clean fclean re bonus
