/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: error01 <error01@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:10:49 by error01           #+#    #+#             */
/*   Updated: 2024/01/12 21:11:21 by error01          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*error_handel(char **argv)
{
	long	*values;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (argv[l])
		l++;
	if (errors0(argv) == 0)
		return (NULL);
	values = malloc(sizeof(long *) * (l));
	if (!values)
		return (NULL);
	while (i < l)
	{
		values[i] = ft_atol(argv[i]);
		i++;
	}
	if (errors1(values, l) == 0)
	{
		free(values);
		return (NULL);
	}
	return (values);
}

void	sort_all(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int len_a;

	len_a = lstsize(*a);
	while (len_a-- > 3)
		pb(a, b, false);
	sort_three(a);
	while (*b)
	{
		set_the_stacks(*a, *b);
		move_nodes(a, b);
	}
	set_the_position(*a);
	smallest = smallest_node(*a);
	if (smallest->above_the_midline)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}

void    swap_to(t_stack **a, bool print)
{
	if (*a && (*a)->next)
    {
        (*a)->prev = (*a)->next;
    	*a = (*a)->next;
		(*a)->prev->next = NULL;
    	(*a)->next = (*a)->prev;
    	(*a)->prev = NULL;
    }
	if (!print)
		printf("sa\n");
}

void	stack(t_stack **a, t_stack **b, t_struct var)
{
	stack_init(a, var.values, var.l);
	if (!is_nsorted(*a))
	{
		if (var.l == 2)
			swap_to(a, false);
		else if (var.l == 3)
			sort_three(a);
		else if (var.l > 3)
			sort_all(a, b);
	}
	lstclear(a);
	lstclear(b);
	free(var.values);
}
