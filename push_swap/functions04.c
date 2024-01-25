/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions04.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:10:49 by error01           #+#    #+#             */
/*   Updated: 2024/01/25 14:52:51 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*top_node;

	while (*b)
	{
		last = lstlast(*a);
		top_node = is_it_in(*b, (*a)->index - 1);
		if ((*b)->index == (*a)->index - 1)
			pa(b, a);
		else if ((*b)->index > last->index)
		{
			pa(b, a);
			ra(a);
		}
		else if (top_node)
		{
			set_the_position(*b);
			finish_rotation(b, top_node, 'b');
			pa(b, a);
		}
		else
			rra(a);
	}
}

void	sort_all(t_stack **a, t_stack **b)
{
	t_sort	sort;

	sort.size = 0;
	sort.last_size = 0;
	sort.size_push = 0;
	set_the_position_index(*a);
	while (lstsize(*a) > 3)
	{
		sort.size = lstsize(*a);
		if (sort.size > 200)
			sort.size_push += ((lstsize(*a) - 3) / 5) + 1;
		else
			sort.size_push += ((lstsize(*a) - 3) / 3) + 1;
		sort.last_size = function(a, b, sort.size_push, sort.last_size);
	}
	sort_three(a);
	sort.last = lstlast(*a);
	sort.last->index = -1;
	b_to_a(a, b);
	sort.last = lstlast(*a);
	while (sort.last->index != -1)
	{
		rra(a);
		sort.last = lstlast(*a);
	}
}

void	stack(t_stack **a, t_stack **b, t_struct var)
{
	stack_init(a, var.values, var.l);
	if (!is_nsorted(*a))
	{
		if (var.l == 2)
			sa(a);
		else if (var.l == 3)
			sort_three(a);
		else if (var.l > 3)
			sort_all(a, b);
	}
	lstclear(a);
	lstclear(b);
	free(var.values);
}
