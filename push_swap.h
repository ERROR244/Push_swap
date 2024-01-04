/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: error01 <error01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:49:37 by error01           #+#    #+#             */
/*   Updated: 2024/01/04 13:47:26 by error01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define INT_MAX 2147483647
#define INT_MIN -2147483648

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
    struct s_stack *prev;
}   t_stack;

char    **ft_split(char const *s, char c);
long	ft_atol(const char *nptr);
void duplicates(long value, long *values, int k);
void	errors1(long *values);
void error_msg1(void);
void	errors0(char **argv);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst, void (*del)(void*));
void	ft_lstdelone(t_stack *lst, void (*del)(void *));
void	ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(void *content);
int		ft_lstsize(t_stack *lst);

#endif