/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:33:23 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/13 12:45:10 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap/Libft/libft.h"
# include "../push_swap/ft_printf/ft_printf.h"
# include "Get-Next-Line/get_next_line.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define INPUT 0

typedef struct s_struct
{
	int				i;
	int				l;
	char			*ptr;
	long			*values;
	bool			splited;
}					t_struct;

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
void				error(char **av);
char				**ft_split(char const *s, char c);
long				ft_atol(const char *nptr);
int					duplicates(long value, long *values, int k, int l);
int					errors1(long *values, int l);
void				error_msg1(void);
int					errors0(char **argv);
void				lstclear(t_stack **lst);
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
void				stack_init(t_stack **a, long *values, int l);
int					size(char **str);
void				pa(t_stack **b, t_stack **a, bool print);
void				pb(t_stack **a, t_stack **b, bool print);
long				*error_handel(char **argv);
void				stack(t_stack **a, t_stack **b, t_struct var);

#endif