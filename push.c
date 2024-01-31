/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:18:55 by ksohail-          #+#    #+#             */
/*   Updated: 2024/01/25 14:45:38 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_push;

	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stack **b, t_stack **a)
{
	if (*b)
	{
		push_to(a, b);
		printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a)
	{
		push_to(b, a);
		printf("pb\n");
	}
}
