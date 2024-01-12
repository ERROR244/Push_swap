/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: error01 <error01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:49:37 by error01           #+#    #+#             */
/*   Updated: 2024/01/12 12:05:00 by error01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	bool			above_the_midline;
	bool			cheapest;
	int				index_position;
	int				push_price;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
long				ft_atol(const char *nptr);
void				duplicates(long value, long *values, int k, int l);
void				errors1(long *values, int l);
void				error_msg1(void);
void				errors0(char **argv);
void				lstadd_back(t_stack **lst, t_stack *new);
void				lstadd_front(t_stack **lst, t_stack *new);
void				lstclear(t_stack **lst);
t_stack				*lstlast(t_stack *lst);
t_stack				*lstnew(int value, t_stack *stack);
int					lstsize(t_stack *lst);
void				rotate(t_stack **a);
void				rr(t_stack **a, t_stack **b, bool print);
void				ra(t_stack **a, bool print);
void				rb(t_stack **b, bool print);
void				swap(t_stack **a);
void				sa(t_stack **a, bool print);
void				sb(t_stack **b, bool print);
void				ss(t_stack **a, t_stack **b, bool print);
void				reverse_rotate(t_stack **a);
void				rra(t_stack **a, bool print);
void				rrb(t_stack **b, bool print);
void				rrr(t_stack **a, t_stack **b, bool print);
bool				is_nsorted(t_stack *a);
void				stack_init(t_stack **a, t_stack *node, long *values, int l);
t_stack				*bigest_node(t_stack *a);
void				sort_three(t_stack **a);
int					size(char **str);
void				pa(t_stack **b, t_stack **a, bool print);
void				pb(t_stack **a, t_stack **b, bool print);
t_stack				*smallest_node(t_stack *stack);
void				set_the_stacks(t_stack *a, t_stack *b);
void				set_the_position(t_stack *stack);
void				move_nodes(t_stack **a, t_stack **b);
void				finish_rotation(t_stack **stack, t_stack *top_node,
						char stack_name);

#endif