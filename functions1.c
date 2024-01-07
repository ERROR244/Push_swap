/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:08:02 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/07 11:37:14 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	is_nsorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

void	stack_init(t_stack **a, t_stack *node, long *values, int l)
{
	int i;
	t_stack *curr;

	i = 1;
	*a = lstnew((int)values[0], NULL);
	while (i < l)
	{
		node = lstnew((int)values[i], lstlast(*a));
		lstadd_front(a, node);
		i++;
	}
}

t_stack *bigest_node(t_stack *a)
{
	t_stack *res;
	long big = LONG_MIN;
	while (a)
	{
		if (a->value > big)
		{
			res = a;
			big = a->value;
		}
		a = a->next;
	}
	return (res);
}

void	sort_three(t_stack **a)
{
	t_stack *big;

	big = bigest_node(*a);
	if (*a == big)
		ra(a, false);
	else if ((*a)->next == big)
		rra(a, false);
	if ((*a)->next->value < (*a)->value)
		sa(a, false);
}