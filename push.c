/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:18:55 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/07 11:48:12 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to(t_stack **stack1, t_stack **stack2)
{
	t_stack	*node_to_push;

	node_to_push = *stack1;
	*stack1 = (*stack1)->next;
	if (*stack1)
		(*stack1)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*stack2)
	{
		*stack2 = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *stack2;
		node_to_push->next->prev = node_to_push;
		*stack2 = node_to_push;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	if (*b)
	{
		push_to(b, a);
		if (!print)
			printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	if (*a)
	{
		push_to(a, b);
		if (!print)
			printf("pb\n");
	}
}
