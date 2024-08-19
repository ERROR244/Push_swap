/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:49:37 by error01           #+#    #+#             */
/*   Updated: 2024/01/29 20:56:58 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdint.h> 
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_struct
{
	int				i;
	int				l;
	char			*ptr;
	long			*values;
	bool			splited;
	int				rang_push;
}					t_struct;

typedef struct s_stack
{
	int				value;
	bool			above_the_midline;
	int				how_far_from_the_midline;
	bool			cheapest;
	int				index_position;
	int				index;
	int				push_price;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_sort
{
	int				size_push;
	int				last_size;
	t_stack			*last;
	t_stack			*curr;
	int				size;
}					t_sort;

void				set_the_position_index(t_stack *stack);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
long				ft_atol(const char *nptr);
int					duplicates(long value, long *values, int k, int l);
int					errors1(long *values, int l);
void				error_msg1(void);
int					errors0(char **argv);
void				lstadd_back(t_stack **lst, t_stack *new);
void				lstadd_front(t_stack **lst, t_stack *new);
void				lstclear(t_stack **lst);
t_stack				*lstlast(t_stack *lst);
t_stack				*lstnew(int value, t_stack *stack);
int					lstsize(t_stack *lst);
void				rotate(t_stack **a);
void				rr(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				swap(t_stack **a);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **a);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
bool				is_nsorted(t_stack *a);
void				stack_init(t_stack **a, long *values, int l);
t_stack				*bigest_node(t_stack *a);
void				sort_three(t_stack **a);
int					size(char **str);
void				pa(t_stack **b, t_stack **a);
void				pb(t_stack **a, t_stack **b);
void				set_the_position(t_stack *stack);
long				*error_handel(char **argv);
void				sort_all(t_stack **a, t_stack **b);
void				stack(t_stack **a, t_stack **b, t_struct var);
long				*error_handel(char **argv);
t_stack				*return_node(t_stack *stack, int index);
t_stack				*is_it_in(t_stack *b, int index);
int					function(t_stack **a, t_stack **b, int size_push,
						int last_size);
void				finish_rotation(t_stack **stack, t_stack *top_node,
						char stack_name);

#endif